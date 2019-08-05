// BOARD Seeed Wio LTE M1/NB1(BG96)
// GROVE I2C <-> Grove - 16x2 LCD (SKU#104020111)

#include <MjGrove.h>

WioCellular Wio;

GroveBoard Board;
GroveLCD1602 Lcd(&Board.I2C);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  Lcd.Init();
  Lcd.SetCursor(0, 0);
  Lcd.print("GroveLCD1602");
}

void loop() {
  Lcd.SetCursor(0, 1);
  Lcd.print(millis() / 1000);
  delay(100);
}
