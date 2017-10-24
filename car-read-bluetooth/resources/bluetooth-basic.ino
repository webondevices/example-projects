// Pin connections:
// BT VCC -> 5V
// BT GND -> GND
// BT TX  -> D8 - no need for voltage divider
// BT TX  -> D8 - voltage divider needed (5V to 3.3V)
 
#include <AltSoftSerial.h>

// Create Software Serial instance for Bluetooth module
AltSoftSerial BTserial; 

char c = "";
String message = "";
 
void setup() {
    
    // Start serial communication with computer
    Serial.begin(57600);
    
    // Start serial communication with Bluetooth module
    BTserial.begin(57600);  
}
 
void loop() {

    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available()) {
        c = BTserial.read();

        // Concatenate received characters to a string
        message += c;

        // If end line character detected, output message
        if (c == 10 | c == 13) {
          Serial.print("From BT: " + message);
          message = "";
        }
        
    }
 
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available()) {

        // Read character
        c = Serial.read();

        // Send character
        BTserial.write(c);
 
        // Echo the user input to the main window. 
        Serial.write(c);
    }
}
