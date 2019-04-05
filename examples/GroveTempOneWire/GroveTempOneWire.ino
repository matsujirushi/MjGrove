// BOARD Seeed Wio 3G
// GROVE D38 <-> One Wire Temperature Sensor (SKU#101990019)

#include <MjGrove.h>

#define INTERVAL    (2000)

GroveBoard Board;
GroveTempOneWire Temp(&Board.D38);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Board.D38.Enable();
  Temp.Init();
}

void loop() {
  Temp.Read();
  
  SerialUSB.print("Current temperature = ");
  SerialUSB.print(Temp.Temperature);
  SerialUSB.println("C");

  delay(INTERVAL);
}
