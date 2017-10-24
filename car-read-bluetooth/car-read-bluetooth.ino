// HM-10 BLE Bluetooth pin connections:
// BT VCC -> 5V
// BT GND -> GND
// BT TX  -> D8 - no need for voltage divider
// BT RX  -> D9 - voltage divider needed (5V to 3.3V)

#include <AltSoftSerial.h>

// Create Software Serial instance for Bluetooth module
AltSoftSerial BTserial; 

char c = "";

// Set motor control pins
int motorLeftSpeed = 6;
int motorLeftBackward = 5;
int motorLeftForward = 7;

int motorRightSpeed = 11;
int motorRightBackward = 10;
int motorRightForward = 12;

#include "motor.h"

int timer = 0;
 
void setup() {
    
    // Start serial communication with Bluetooth module
    BTserial.begin(57600);

    Serial.begin(57600);

    // Set all motor pins as outputs
    pinMode(motorLeftSpeed, OUTPUT);
    pinMode(motorRightSpeed, OUTPUT);
    pinMode(motorLeftForward, OUTPUT);
    pinMode(motorLeftBackward, OUTPUT);
    pinMode(motorRightForward, OUTPUT);
    pinMode(motorRightBackward, OUTPUT);

    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
}
 
void loop() {

    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available()) {
        c = BTserial.read();
        
        // Up button pressed
        if (c == 65 | c == 97) {
            moveForward(255);
            timer = 1500;
        }

        // Right button pressed
        if (c == 66 | c == 98) {
            turnRight(150);
            timer = 1000;
        }

        // Back button pressed
        if (c == 67 | c == 99) {
            moveBackwards(255);
            timer = 1000;
        }

        // Left arrow pressed
        if (c == 68 | c == 100) {
            turnLeft(100);
            timer = 1500;
        }

    // If no input pressed stop after timer runs out
    } else {
      timer = timer - 1 < 0 ? 0 : timer - 1;
      if (timer == 0) {
        moveForward(0);
      }
    }
}
