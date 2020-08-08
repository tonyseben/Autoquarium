
void loopRelays() {
  EVERY_N_SECONDS( 1 ) {
    int hourNow = TIME_NOW.hour();
    if (DEBUG) {
      hourNow = TIME_NOW.minute() % 24;
    }

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
    } else {
      relay3State = HIGH;
    }

    digitalWrite(PIN_RELAY1, relay1State);
    digitalWrite(PIN_RELAY2, relay2State);
    digitalWrite(PIN_RELAY3, relay3State);
    digitalWrite(PIN_RELAY4, relay4State);

    if (relay1LastState != relay1State
        || relay2LastState != relay2State
        || relay3LastState != relay3State
        || relay4LastState != relay4State) {
          if(relay1LastState != relay1State){
            dPrintln((String)">>>>>>>>>>>>>>>> RELAY 1 >>> " + relay1LastState + " to " + relay1State);
          } 
          if(relay2LastState != relay2State){
            dPrintln((String)">>>>>>>>>>>>>>>> RELAY 2 >>> " + relay2LastState + " to " + relay2State);
          }
          if(relay3LastState != relay3State){
            dPrintln((String)">>>>>>>>>>>>>>>> RELAY 3 >>> " + relay3LastState + " to " + relay3State);
          }
          if(relay4LastState != relay4State){
            dPrintln((String)">>>>>>>>>>>>>>>> RELAY 4 >>> " + relay4LastState + " to " + relay4State);
          }
      // Beeps equals no of relays ON.
      buzzRelayOn();
    }

    dPrintln((String)"R1:" + relay1State + " R2:" + relay2State
             + " R3:" + relay3State + " R4:" + relay4State);
  }
}
