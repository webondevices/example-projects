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
