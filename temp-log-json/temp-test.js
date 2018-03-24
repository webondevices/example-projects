const SerialPort = require('serialport');

// Add your USB port name
const port = new SerialPort('/dev/xy', {
	parser: SerialPort.parsers.readline('\n')
});

const fs = require('fs');

const logIntervalMinutes = 0.1;
let lastMoment = new Date();

function tryParseJson (str) {
    try {
        JSON.parse(str);
    } catch (e) {
        return false;
    }
    return JSON.parse(str);
}

console.log('Initialising...');

port.on('open', function () {
	console.log('Opened port...');
	
	port.on('data', function (data) {
		const sensorData = tryParseJson(data);
		const moment = new Date();

		if (moment.getTime() - lastMoment.getTime() > logIntervalMinutes * 60 * 1000) {
			lastMoment = moment;

			fs.appendFile('log.txt', `\n${sensorData.temperature} , ${sensorData.humidity} , ${moment}`, function (err) {
			    if (err) return console.log(err);
			    console.log('Logged data: ', moment);
			});
		}
	});
});