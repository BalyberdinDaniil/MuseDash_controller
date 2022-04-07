#include "Joystick.h"
#include "Keyboard.h"


// Create Joystick
Joystick_ Joystick;

bool pressButton [4] = {0, 0, 0, 0};
bool pressButtonBuffer [4] = {0, 0, 0, 0};
char butt [4] = {'f', 'j', 'd', 'k'};

bool device = 0; //Клавиатура по умолчанию

const byte countButtons = 4;

void setup() {
  Joystick.begin();
  Keyboard.begin();
  for (byte i = 0; i < countButtons; i++) {
    pinMode(i, INPUT_PULLUP);
    pinMode(i + 8, INPUT_PULLUP);
  }
  pinMode(13, INPUT);
  device = digitalRead(13);

  // чтобы постоянно не читать порты сделал булев массив.
  //Таким образом чтение порта идёт только если на кнопку нажали
  attachInterrupt(2, ff, RISING);
  attachInterrupt(3, jj, RISING);
  attachInterrupt(1, dd, RISING);
  attachInterrupt(0, kk, RISING);
}

void ff() {
  pressButton [0] = 1;
}
void jj() {
  pressButton [1] = 1;
}
void dd() {
  pressButton [2] = 1;
}
void kk() {
  pressButton [3] = 1;
}


void loop() {
  if (!device) {
    while (1 > 0) {
      for (byte i = 0; i < countButtons; i++) {
        if (pressButton[i]) {
          if (!digitalRead(i + 8)) {
            pressButton[i] = 0;
            //Joystick.releaseButton(i + 4);
            Keyboard.release(butt [i]);
          }
          else {
            //Joystick.pressButton(i + 4); // L
            Keyboard.press(butt [i] );
          }
        }
      }
    }
  }
  else
    while (1 > 0) {
      for (byte i = 0; i < countButtons; i++) {
        if (pressButton[i]) {
          if (!digitalRead(i + 8)) {
            pressButton[i] = 0;
            Joystick.releaseButton(i + 4);
            //Keyboard.release(butt [i] );
          }
          else {
            Joystick.pressButton(i + 4); // L
            //Keyboard.press(butt [i] );
          }
        }
      }
    }
}
