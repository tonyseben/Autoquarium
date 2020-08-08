
boolean relay1LastState = LOW;
boolean relay2LastState = LOW;
boolean relay3LastState = LOW;
boolean relay4LastState = LOW;

void loopRelays() {
  EVERY_N_SECONDS( 1 ) {
    int hourNow = TIME_NOW.hour();
    if (DEBUG) {
      hourNow = TIME_NOW.minute() % 24;
    }

    relay1LastState = digitalRead(PIN_RELAY1);
    relay2LastState = digitalRead(PIN_RELAY2);
    relay3LastState = digitalRead(PIN_RELAY3);
    relay4LastState = digitalRead(PIN_RELAY4);

    if (IS_PAUSED) {
      digitalWrite(PIN_RELAY1, LOW);
      digitalWrite(PIN_RELAY2, LOW);
      digitalWrite(PIN_RELAY3, HIGH);
      digitalWrite(PIN_RELAY4, LOW);

    } else {
      digitalWrite(PIN_RELAY1, RELAY1_HOURS[hourNow]);
      digitalWrite(PIN_RELAY2, RELAY2_HOURS[hourNow]);
      digitalWrite(PIN_RELAY3, RELAY3_HOURS[hourNow]);
      digitalWrite(PIN_RELAY4, RELAY4_HOURS[hourNow]);

      if (relay1LastState != RELAY1_HOURS[hourNow]
          || relay2LastState != RELAY2_HOURS[hourNow]
          || relay3LastState != RELAY3_HOURS[hourNow]
          || relay4LastState != RELAY4_HOURS[hourNow]) {
        // Beeps if there is a state change on any of the relays
        buzzRelayOn();
      }
    }
    
    dPrintln((String)"IDEAL R1:" + RELAY1_HOURS[hourNow] + " R2:" + RELAY2_HOURS[hourNow] + " R3:" + RELAY3_HOURS[hourNow] + " R4:" + RELAY4_HOURS[hourNow]);
    dPrintln((String)"REAL  R1:" + digitalRead(PIN_RELAY1) + " R2:" + digitalRead(PIN_RELAY2) + " R3:" + digitalRead(PIN_RELAY3) + " R4:" + digitalRead(PIN_RELAY4));
  }
}
