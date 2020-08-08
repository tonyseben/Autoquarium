
void setupUtils() {
  if (DEBUG) {
    Serial.begin(57600);
  }
}


void dPrint(String message){
  if(DEBUG){
    Serial.print(message);
  }
}

void dPrintln(String message){
  if(DEBUG){
    Serial.println(message);
  }
}
