// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Tilt Switch (SKU#101020025)

#include <MjGrove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveTiltSwitch Tilt(&Board.D38);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Board.D38.Enable();
  Tilt.Init();
}

void loop() {
  bool tiltState = Tilt.IsOn();
  SerialUSB.print(tiltState ? '*' : '.');
  
  delay(INTERVAL);
}
