#include <LN513.h>

#define DIGIT1 8
#define DIGIT2 9
#define DIGIT3 10
#define DIGIT4 11

void selectDigit(uint8_t digit);
LN513 ln513;

int16_t delayTime = 100;

void setup() {
  // put your setup code here, to run once:
  ln513.initialize(true);

  pinMode(DIGIT1, OUTPUT);
  pinMode(DIGIT2, OUTPUT);
  pinMode(DIGIT3, OUTPUT);
  pinMode(DIGIT4, OUTPUT);
}

void loop() {
  selectDigit(1);
  ln513.change(4);
  delay(delayTime);
  
  selectDigit(2);
  ln513.change(3);
  delay(delayTime);
  
  selectDigit(3);
  ln513.change(2);
  delay(delayTime);
  
  selectDigit(4);
  ln513.change(1);
  delay(delayTime);

  delayTime -= 5;
  if (delayTime < 0) {
    delayTime = 2;
  }
}

void selectDigit(uint8_t digit)
{
  digitalWrite(DIGIT1, HIGH);
  digitalWrite(DIGIT2, HIGH);
  digitalWrite(DIGIT3, HIGH);
  digitalWrite(DIGIT4, HIGH);
  switch (digit) {
    case 1:
      digitalWrite(DIGIT1, LOW);
      break;

    case 2:
      digitalWrite(DIGIT2, LOW);
      break;

    case 3:
      digitalWrite(DIGIT3, LOW);
      break;

    case 4:
      digitalWrite(DIGIT4, LOW);
      break;
  }
}
