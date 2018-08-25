// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - EMG Detector (SKU#101020058)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveEMGDetector Detector(&Board.A6);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.A6.Enable();
  Detector.Init();
}

void loop() {
  Detector.Read();

  SerialUSB.println(Detector.Level);

  delay(INTERVAL);
}
