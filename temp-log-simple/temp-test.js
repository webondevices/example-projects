var SerialPort = require("serialport");
var port = new SerialPort("/dev/tty.x", {
	parser: SerialPort.parsers.readline('\n')
});

console.log('Initialising...');

port.on('open', function() {
	console.log('Opened port...');
	
	port.on('data', function(data) {
		var sensorData = tryParseJson(data);

		console.log("Temperature: " + sensorData.temperature + "°C");
		console.log("   Humidity: " + sensorData.humidity + "%");
		console.log("===================");
		console.log("");
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