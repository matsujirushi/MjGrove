// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Button (SKU#101020003)

#include <MjGrove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveButton Button(&Board.D38);

void setup() {
  delay(200);
  SerialUSB.begin(115200);

  Board.D38.Enable();
  Button.Init();
}

void loop() {
  bool buttonState = Button.IsOn();
  SerialUSB.print(buttonState ? '*' : '.');
  
  delay(INTERVAL);
}

