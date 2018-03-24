const SerialPort = require('serialport');

// Add your USB port name
const port = new SerialPort('/dev/xy', {
	parser: SerialPort.parsers.readline('\n')
});

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

		console.log(`Temperature: ${sensorData.temperature}°C`);
		console.log(`   Humidity: ${sensorData.humidity}%`);
		console.log(`===================\n`);
	});
});