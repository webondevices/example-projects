// Start a simple HTTP server
var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);

var five = require("johnny-five");
var Rasp = require("raspi-io");

var board = new five.Board({
    io: new Rasp({
    	enableSoftPwm: true
    })
}); 

var numberOfClients = 0;
var piConnected = false;

var redLed, greenLed, blueLed;

var lampState = false;
var colorValues = {
    red: 255,
    green: 255,
    blue: 255
};

var alarm = null;

function updateData(sensorData) {
	if (numberOfClients > 0) {
		io.sockets.emit('sensor data', { data: sensorData });
	}
}

function start(data) {
	
	// Start listening on port 8080
	server.listen(8080, function () {
	    console.log('Express server listening on port 8080');
	});

	// Respond to web GET requests with index.html page
	app.get('/', function (request, response) {
	    response.sendFile(__dirname + '/public/index.html');
	});

	// Define route folder for static requests
	app.use(express.static(__dirname + '/public'));

	// Increment client counter if someone connects
	io.on('connection', function (socket) {
		numberOfClients++;

		socket.emit('sync', {
			colorValues: colorValues,
			lampState: lampState
		});

		socket.on('set', function(signal){
			colorValues = signal.colorValues;
			lampState = signal.lampState;

			if (piConnected) {
				redLed.brightness(lampState ? colorValues.red : 0);
				greenLed.brightness(lampState ? colorValues.green : 0);
				blueLed.brightness(lampState ? colorValues.blue : 0);
			}
		});

		// Decrement client counter if someone disconnects
		socket.on('disconnect', function () {
			numberOfClients--;
		});
	});

	// Initialise Raspberry PI
	board.on("ready", function() {
		piConnected = true;
  		redLed = new five.Led(1);
	    greenLed = new five.Led(4);
	    blueLed = new five.Led(5);
  	});
}

function startAlarm(length){
	clearInterval(setAlarm);
	console.log('ALARM');
}

function setAlarm(time, length){
	var hour = parseInt( time.split(':')[0] );
	var minute = parseInt( time.split(':')[1] );

	alarm = setInterval(function(){
		var date = new Date();
		var nowHour = date.getHours();
		var nowMinute = date.getMinutes();

		if (nowHour >= hour && nowMinute >= nowMinute) startAlarm(length);
	});

}

exports.start = start;
exports.updateData = updateData;
