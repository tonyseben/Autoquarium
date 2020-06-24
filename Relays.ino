
void runRelays() {
  Serial.print("Run Relays: ");
  int hourNow = TIME_NOW.minute() % 24;

  boolean relay1LastState = digitalRead(PIN_RELAY1);
  boolean relay2LastState = digitalRead(PIN_RELAY2);
  boolean relay3LastState = digitalRead(PIN_RELAY3);
  boolean relay4LastState = digitalRead(PIN_RELAY4);

  boolean relay1State = LOW;
  boolean relay2State = LOW;
  boolean relay3State = LOW;
  boolean relay4State = LOW;

  if (!IS_PAUSED) {
    relay1State = RELAY1_HOURS[hourNow];
    relay2State = RELAY2_HOURS[hourNow];
    relay3State = RELAY3_HOURS[hourNow];
    relay4State = RELAY4_HOURS[hourNow];
  }

  digitalWrite(PIN_RELAY1, relay1State);
  digitalWrite(PIN_RELAY2, relay2State);
  digitalWrite(PIN_RELAY3, relay3State);
  digitalWrite(PIN_RELAY4, relay4State);

  int changeCount = 0;
  if (relay1LastState != relay1State
      || relay2LastState != relay2State
      || relay3LastState != relay3State
      || relay4LastState != relay4State) {
    // Beeps equals no of relays ON.
    buzzRelayOn(relay1State + relay2State + relay3State + relay4State);
  }

  Serial.println((String)"R1:" + relay1State + " R2:" + relay2State
                 + " R3:" + relay3State + " R4:" + relay4State);
}
