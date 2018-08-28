// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - Rotary Angle Sensor (SKU#101020017)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveRotaryAngle RotaryAngle(&Board.A6);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.A6.Enable();
  RotaryAngle.Init();
}

void loop() {
  RotaryAngle.Read();

  SerialUSB.println(RotaryAngle.Volume);

  delay(INTERVAL);
}
