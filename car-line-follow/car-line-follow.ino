// Set motor control pins
int motorLeftSpeed = 6;
int motorLeftBackward = 9;
int motorLeftForward = 8;

int motorRightSpeed = 11;
int motorRightBackward = 12;
int motorRightForward = 10;

int lft = 4;
int ctr = 3;
int rgt = 2;

void setup() {

    // Set all line follow pins as input
    pinMode(lft, INPUT);
    pinMode(ctr, INPUT);
    pinMode(rgt, INPUT);

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

void turnLeft(int speed) {

    // Set left motor speed to maximum (0 - 100)
    analogWrite(motorLeftSpeed, 0);

    // Set right motor speed to maximum (0 - 100)
    analogWrite(motorRightSpeed, speed);
}

void turnRight(int speed) {

    // Set left motor speed to maximum (0 - 100)
    analogWrite(motorLeftSpeed, speed);

    // Set right motor speed to maximum (0 - 100)
    analogWrite(motorRightSpeed, 0);
}

void moveForward(int speed) {
    
    // Set left motor speed to maximum (0 - 100)
    analogWrite(motorLeftSpeed, speed);

    // Set right motor speed to maximum (0 - 100)
    analogWrite(motorRightSpeed, speed);
}

void loop() {
    int left = digitalRead(lft);
    int centre = digitalRead(ctr);
    int right = digitalRead(rgt);
  
    // 101
    if (left == 1 && centre == 0 && right == 1) {
        moveForward(100);
    }

    // 011 || 001
    if ((left == 0 && centre == 1 && right == 1) || (left == 0 && centre == 0 && right == 1)) {
        turnRight(100);
    }

    // 110 || 100
    if ((left == 1 && centre == 1 && right == 0) || (left == 1 && centre == 0 && right == 0)) {
        turnLeft(100);
    }

    // 000
    if (left == 0 && centre == 0 && right == 0) {
        moveForward(0);
    }
}