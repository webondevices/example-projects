var five = require('johnny-five');
var server = require('./server');


// Start server
server.start();


// Start wakeup alarm
server.setAlarm('6:30', '30min');
