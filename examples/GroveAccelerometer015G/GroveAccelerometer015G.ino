// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - 3-Axis Digital Accelerometer(±1.5g) (SKU#101020039)

#include <MjGrove.h>

#define INTERVAL    (100)

WioCellular Wio;

GroveBoard Board;
GroveAccelerometer015G Accel(&Board.I2C);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  Accel.Init();
}

void loop() {
  Accel.Read();

  SerialUSB.print("NORMAL: ");
  SerialUSB.print(Accel.X);
  SerialUSB.print(' ');
  SerialUSB.print(Accel.Y);
  SerialUSB.print(' ');
  SerialUSB.println(Accel.Z);

  SerialUSB.print("LOOKUP: ");
  SerialUSB.print(Accel.LOOKUP_X.g);
  SerialUSB.print(' ');
  SerialUSB.print(Accel.LOOKUP_Y.g);
  SerialUSB.print(' ');
  SerialUSB.println(Accel.LOOKUP_Z.g);
  
  SerialUSB.println("----------------------");

  delay(INTERVAL);
}
