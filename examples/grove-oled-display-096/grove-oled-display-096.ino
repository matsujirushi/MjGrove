// BOARD Seeed Wio 3G
// GROVE I2C <-> Grove - OLED Display 0.96" (SKU#104030008)

#include <MjGrove.h>

WioCellular Wio;

GroveBoard Board;
GroveOLEDDisplay096 Oled(&Board.I2C);

void setup() {
  delay(200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);

  Board.I2C.Enable();
  Oled.Init();
  Oled.Clear();
  Oled.write('H');
  Oled.write('e');
  Oled.write('l');
  Oled.write('l');
  Oled.write('o');
}

void loop() {
}
