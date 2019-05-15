#include <MjGrove.h>

#define INTERVAL    (1000)

WioCellular Wio;

GroveBoard Board;
OmronBaro2SMPB02E Sensor(&Board.I2C);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  Sensor.Init();
}

void loop() {
  Sensor.Read();
  
  SerialUSB.print("Current temperature = ");
  SerialUSB.print(Sensor.Temperature);
  SerialUSB.print("C  ");
  SerialUSB.print("pressure = ");
  SerialUSB.print(Sensor.Pressure);
  SerialUSB.println("Pa");
  
  delay(INTERVAL);
}
