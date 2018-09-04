// BOARD Seeed Wio 3G
// GROVE D38 <-> Grove - Touch Sensor (SKU#101020037)

#include <MjGrove.h>

#define INTERVAL    (100)

GroveBoard Board;
GroveTouch Touch(&Board.D38);

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Board.D38.Enable();
  Touch.Init();
}

void loop() {
  bool touchState = Touch.IsOn();
  SerialUSB.print(touchState ? '*' : '.');
  
  delay(INTERVAL);
}
