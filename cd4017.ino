static void navigation() {
  bool statusKeysAll [8] = {0, 0, 0, 0, 0, 0, 0, 0};
  const char keyMapping [8] = {218, 217, 216, 177, 176, 215, 'E', 'Q'};
  // TRIUEQWY
  //215 вправо
  //217 вниз
  //218 вверх
  //216 влево
  //1764 enter
  //177 esc
  bool ex = false;
  byte pressed = 0;
  while (!ex) {
    //сбрасываю счётчик
    digitalWrite(reset, LOW);
    for (byte i = 0; i < 9; i++) {
      digitalWrite(step, LOW);
      //delay(70); нужно успеть убрать палец с клавиши

      if (digitalRead(read)) {
        if (!statusKeysAll[i]) {
          pressed++;
          statusKeysAll[i] = true;
          Keyboard.press(keyMapping[i]);
        }
      }

      else {
        if (statusKeysAll[i]) {
          pressed--;
          Keyboard.release(keyMapping[i]);
          statusKeysAll[i] = false;

        }
      }
      digitalWrite(step, HIGH);
    }

    if (pressed == 0) {
      ex = true;
    }
    digitalWrite(reset, HIGH);
  }
}
