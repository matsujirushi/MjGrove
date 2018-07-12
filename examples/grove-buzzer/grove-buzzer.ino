#include <Grove.h>

#define BUZZER_ON_TIME  (200)
#define BUZZER_OFF_TIME (800)

GroveConnectorDIO D38(38, 39);
GroveBuzzer* Buzzer;

void setup() {
  HalRcc::AHB1_GPIOC_Enable();
  Buzzer = new GroveBuzzer(&D38);
}

void loop() {
  Buzzer->On();
  delay(BUZZER_ON_TIME);

  Buzzer->Off();
  delay(BUZZER_OFF_TIME);
}

