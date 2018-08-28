// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - High Temperature Sensor (SKU#111020002)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveHighTemp Temp(&Board.A6);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

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
