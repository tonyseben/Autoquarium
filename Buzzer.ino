

void buzzSetup() {
  tone(PIN_BUZZER, 5000, 100);
  delay(250);
  tone(PIN_BUZZER, 5500, 100);
  delay(250);
  tone(PIN_BUZZER, 6000, 500);
}

void buzzRelayOn(int count) {
  for (int i = 0; i < count; i++) {
    tone(PIN_BUZZER, 4000, 100);
    delay(150);
  }
}

void buzzPauseOn() {
  tone(PIN_BUZZER, 5500, 200);
}

void buzzPauseOff() {
  tone(PIN_BUZZER, 5500, 200);
  delay(250);
  tone(PIN_BUZZER, 5500, 100);
}
