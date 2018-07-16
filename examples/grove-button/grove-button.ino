// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Button (SKU#101020003)

#if defined ARDUINO_WIO_3G
#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino
#else
#error "This board is not supported."
#endif
#include <Grove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveButton Button(&Board.D38);

void setup() {
  delay(200);

  SerialUSB.begin(115200);
}

void loop() {
  bool buttonState = Button.IsOn();
  SerialUSB.print(buttonState ? '*' : '.');
  
  delay(INTERVAL);
}
