var SerialPort = require("serialport");
var port = new SerialPort("/dev/tty.x", {
	parser: SerialPort.parsers.readline('\n')
});

var fs = require('fs');

var lastMoment = new Date();
var logIntervalMinutes = 15;

console.log('Initialising...');

port.on('open', function() {
	console.log('Opened port...');
	
	port.on('data', function(data) {
		var sensorData = tryParseJson(data);
		var moment = new Date();

		if (moment.getTime() - lastMoment.getTime() > logIntervalMinutes * 60 * 1000) {
			lastMoment = moment;
			fs.appendFile('log.txt', ('\n' + sensorData.temperature + ' , ' +  sensorData.humidity + ' , ' + moment), function (err) {
			    if (err) return console.log(err);
			    console.log('Logged data: ', moment);
			});
		}
	});
});

function tryParseJson(str) {
    try {
        JSON.parse(str);
    } catch (e) {
        return false;
    }
    return JSON.parse(str);
}