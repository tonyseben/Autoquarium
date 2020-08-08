

void setupBuzzer() {
  tone(PIN_BUZZER, 5000, 100);
  delay(250);
  tone(PIN_BUZZER, 5500, 100);
  delay(250);
  tone(PIN_BUZZER, 6000, 500);
}

void buzzRelayOn() {
  tone(PIN_BUZZER, 3000, 100);
  delay(120);
  tone(PIN_BUZZER, 3000, 100);
  delay(120);
}

void buzzPauseOn() {
  tone(PIN_BUZZER, 4000, 100);
  delay(120);
}

void buzzPauseOff() {
  tone(PIN_BUZZER, 4000, 200);
  delay(220);
}

void playPauseStartMelody() {

  int NOTE_A7 = 3520;
  int NOTE_B7 = 3951;
  int NOTE_C8 = 4186;
  int NOTE_D8 = 4699;
  // notes in the melody:
  int melody[] = {NOTE_C8, NOTE_D8, NOTE_D8, NOTE_A7, NOTE_D8, 0, NOTE_B7, NOTE_C8};
  // note durations: 4 = quarter note, 8 = eighth note, etc.:
  int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(PIN_BUZZER, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(PIN_BUZZER);
  }
}
