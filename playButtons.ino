static void playButtons() {

  byte keyStatus [4] = {0, 0, 0, 0};
  const char buttKeyBoard [4] = {'d', 'f', 'j', 'k'};
  bool ex = false;
  byte pressed = 0;
  while (!ex) {
    for (byte i = 0; i < 4; i++) {  //Проверяем было ли прерывание на соот. входах для игровых кнопок
      if (pressButton[i]) {
        if (digitalRead(i)) {
          if (!keyStatus[i]) {
            Keyboard.press(buttKeyBoard [i]);
            keyStatus[i] = 1;
            pressed++;
          }
        }
        else {
          Keyboard.release(buttKeyBoard [i]);
          pressButton[i] = 0;
          keyStatus[i] = 0;
          pressed--;
        }
      }
      else if (pressed == 0) ex = true;
    }
  }
}
