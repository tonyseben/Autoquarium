
//Servo FEED_SERVO1;
//Servo FEED_SERVO2;
//
//int feedTimes[] = {9, 21};
//int feedOffset = 5; // minutes
//int feedDuration = 20; // minutes
//int position = 0;


void setupFeeder(){
  //FEED_SERVO1.attach(PIN_SERVO1);
  //FEED_SERVO2.attach(PIN_SERVO2);
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
  //      FEED_SERVO1.write(position++);
  //      delay(5);
  //    }
  //
  //    while (position >= 0) {
  //      FEED_SERVO1.write(position--);
  //      delay(5);
  //    }
  //  }
  //
  //  dPrintln((String)" Status " + runStatus);
  //  FEEDER_STATUS = runStatus;
}
