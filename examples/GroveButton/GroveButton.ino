// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Button (SKU#101020003)

#include <MjGrove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveButton Button(&Board.D38);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Board.D38.Enable();
  Button.Init();
}

void loop() {
  bool buttonState = Button.IsOn();
  SerialUSB.print(buttonState ? '*' : '.');
  
  delay(INTERVAL);
}

