
RTC_DS1307 RTC;
char *result = malloc(20);

void setupRTC() {
  Wire.begin();
  if (!RTC.begin()) {
    dPrintln("[!] RTC not Working");
    while (true) {}
  }
  dPrintln("RTC Start");
  if (DEBUG) {
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

DateTime getTimeFromRTC() {
  DateTime now = RTC.now();

  if (now.year() == 2165) {
    dPrintln("[!] RTC Incorrect time");
    return NULL;
  }
  else {
    sprintf(
      result,
      "%02d/%02d/%02d %02d:%02d:%02d",
      now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());

    EVERY_N_SECONDS( 1 ) {
      dPrint(result);
      dPrintln((String)" | H:" + now.minute() % 24 + ", M:" + now.second());
    }
    return now;
  }
}
