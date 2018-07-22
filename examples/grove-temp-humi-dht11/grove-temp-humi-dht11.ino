// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Temperature & Humidity Sensor (DHT11) (SKU#101020011)

#include <MjGrove.h>

#define INTERVAL    (2000)

GroveBoard Board;
GroveTempHumiDHT11 TempHumi(&Board.D38);

void setup() {
  delay(200);
#if defined ARDUINO_WIO_3G
  SerialUSB.begin(115200);
#endif

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
