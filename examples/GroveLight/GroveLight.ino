// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - Light Sensor v1.2 (SKU#101020132)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveLight Light(&Board.A6);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.A6.Enable();
  Light.Init();
}

void loop() {
  Light.Read();
  SerialUSB.println(Light.Value * 100, 0);
  
  delay(INTERVAL);
}
