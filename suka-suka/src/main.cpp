#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D5;
int SCL_pin = D6;
// put function declarations here:
int trigPin = D0;
int echoPin = D1;
int redLED = D2;
int greenLED = D3;


long duration;
int distance;


void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(D4);
  Serial.begin(9600);
  Wire.begin(SDA_pin, SCL_pin);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  myservo.write(0);
  
  duration = pulseIn(echoPin, HIGH);

  distance = (0.034 * duration)/2;
  lcd.setCursor(0,0);
  // Serial.print("Jarak:  ");
  // Serial.print(distance);
  // Serial.println(" cm");
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <= 10) {
    myservo.write(90);
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    delay(15);

  } else {
    myservo.write(0);
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    delay(15);
  }

  delay(1000);

}

