// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Buzzer (SKU#107020000)

#include <Grove.h>

#define BUZZER_ON_TIME  (200)
#define BUZZER_OFF_TIME (800)

GroveBoard Board;
GroveBuzzer Buzzer(&Board.D38);

void setup() {
}

void loop() {
  Buzzer.On();
  delay(BUZZER_ON_TIME);

  Buzzer.Off();
  delay(BUZZER_OFF_TIME);
}
