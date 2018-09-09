// BOARD Seeed Wio 3G
// GROVE UART <-> Grove - Speech Recognizer (SKU#101020232)

#include <MjGrove.h>

WioCellular Wio;

GroveBoard Board;
GroveSpeechRecognizer Speech(&Board.UART);

void MessageReceived(const char* message) {
  SerialUSB.println(message);
}

void setup() {
  delay(200);
#if !defined ARDUINO_STM32F4_WIO_GPS
  SerialUSB.begin(115200);
#endif

  Wio.Init();
  Wio.PowerSupplyGrove(true);
  delay(500);
  
  Board.UART.Enable();
  Speech.Init();
  
  Speech.AttachMessageReceived(MessageReceived);
}

void loop() {
  Speech.DoWork();
}
