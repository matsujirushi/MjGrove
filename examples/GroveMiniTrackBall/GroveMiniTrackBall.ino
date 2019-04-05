// BOARD Seeed Wio 3G
// GROVE I2C <-> GroveMiniTrackBall (SKU#101020091)

#include <MjGrove.h>

#define INTERVAL    (2000)

WioCellular Wio;

GroveBoard Board;
GroveMiniTrackBall TrackBall(&Board.I2C);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  TrackBall.Init();
}

void loop() {
  TrackBall.Read();

  SerialUSB.print(TrackBall.UpCount);
  SerialUSB.print("-");
  SerialUSB.print(TrackBall.DownCount);
  SerialUSB.print("-");
  SerialUSB.print(TrackBall.LeftCount);
  SerialUSB.print("-");
  SerialUSB.print(TrackBall.RightCount);
  SerialUSB.print("-");
  SerialUSB.print(TrackBall.ConfirmCount);
  SerialUSB.print(" ");
  SerialUSB.print(TrackBall.PositionX);
  SerialUSB.print(",");
  SerialUSB.println(TrackBall.PositionY);
  
  delay(INTERVAL);
}
