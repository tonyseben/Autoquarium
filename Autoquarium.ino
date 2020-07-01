#include <stddef.h>
#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>
#include "Schedule.h"

const int PIN_RELAY1 = 2;
const int PIN_RELAY2 = 3;
const int PIN_RELAY3 = 4;
const int PIN_RELAY4 = 5;
const int PIN_NEOPIXEL = 6;
const int PIN_BUZZER = 7;
const int PIN_SERVO1 = 10;
const int PIN_SERVO2 = 11;
const int PIN_PAUSE = 8;
const int PIN_PAUSE_INDICATOR = 13;

DateTime TIME_NOW;
 
RTC_DS1307 RTC;
Servo FEED_SERVO1;
Servo FEED_SERVO2;

void setup() {
  Serial.begin(57600);
  Serial.println("setup...");

  pinMode(PIN_RELAY1, OUTPUT);
  pinMode(PIN_RELAY2, OUTPUT);
  pinMode(PIN_RELAY3, OUTPUT);
  pinMode(PIN_RELAY4, OUTPUT);
  pinMode(PIN_NEOPIXEL, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_PAUSE_INDICATOR, OUTPUT);
  pinMode(PIN_SERVO1, OUTPUT);
  pinMode(PIN_SERVO2, OUTPUT);
  
  pinMode(PIN_PAUSE, INPUT);

  digitalWrite(PIN_RELAY1, LOW);
  digitalWrite(PIN_RELAY2, LOW);
  digitalWrite(PIN_RELAY3, LOW);
  digitalWrite(PIN_RELAY4, LOW);
  digitalWrite(PIN_NEOPIXEL, LOW);
  digitalWrite(PIN_BUZZER, LOW);
  digitalWrite(PIN_PAUSE, LOW);
  digitalWrite(PIN_PAUSE_INDICATOR, LOW);
  digitalWrite(PIN_SERVO1, LOW);
  digitalWrite(PIN_SERVO2, LOW);

  Wire.begin();
  if (!RTC.begin()) {
    Serial.println("Error: RTC not Working!");
    while (true) {}
  }
  Serial.println("RTC started...");
  //RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
  FEED_SERVO1.attach(PIN_SERVO1);
  FEED_SERVO2.attach(PIN_SERVO2);
  
  buzzSetup();
  delay(2000);
}

void loop() {
  Serial.println("loop..............................................................");
  Serial.println((String)"PAUSE: button:" + digitalRead(PIN_PAUSE) +", led:"+digitalRead(PIN_PAUSE_INDICATOR));

  TIME_NOW = getTimeFromRTC();
  if (TIME_NOW == NULL) {
    return;
  }

  runRelays();
  handlePause();
  delay(1000);
}
