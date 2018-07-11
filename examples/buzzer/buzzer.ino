#include <Grove.h>

GroveConnectorDIO D38(38, 39);

void setup() {
  HalRcc::AHB1_GPIOC_Enable();

  D38.P1().SetPullUpDown(HalGpio::PUPD_NO);
  D38.P1().SetOutType(HalGpio::OUT_TYPE_PUSH_PULL);
  D38.P1().SetOutSpeed(HalGpio::OUT_SPEED_LOW);
  D38.P1().SetMode(HalGpio::MODE_OUTPUT);
}

void loop() {
  D38.P1().Write(true);
  delay(200);
  D38.P1().Write(false);
  delay(800);
}
