#include "Joystick.h"
#include "Keyboard.h"


// Create Joystick
Joystick_ Joystick;

bool device = 0; //Клавиатура по умолчанию

bool pressButton [5] = {0, 0, 0, 0, 0};
bool pressButtonBuffer [5] = {0, 0, 0, 0, 0};

char buttKeyBoard [5] = {'d', 'f', 'j', 'k', 193, 224, 177, 218, 217, 216, 215}; // CAPS, ENTER, ESC, UP DOWN LEFT RIGHT
//char buttSwitch [5] = {Y, B, A, L, PLUS, MINUS, HOME, UP, DOWN, LEFT, RIGHT };



void setup() {
  Joystick.begin();
  Keyboard.begin();
  for (byte i = 0; i < 4; i++) {
    pinMode(i, INPUT_PULLUP);
    pinMode(i + 8, INPUT_PULLUP);
  }
  pinMode(13, INPUT);
  pinMode(7, INPUT);
  device = digitalRead(13);

  // чтобы постоянно не читать порты сделал булев массив.
  //Таким образом чтение порта идёт только если на кнопку нажали
  attachInterrupt(2, L1, RISING); //0
  attachInterrupt(3, L2, RISING); //1
  attachInterrupt(1, R1, RISING); //2
  attachInterrupt(0, R2, RISING); //0
  attachInterrupt(6, navigations, RISING); //0
}

void L1() {
  pressButton [0] = 1;
}
void L2() {
  pressButton [1] = 1;
}
void R1() {
  pressButton [2] = 1;
}
void R2() {
  pressButton [3] = 1;
}

void navigations() {
  pressButton [4] = 1;
}


void loop() {
  if (!device) {
    byte countButton = 0;
    while (1 > 0) {
      for (byte counter = 0; counter < 8; counter++) { //Счётчик CD4017 бегает по кнопкам
        for (byte i = 0; i < 5; i++) {  //Проверяем было ли прерывание на всех таких входах
          if (pressButton[i]) {
            if (!digitalRead(i + 8)) {
              pressButton[i] = 0;
              //Joystick.releaseButton(i + 4);
              Keyboard.release(buttKeyBoard [i]);
            }
            else {
              //Joystick.pressButton(i + 4); // L
              Keyboard.press(buttKeyBoard [i] );
            }
          }
        }
        /*
          посылаем на ногу "счёт" CD4017
        */
      }
      /*Шлём сброс на CD4017*/
    }
  }
}
