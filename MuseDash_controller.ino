//Joystick.pressButton(i + 4); // L
//Joystick.releaseButton(i + 4);
#define step 8
#define reset 9
#define read 7

#include "Joystick.h"
#include "Keyboard.h"

unsigned long timing;

// Create Joystick
Joystick_ Joystick;

bool device = 0; //Клавиатура по умолчанию

volatile bool pressButton [5] = {0, 0, 0, 0, 0};




void setup() {
  Joystick.begin();
  Keyboard.begin();
  for (byte i = 0; i < 4; i++) {
    pinMode(i, INPUT_PULLUP);
    pinMode(i + 8, INPUT_PULLUP);
  }
  pinMode(13, INPUT);
  pinMode(7, INPUT);
  pinMode(step, OUTPUT);
  pinMode(reset, OUTPUT);
  pinMode(read, INPUT);

  device = analogRead(A0);

  //Чтение по прерыванию - была ли нажата кнопка.
  //Чтение цифровых входов - зажата ли в данный момент
  // Чтобы вечно не крутить digitalRead() используем прерывания.

  attachInterrupt(2, L1, RISING); //0
  attachInterrupt(3, L2, RISING); //1
  attachInterrupt(1, R1, RISING); //2
  attachInterrupt(0, R2, RISING); //0
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


void loop() {
  if (device < 512) {
    while (1 > 0) {
      //
      playButtons();
      //navigation();
    }
  }
}
