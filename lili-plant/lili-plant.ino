#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

// Analog pins
const int TEMP_PIN  = 0;
const int MOIST_PIN = 1;
const int LIGHT_PIN = 2;

// Digital pins
const int MOTION_PIN = 2;
const int LED_PIN = 3;

// Voice IDs:
// 1 : I'm happy right now. Everything is fine with me.
// 2 : It's really cold in here. Can you turn on the heating?
// 3 : It's very hot in here. Can you let some fresh are in?
// 4 : Hi, how are you? My name is Lili. I'm Maya's flower.
// 5 : Can you water me please? My soil is dry.
// 6 : My soil is too wet. I don't need more water.
// 7 : It's too dark in here. I need more sun light.

// Set volume 0 - 30
int volume = 20;

// Measurements
float temperature = 0.0;
int moisture = 0;
int light = 0;

// Delay
unsigned long previousMillis = 0;
const long interval = 3000;

void setup() {
  
    // Setup motion sensor
    pinMode(MOTION_PIN, INPUT);

    // Setup LED
    pinMode(LED_PIN, OUTPUT);

    // Setup MP3 player
    Serial.begin(9600);
    // mp3_set_serial(Serial);
    delay(50);
    // mp3_set_volume(volume);
}

void speak(int voiceID) {  
    mp3_play(voiceID);
    delay(6000);
}

void interpretSituation(){
    boolean tempWasGood = true;
    boolean moistWasGood = true;
    boolean lightWasGood = true;

    // Greeting
    speak(4);

    // Check temperature
    if (temperature < 19) {
        speak(2);
        tempWasGood = false;
    
    } else if (temperature > 24) {
        speak(3);
        tempWasGood = false;   
    }

    // Check moisture
    if (moisture > 60) {
        speak(5);
        moistWasGood = false;
    
    } else if (moisture < 30) {
        speak(6);
        moistWasGood = false;   
    }

    // Check light
    if (light < 60) {
        speak(7);
        lightWasGood = false;
    }

    // If ereything was good
    if (tempWasGood && moistWasGood && lightWasGood) {
        speak(1);
    }
}

float readPin(int pinNum) {
    analogRead(pinNum);
    return analogRead(pinNum);
}

void loop() {

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;

        // Read temperature sensors
        temperature = (readPin(TEMP_PIN) * 500.0) / 1024;
        Serial.println(temperature);

        // Read moisture sensor
        moisture = map(readPin(MOIST_PIN), 1023, 0, 0, 100);
        Serial.println(moisture);

        // Read light sensor
        light = map(readPin(LIGHT_PIN), 500, 0, 0, 100);
        Serial.println(light);
        
    }

    // Handle motion sensor
    if (digitalRead(MOTION_PIN)) {
        
        interpretSituation();
    }
}
