#include <Arduino.h>
#include <Servo.h>


Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(D4);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(90);

  for (int pos = 0; pos <= 180; pos++)
  {
    /* code */
    myservo.write(90);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--)
  {
    /* code */
    myservo.write(pos);
    delay(15);
  }
  
  
}
