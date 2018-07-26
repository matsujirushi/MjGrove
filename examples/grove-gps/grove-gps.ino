// BOARD Seeed Wio 3G
// GROVE UART <-> Grove - GPS (SKU#113020003)

#include <MjGrove.h>

WioCellular Wio;

GroveBoard Board;
GroveGPS GPS(&Board.UART);

void MessageReceived(const char* message) {
  SerialUSB.println(message);
}

void setup() {
  delay(200);
#if defined ARDUINO_WIO_3G
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);
  
  Board.UART.Enable();
  GPS.Init();
  
  GPS.AttachMessageReceived(MessageReceived);
}

void loop() {
  GPS.DoWork();
}

