// BOARD Seeed Wio LTE M1/NB1(BG96)
// GROVE I2C <-> Grove - I2C High Accuracy Temp&Humi Sensor (SHT35) (SKU#101020592)

#include <MjGrove.h>

#define INTERVAL    (2000)

WioCellular Wio;

GroveBoard Board;
GroveTempHumiSHT35 TempHumi(&Board.I2C);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  TempHumi.Init();
}

void loop() {
  if (SerialUSB.available() >= 1) {
    switch (SerialUSB.read()) {
    case 'H':
      SerialUSB.println("On heater.");
      TempHumi.SetHeater(true);
      break;
    case 'h':
      SerialUSB.println("Off heater.");
      TempHumi.SetHeater(false);
      break;
    }
  }
  
  TempHumi.Read();
  
  SerialUSB.print("Current humidity = ");
  SerialUSB.print(TempHumi.Humidity);
  SerialUSB.print("%  ");
  SerialUSB.print("temperature = ");
  SerialUSB.print(TempHumi.Temperature);
  SerialUSB.println("C");

  delay(INTERVAL);
}
