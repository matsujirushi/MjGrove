// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Temperature & Humidity Sensor Pro (AM2302/DHT22) (SKU#101020019)

#include <MjGrove.h>

#define INTERVAL    (2000)

GroveBoard Board;
GroveTempHumiDHT22 TempHumi(&Board.D38);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Board.D38.Enable();
  TempHumi.Init();
}

void loop() {
  TempHumi.Read();
  
  SerialUSB.print("Current humidity = ");
  SerialUSB.print(TempHumi.Humidity);
  SerialUSB.print("%  ");
  SerialUSB.print("temperature = ");
  SerialUSB.print(TempHumi.Temperature);
  SerialUSB.println("C");

  delay(INTERVAL);
}
