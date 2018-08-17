// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - Temp&Humi&Barometer Sensor (BME280) (SKU#101020193)

#include <MjGrove.h>

#define INTERVAL    (2000)

WioCellular Wio;

GroveBoard Board;
GroveTempHumiBaroBME280 TempHumiBaro(&Board.I2C);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  TempHumiBaro.Init();
}

void loop() {
  TempHumiBaro.Read();
  
  SerialUSB.print("Current humidity = ");
  SerialUSB.print(TempHumiBaro.Humidity);
  SerialUSB.print("%  ");
  SerialUSB.print("temperature = ");
  SerialUSB.print(TempHumiBaro.Temperature);
  SerialUSB.print("C  ");
  SerialUSB.print("pressure = ");
  SerialUSB.print(TempHumiBaro.Pressure);
  SerialUSB.println("Pa");

  delay(INTERVAL);
}

