// BOARD Seeed Wio 3G
// GROVE I2C <-> GroveMiniTrackBall (SKU#101020091)

#include <MjGrove.h>

#define INTERVAL    (2000)

WioCellular Wio;

GroveBoard Board;
GroveMiniTrackBall TrackBall(&Board.I2C);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  TrackBall.Init();
}

void loop() {
  TrackBall.Read();
  
  delay(INTERVAL);
}
