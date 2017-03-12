function init() {
    var socket = io.connect();
    var connected = false;

    var lampState = false;

    var colorValues = {
        red: 255,
        green: 255,
        blue: 255
    };

    var randomTicker = null;
    var randomState = false;

    socket.on('connect', function () {
        connected = true;
    });

    socket.on('sync', function(signal){
        colorValues = signal.colorValues;
        lampState = signal.lampState;
        syncRgb();
    });

    function syncRgb(){
        red.value = colorValues.red;
        green.value = colorValues.green;
        blue.value = colorValues.blue;
    }

    function updateServer() {
        if (connected) {
            socket.emit('set', {colorValues: colorValues, lampState: lampState});
        }
    }

    function color(color, event){
        colorValues[color] = parseInt(event.currentTarget.value);
        updateServer();
    }

    function addRandomTicker(){
        randomTicker = setInterval(function(){
            colorValues = {
                red: Math.floor(Math.random() * 255) + 1,
                green: Math.floor(Math.random() * 255) + 1,
                blue: Math.floor(Math.random() * 255) + 1
            };
            syncRgb();
            updateServer();
        }, 250);
    }

    function random(){
        if (!randomState) {
            randomState = true; 
            randomBtn.className = 'on';
            addRandomTicker();
        } else {
            clearInterval(randomTicker);
            randomState = false;
            randomBtn.className = '';
        }
    }

    function onoff(){
        if (lampState) {
            lampState = false;
            onoffBtn.className = 'on';
        } else {
            lampState = true;
            onoffBtn.className = '';
        }
        updateServer();
    }

    function listen(){
        recognition.start();
        listenBtn.className = 'on';
        listenBtn.style.backgroundColor = '#ffb4b4';
    }

    function interpretSpeech(){
        var result = getComputedStyle(speechResult).getPropertyValue("background-color");
        result = result.slice(4, result.length - 1);

        var colorArray = result.split(',');

        colorValues.red = parseInt(colorArray[0]);
        colorValues.green = parseInt(colorArray[1]);
        colorValues.blue = parseInt(colorArray[2]);

        syncRgb();
        updateServer();
    }

    var red = document.getElementById('red');
    red.addEventListener('input', color.bind(this, 'red'));

    var green = document.getElementById('green');
    green.addEventListener('input', color.bind(this, 'green'));

    var blue = document.getElementById('blue');
    blue.addEventListener('input', color.bind(this, 'blue'));

    var randomBtn = document.getElementById('random');
    randomBtn.addEventListener('click', random);

    var onoffBtn = document.getElementById('onoff');
    onoffBtn.addEventListener('click', onoff);

    var listenBtn = document.getElementById('listen');
    listenBtn.addEventListener('click', listen);

    var speechResult = document.getElementById('speech-result');

    window.SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
    var recognition = new SpeechRecognition();
    recognition.continuous = true;
    recognition.interimResults = true;

    recognition.onresult = function(event) {
        var results = event.results;
        
        for (var i = event.resultIndex; i !== results.length; ++i) {
            var result = results[i];
            var interimTranscript = '';
        
            if (result.isFinal) {
                speechResult.style.backgroundColor = results[0][0].transcript;
                recognition.stop();
                listenBtn.className = '';
                listenBtn.style.backgroundColor = '#eee';
            } else {
                interimTranscript = result[0].transcript;
                speechResult.style.backgroundColor = interimTranscript;
            }

            interpretSpeech();
        }
    };
}

window.onload = init;