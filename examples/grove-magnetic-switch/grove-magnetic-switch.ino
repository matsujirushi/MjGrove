// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Magnetic Switch (SKU#101020038)

#include <MjGrove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveMagneticSwitch Switch(&Board.D38);

void setup() {
  delay(200);
#if defined ARDUINO_WIO_3G
  SerialUSB.begin(115200);
#endif

  Board.D38.Enable();
  Switch.Init();
}

void loop() {
  bool switchState = Switch.IsOn();
  SerialUSB.print(switchState ? '*' : '.');
  
  delay(INTERVAL);
}

