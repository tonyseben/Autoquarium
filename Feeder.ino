
//Servo FEED_SERVO;
//
//int feedTimes[] = {9, 21};
//int feedOffset = 5; // minutes
//int feedDuration = 20; // minutes
//int position = 0;


void setupFeeder(){
  //FEED_SERVO.attach(PIN_SERVO);
}


void runFeeder() {
  //  dPrint("Run feeder: ");
  //
  //  int hourNow = TIME_NOW.minute() % 24;
  //  int minuteNow = TIME_NOW.second();
  //
  //  int runStatus = STATUS_IDLE;
  //  int timeCount = (sizeof(feedTimes) / sizeof(feedTimes[0]));
  //
  //  for (int i = 0; i < timeCount; i++) {
  //    if (hourNow == feedTimes[i] && minuteNow < feedDuration) {
  //      runStatus = STATUS_RUNNING;
  //      break;
  //    }
  //  }
  //
  //  if (runStatus == STATUS_RUNNING
  //  && minuteNow > feedOffset) {
  //    while (position < 180) {
  //      FEED_SERVO.write(position++);
  //      delay(5);
  //    }
  //
  //    while (position >= 0) {
  //      FEED_SERVO.write(position--);
  //      delay(5);
  //    }
  //  }
  //
  //  dPrintln((String)" Status " + runStatus);
  //  FEEDER_STATUS = runStatus;
}
