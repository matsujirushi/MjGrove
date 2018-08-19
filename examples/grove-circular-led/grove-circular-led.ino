// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Circular LED (SKU#104030013)

#include <MjGrove.h>

GroveBoard Board;
GroveCircularLED Circular(&Board.D38);

void setup() {
  delay(200);

  Board.D38.Enable();
  Circular.Init();
}

void loop() {
  for (int j = 0; j <= 24; j++) {
    for (int i = 0; i < 24; i++) {
      Circular.SetBrightness(i, i < j ? 0.1 : 0);
    }
    Circular.Show();
    delay(200);
  }
}

