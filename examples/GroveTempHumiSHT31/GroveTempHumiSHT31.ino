// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Temperature&Humidity Sensor (SHT31) (SKU#101020212)

#include <MjGrove.h>

#define INTERVAL    (2000)

WioCellular Wio;

GroveBoard Board;
GroveTempHumiSHT31 TempHumi(&Board.I2C);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
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

