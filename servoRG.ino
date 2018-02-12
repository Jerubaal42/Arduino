#include <Servo.h>
Servo leftservo;
Servo rightservo;
int x=1;
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  leftservo.attach(10);
  rightservo.attach(9);
  delay(1000);
  leftservo.detach();
  rightservo.detach();
  delay(100);
  leftservo.attach(10);
  delay(2100);
  leftservo.detach();
  delay(100);
  leftservo.attach(10);
  rightservo.attach(9);
  delay(1000);
  leftservo.detach();
  rightservo.detach();
  delay(100);
  leftservo.attach(10);
  delay(2100);
  leftservo.detach();
  delay(100);
}
