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
  SerialUSB.begin(115200);

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);
  
  Board.UART.Enable(9600, 8, HalUART::PARITY_NONE, 1);
  GPS.Init();
  
  GPS.AttachMessageReceived(MessageReceived);
}

void loop() {
  GPS.DoWork();
}

