// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Temperature & Humidity Sensor (DHT11) (SKU#101020011)

#include <Grove.h>

#define INTERVAL    (2000)

GroveBoard Board;
GroveTempHumiDHT11 TempHumi(&Board.D38);

void setup() {
  delay(200);
  
  SerialUSB.begin(115200);
}

void loop() {
  float temp;
  float humi;
  TempHumi.Read(&temp, &humi);
  
  SerialUSB.print("Current humidity = ");
  SerialUSB.print(humi);
  SerialUSB.print("%  ");
  SerialUSB.print("temperature = ");
  SerialUSB.print(temp);
  SerialUSB.println("C");

  delay(INTERVAL);
}
