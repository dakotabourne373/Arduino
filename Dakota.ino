#include <Servo.h>

Servo myServo;

int proxPinQ = A0;
int proxPin2 = A1;
float proxValQ;
float proxVal2;
int angle;
int pos = 0;

#define DEBUG 1
void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
  pinMode(proxPinQ, INPUT);
  delay(2000);
  pinMode(proxPin2, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  proxValQ = analogRead(proxPinQ);
  proxVal2 = analogRead(proxPin2);
  Serial.print(", Q: ");
  Serial.print(proxValQ);
  delay(5);
  Serial.print(", 2: ");
  Serial.print(proxVal2);
  delay(500);

  if (proxValQ >= 250) {
      myServo.write(0);              // tell servo to go to position in variable 'pos'
    }
  else if (proxValQ < 250) {
      myServo.write(90);              // tell servo to go to position in variable 'pos'
  }
  if (proxVal2 >= 250) {
      myServo.write(0);              // tell servo to go to position in variable 'pos'
    }
  else if (proxVal2 < 250) {
      myServo.write(90);              // tell servo to go to position in variable 'pos'
    }
}

