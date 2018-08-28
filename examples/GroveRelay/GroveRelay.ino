// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Relay (SKU#103020005)

#include <MjGrove.h>

#define RELAY_ON_TIME   (1000)
#define RELAY_OFF_TIME  (3000)

GroveBoard Board;
GroveRelay Relay(&Board.D38);

void setup() {
  delay(200);

  Board.D38.Enable();
  Relay.Init();
}

void loop() {
  Relay.On();
  delay(RELAY_ON_TIME);

  Relay.Off();
  delay(RELAY_OFF_TIME);
}
