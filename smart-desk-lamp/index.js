var five = require('johnny-five');
var server = require('./server');

var arduino = new five.Board();

// Start server
server.start();

arduino.on('ready', function() {
    
    server.updateData(sensorData);
    
});
