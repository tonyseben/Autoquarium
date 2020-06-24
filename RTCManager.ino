
DateTime getTimeFromRTC() {

  char *result = malloc(20);
  DateTime now = RTC.now();

  if (now.year() == 2165) {
    Serial.println("Error: Incorrect time in RTC.");
    return NULL;
  }
  else {
    sprintf(
      result,
      "%02d/%02d/%02d %02d:%02d:%02d",
      now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());

    Serial.print(result);
    Serial.println((String)" | hourNow:" + now.minute()%24 + ", minuteNow:" + now.second() + " | unixTime:" + now.unixtime());
    return now;
  }
}
