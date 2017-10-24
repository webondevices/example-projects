// Set motor control pins
int motorLeftSpeed = 6;
int motorLeftBackward = 5;
int motorLeftForward = 7;

int motorRightSpeed = 11;
int motorRightBackward = 10;
int motorRightForward = 12;

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

void moveBackwards(int speed) {
    
    // Set left motor to forward direction
    digitalWrite(motorLeftForward, LOW);
    digitalWrite(motorLeftBackward, HIGH);
    // Set left motor speed to maximum (0 - 255)
    analogWrite(motorLeftSpeed, speed);

    // Set right motor to forward direction
    digitalWrite(motorRightForward, LOW);
    digitalWrite(motorRightBackward, HIGH);
    // Set right motor speed to maximum (0 - 255)
    analogWrite(motorRightSpeed, speed);
}

void loop() {

    turnRight(150);
    delay(6000);

    moveBackwards(150);
    delay(7000);

   moveForward(12);
    delay(8000);

   turnLeft(150);
    delay(9000);

}
