// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Digital Light Sensor (SKU#101020030)

#include <MjGrove.h>

#define INTERVAL    (2000)

WioCellular Wio;

GroveBoard Board;
GroveDigitalLight Light(&Board.I2C);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  Light.Init();
}

void loop() {
  Light.Read();
  
  SerialUSB.print("Current lux = ");
  SerialUSB.println(Light.Lux);

  delay(INTERVAL);
}
