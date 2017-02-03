// Start a simple HTTP server
var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);

var numberOfClients = 0;

var colorValues = {
    red: 255,
    green: 255,
    blue: 255
};

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

		socket.emit('sync', {colorValues: colorValues});

		socket.on('set', function(signal){
			colorValues = signal.colorValues;
		});

		// Decrement client counter if someone disconnects
		socket.on('disconnect', function () {
			numberOfClients--;
		});
	});
}

exports.start = start;
exports.updateData = updateData;
