// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - 4-Digit Display (SKU#104030003)

#include <MjGrove.h>

#define INTERVAL    (100)

GroveBoard Board;
Grove4DigitDisplay Display(&Board.D38);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Board.D38.Enable();
  Display.Init();
}

void loop() {
  for (int i = 0; i <= 9999; i++) {
    Display.print(i);
    delay(INTERVAL);
  }
}
