// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - 3-Axis Digital Accelerometer(±16g) (SKU#101020054)

#include <Grove.h>

#define INTERVAL    (100)

#if defined ARDUINO_WIO_3G
Wio3G Wio;
#else
#error "This board is not supported."
#endif

GroveBoard Board;
GroveAccelerometer16G Accel(&Board.I2C);

void setup() {
  delay(200);
  
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  WireI2C.begin();    // TODO
  Accel.Initialize(); // TODO
}

void loop() {
  Accel.ReadXYZ();

  SerialUSB.print(Accel.X);
  SerialUSB.print(' ');
  SerialUSB.print(Accel.Y);
  SerialUSB.print(' ');
  SerialUSB.println(Accel.Z);

  delay(INTERVAL);
}
