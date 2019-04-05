// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - High Temperature Sensor (SKU#111020002)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveHighTemp Temp(&Board.A6);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.A6.Enable();
  Temp.Init();
}

void loop() {
  Temp.Read();

  SerialUSB.println(Temp.Temperature);

  delay(INTERVAL);
}
