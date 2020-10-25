// DEBUG FLAG
const boolean DEBUG = false;
// PAUSE FLAG
boolean IS_PAUSED = false;

// PIN ALLOCATION
const int PIN_RELAY1 = 2;
const int PIN_RELAY2 = 4;
const int PIN_RELAY3 = 7;
const int PIN_RELAY4 = 8;
const int PIN_NEOPIXEL = 5;
const int PIN_BUZZER = 3;
const int PIN_SERVO = 6;
const int PIN_PAUSE = 12;
const int PIN_PAUSE_INDICATOR = 13;

int PAUSE_DURATION_SECONDS = 600; // 600 = 10min

// RELAY SCHEDULES
//........................0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23
boolean RELAY1_HOURS[] = {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1};
boolean RELAY2_HOURS[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0};
boolean RELAY3_HOURS[] = {0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1};
boolean RELAY4_HOURS[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

void optimiseConstantsForDebug() {
//  PAUSE_DURATION_SECONDS = 10;
//
//  //....................0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23
//  boolean R1_HOURS[] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1};
//  boolean R2_HOURS[] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0};
//  boolean R3_HOURS[] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
//  boolean R4_HOURS[] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
//
//  memcpy(RELAY1_HOURS, R1_HOURS, 24*sizeof(boolean));
//  memcpy(RELAY2_HOURS, R2_HOURS, 24*sizeof(boolean));
//  memcpy(RELAY3_HOURS, R3_HOURS, 24*sizeof(boolean));
//  memcpy(RELAY4_HOURS, R4_HOURS, 24*sizeof(boolean));
}
