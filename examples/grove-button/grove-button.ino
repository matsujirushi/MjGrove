#include <Wio3GforArduino.h>  // https://github.com/SeeedJP/Wio_3G_for_Arduino
#include <Grove.h>

#define INTERVAL    (100)

GroveConnectorDIO D38(38, 39);

void setup() {
  SerialUSB.begin(115200);
  
  D38.P1().SetMode(GroveGpio::MODE_INPUT);
}

void loop() {
  bool buttonState = D38.P1().Read();
  SerialUSB.print(buttonState ? '*' : '.');
  
  delay(INTERVAL);
}

