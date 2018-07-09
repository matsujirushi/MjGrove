#include <Grove.h>

GroveConnectorDIO D38(38, 39);

void setup() {
  pinMode(38, OUTPUT);

  D38.P1().SetPullUpDown(GroveGpio::PUPD_NO);
  D38.P1().SetOutType(GroveGpio::OUT_TYPE_PUSH_PULL);
  D38.P1().SetOutSpeed(GroveGpio::OUT_SPEED_LOW);
  D38.P1().SetMode(GroveGpio::MODE_OUTPUT);
}

void loop() {
  D38.P1().Write(true);
  delay(200);
  D38.P1().Write(false);
  delay(800);
}
