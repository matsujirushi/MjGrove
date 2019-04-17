#include <MjGrove.h>

////////////////////////////////////////////////////////////////////////////////
// Defines

#define BOOT_INTERVAL   (60)  // [sec.]

////////////////////////////////////////////////////////////////////////////////
// Global variables

WioCellular Wio;

GroveBoard Board;
WioExtRTC ExtRTC(&Board.I2C);

////////////////////////////////////////////////////////////////////////////////
// setup and loop

void setup()
{
  delay(200);
  delay(3000);

  SerialUSB.begin(115200);
  SerialUSB.println("");
  SerialUSB.println("--- START ---------------------------------------------------");

  ////////////////////////////////////////
  // Low-level initialize

  SerialUSB.println("### I/O Initialize.");
  Wio.Init();

  SerialUSB.println("### Power supply ON.");
  Wio.PowerSupplyGrove(true);
  delay(500);
  
  ////////////////////////////////////////
  // Device initialize
  
  SerialUSB.println("### Device initialize.");
  Board.I2C.Enable();
  ExtRTC.Init();

  ////////////////////////////////////////
  // Completed

  SerialUSB.println("### Completed.");
}

void loop()
{
  uint8_t val;
  ExtRTC.Eeprom.Read(0, &val, sizeof(val));
  SerialUSB.print("EEPROM value is ");
  SerialUSB.println(val);
  
  val++;
  ExtRTC.Eeprom.Write(0, &val, sizeof(val));
  
  SerialUSB.println("Shutdown.");
  ExtRTC.SetWakeupPeriod(BOOT_INTERVAL);
  ExtRTC.Shutdown();
  while (1) {}
}

////////////////////////////////////////////////////////////////////////////////
