const SerialPort = require('serialport');
const AWS = require('aws-sdk');
AWS.config.update({region: 'eu-west-2'});

const doc = require('dynamodb-doc');
const dynamo = new doc.DynamoDB();

// Add your USB port name
const port = new SerialPort('/dev/xy', {
	parser: SerialPort.parsers.readline('\n')
});

const logIntervalMinutes = 0.1;
let lastMoment = new Date();

function tryParseJson(str) {
    try {
        JSON.parse(str);
    } catch (e) {
        return false;
    }
    return JSON.parse(str);
}

console.log('Initialising...');

port.on('open', function() {
	console.log('Opened port...');
	
	port.on('data', function(data) {
		const sensorData = tryParseJson(data);
		const moment = new Date();

		if (moment.getTime() - lastMoment.getTime() > logIntervalMinutes * 60 * 1000) {
			lastMoment = moment;

			dynamo.putItem({
				TableName: 'temp-data',
				Item: {
					temperature: sensorData.temperature,
					humidity: sensorData.humidity,
					datetime: moment.getTime()
				}
			}, function(err, data) {
				if (err) {
					console.log(err);
				} else {
					console.log(JSON.stringify(data, null, '  '));
				}
			});
		}
	});
});