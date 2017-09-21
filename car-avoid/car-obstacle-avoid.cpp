#include <NewPing.h>

// Set motor control pins
int motorLeftSpeed = 6;
int motorLeftForward = 9;
int motorLeftBackward = 8;

int motorRightSpeed = 11;
int motorRightForward = 12;
int motorRightBackward = 10;

// Set sonar sensor pins
int trigger = 3;
int echo = 2;

// Sonar max distance
int maxDistance = 400;
int turnThreshold = 100;

// Initialise sonar sensor
NewPing sonar(trigger, echo, maxDistance);

void setup() {

    // Set all motor pins as outputs
    pinMode(motorLeftSpeed, OUTPUT);
    pinMode(motorRightSpeed, OUTPUT);
    pinMode(motorLeftForward, OUTPUT);
    pinMode(motorLeftBackward, OUTPUT);
    pinMode(motorRightForward, OUTPUT);
    pinMode(motorRightBackward, OUTPUT);
}

void turnLeft(int speed) {

    // Set left motor to backward direction
    digitalWrite(motorLeftForward, LOW);
    digitalWrite(motorLeftBackward, HIGH);
    // Set left motor speed to maximum (0 - 255)
    analogWrite(motorLeftSpeed, speed);

    // Set right motor to forward direction
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
    // Set right motor speed to maximum (0 - 255)
    analogWrite(motorRightSpeed, speed);
}

void turnRight(int speed) {
    
    // Set left motor to forward direction
    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    // Set left motor speed to maximum (0 - 255)
    analogWrite(motorLeftSpeed, speed);

    // Set right motor to backward direction
    digitalWrite(motorRightForward, LOW);
    digitalWrite(motorRightBackward, HIGH);
    // Set right motor speed to maximum (0 - 255)
    analogWrite(motorRightSpeed, speed);
}

void moveForward(int speed) {
    
    // Set left motor to forward direction
    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    // Set left motor speed to maximum (0 - 255)
    analogWrite(motorLeftSpeed, speed);

    // Set right motor to forward direction
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
    // Set right motor speed to maximum (0 - 255)
    analogWrite(motorRightSpeed, speed);
}

void loop() {

    // If mesured distance is below threshold
    if (sonar.ping_cm() < turnThreshold / 10) {

        // Turn away
        turnLeft(255);

    // If measured distance is over threshold
    } else {
        moveForward(255);
    }
}