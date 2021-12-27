#include <LN513.h>

LN513 ln513;

void setup() {
  ln513.initialize(true);
}

void loop() {
  for (int i = 0; i < 10; ++i) {
    ln513.change(i);
    delay(1000);
  }
}
