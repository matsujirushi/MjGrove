// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - Oxygen Sensor(ME2-O2-„U20) (SKU#101020002)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveGasO2 Gas(&Board.A6);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.A6.Enable();
  Gas.Init();
}

void loop() {
  Gas.Read();

  SerialUSB.println(Gas.Concentration);

  delay(INTERVAL);
}
