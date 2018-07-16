// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Temperature & Humidity Sensor (DHT11) (SKU#101020011)

#if defined ARDUINO_WIO_3G
#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino
#else
#error "This board is not supported."
#endif
#include <Grove.h>

#define INTERVAL    (2000)

GroveBoard Board;
GroveTempHumiDHT11 TempHumi(&Board.D38);

void setup() {
  delay(200);
  
  SerialUSB.begin(115200);

  TempHumi.Initialize();
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
