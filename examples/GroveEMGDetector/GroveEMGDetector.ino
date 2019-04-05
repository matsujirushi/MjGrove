// BOARD Seeed Wio 3G
// GROVE A6 <-> Grove - EMG Detector (SKU#101020058)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveEMGDetector Detector(&Board.A6);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

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
