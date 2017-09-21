#include <NewPing.h>

// Set motor control pins
int motorLeftSpeed = 7;
int motorLeftForward = 8;
int motorLeftBackward = 9;

int motorRightSpeed = 12;
int motorRightForward = 10;
int motorRightBackward = 11;

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

void loop() {
    
    // If sonar sensor 
    if
}

// void demoOne() {



//   // this function will run the motors in both directions at a fixed speed
//   // turn on motor A
//   digitalWrite(motorLeftForward, HIGH);
//   digitalWrite(motorLeftBackward, LOW);
//   // set speed to 200 out of possible range 0~255
//   analogWrite(motorLeftSpeed, 200);
//   // turn on motor B
//   digitalWrite(motorRightForward, HIGH);
//   digitalWrite(motorRightBackward, LOW);
//   // set speed to 200 out of possible range 0~255
//   analogWrite(motorRightSpeed, 200);
//   delay(2000);
//   // now change motor directions
//   digitalWrite(motorLeftForward, LOW);
//   digitalWrite(motorLeftBackward, HIGH);  
//   digitalWrite(motorRightForward, LOW);
//   digitalWrite(motorRightBackward, HIGH); 
//   delay(2000);
//   // now turn off motors
//   digitalWrite(motorLeftForward, LOW);
//   digitalWrite(motorLeftBackward, LOW);  
//   digitalWrite(motorRightForward, LOW);
//   digitalWrite(motorRightBackward, LOW);
// }
// void demoTwo()
// {
//   // this function will run the motors across the range of possible speeds
//   // note that maximum speed is determined by the motor itself and the operating voltage
//   // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
//   // by your hardware
//   // turn on motors
//   digitalWrite(motorLeftForward, LOW);
//   digitalWrite(motorLeftBackward, HIGH);  
//   digitalWrite(motorRightForward, LOW);
//   digitalWrite(motorRightBackward, HIGH); 
//   // accelerate from zero to maximum speed
//   for (int i = 0; i < 256; i++)
//   {
//     analogWrite(motorLeftSpeed, i);
//     analogWrite(motorRightSpeed, i);
//     delay(20);
//   } 
//   // decelerate from maximum speed to zero
//   for (int i = 255; i >= 0; --i)
//   {
//     analogWrite(motorLeftSpeed, i);
//     analogWrite(motorRightSpeed, i);
//     delay(20);
//   } 
//   // now turn off motors
//   digitalWrite(motorLeftForward, LOW);
//   digitalWrite(motorLeftBackward, LOW);  
//   digitalWrite(motorRightForward, LOW);
//   digitalWrite(motorRightBackward, LOW);  
// }