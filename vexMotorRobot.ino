// Include the libraries we need
#include <Servo.h>

Servo leftMotor;
Servo rightMotor;
Servo backMotors;
Servo frontMotors;

int rightMotorsPin = 2;
int leftMotorsPin = 4;
int frontMotorsPin = 6;
int backMotorsPin = 8;
int butPin = 12;
int xPin = A0;
int yPin = A2;
int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotorsPin, OUTPUT); //Both motor pins are sending a signal out to the VEX motor controller
  pinMode(rightMotorsPin, OUTPUT);
  pinMode(frontMotorsPin, OUTPUT);
  pinMode(backMotorsPin, OUTPUT);
  pinMode(butPin, INPUT);
  digitalWrite(butPin, HIGH);
  pinMode(yPin,INPUT);
  pinMode(xPin,INPUT);
  
  leftMotor.attach(leftMotorsPin);
  rightMotor.attach(rightMotorsPin);
  frontMotors.attach(frontMotorsPin);
  backMotors.attach(backMotorsPin);

  Serial.begin(115200);

}

void loop() {

  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);

  Serial.println(analogRead(xPin));
  Serial.println(analogRead(yPin));
  delay(500);

 
 if(analogRead(xPin) < 73 ) {
    backMotorsControl(-20);
    frontMotorsControl(-20);
  }

  if(analogRead(xPin) > 950 ) {
    backMotorsControl(20);
    frontMotorsControl(20);
  }

   if(analogRead(yPin) > 950 ) {
    leftMotorsControl(-20);
    rightMotorsControl(-20);
  }
   if(analogRead(yPin) < 73 ) {
    leftMotorsControl(20);
    rightMotorsControl(20);
  }
  

}


//The functions below let you send a power value between -100 and 100 to the motors.
//The servo library uses numbers between 1000 and 2000 to control servos.


int backMotorsControl(int value) {

  backMotors.write(map(value, -100, 100, 1000, 2000));

}

int frontMotorsControl(int value) {

  frontMotors.write(map(value, -100, 100, 1000, 2000));

}

int leftMotorsControl(int value) {

  leftMotor.write(map(value, -100, 100, 1000, 2000));

}

int rightMotorsControl(int value) {
  rightMotor.write(map(value, -100, 100, 1000, 2000));

}