
void setupPin() {

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
}
