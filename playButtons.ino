void playButtons() {

  byte keyStatus [4] = {0, 0, 0, 0};
  char buttKeyBoard [4] = {'d', 'f', 'j', 'k'};
  bool ex = false;
  while (!ex) {
    for (byte i = 0; i < 4; i++) {  //Проверяем было ли прерывание на соот. входах для игровых кнопок
      if (pressButton[i]) {
        if (digitalRead(i)) {
          if (!keyStatus[i]) {
            Keyboard.press(buttKeyBoard [i]);
            keyStatus[i] = 1;
          }
        }
        else {
          pressButton[i] = 0;
          keyStatus[i] = 0;
          Keyboard.release(buttKeyBoard [i]);
          ex = true;
        }
      }
    }
  }
}
