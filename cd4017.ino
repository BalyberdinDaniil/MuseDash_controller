void navigation() {
  bool statusKeysAll [8] = {0, 0, 0, 0, 0, 0, 0, 0};

  char keyMapping [8] = {218, 217, 216, 'R', 'T', 215, 'E', 'Q'};
  //215 вправо
  //217 вниз
  //218 вверх
  //216 влево
  bool ex = false;

  while (!ex) {

    //сбрасываю счётчик


    digitalWrite(reset, LOW);

    for (byte i = 0; i < 9; i++) {
      digitalWrite(step, LOW);

      if (digitalRead(read)) {
        if (millis() - timing > 70) {
          timing = millis();
          if (!statusKeysAll[i]) {
            statusKeysAll[i] = true;
            Keyboard.press(keyMapping[i]);

          }
        }
      }
      else {
        if (statusKeysAll[i]) {
          Keyboard.release(keyMapping[i]);
          statusKeysAll[i] = false;
          ex = true;
        }
      }
      digitalWrite(step, HIGH);
    }
    digitalWrite(reset, HIGH);
  }
}
