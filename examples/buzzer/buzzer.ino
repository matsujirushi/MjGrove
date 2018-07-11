#include <Grove.h>

GroveConnectorDIO D38(38, 39);

void setup() {
  HalRcc::AHB1_GPIOC_Enable();
  D38.P1().SetMode(GroveGpio::MODE_OUTPUT);
}

void loop() {
  D38.P1().Write(true);
  delay(200);
  D38.P1().Write(false);
  delay(800);
}
