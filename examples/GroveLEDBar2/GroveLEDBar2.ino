// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove LED Bar v2.0 (SKU#104020006)

#include <MjGrove.h>

GroveBoard Board;
GroveLEDBar2 Bar(&Board.D38);

void setup() {
  delay(200);

  Board.D38.Enable();
  Bar.Init();
}

void loop() {
  for (int j = 0; j <= 10; j++) {
    for (int i = 0; i < 10; i++) {
      Bar.SetBrightness(i, i < j ? 0.1 : 0);
    }
    Bar.Show();
    delay(200);
  }
}

