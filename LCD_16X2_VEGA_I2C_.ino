/*
  ARIES v3.0 + Grove 16x2 LCD
  I2C  : I2C-1
  Addr : 0x3E
  Using rgb_lcd.h library
  Based on Seeed Studio Grove LCD series
*/

#include <Wire.h>

// Bind default Wire to I2C-1
TwoWire Wire(1);

#include "rgb_lcd.h"

rgb_lcd lcd;

void setup()
{
    Serial.begin(115200);

    // Start I2C1
    Wire.begin();

    // Initialize LCD: 16 columns, 2 rows
    lcd.begin(16, 2);

    // Display welcome text
    lcd.setCursor(0, 0);
    lcd.print("Grove LCD Found!");
    lcd.setCursor(0, 1);
    lcd.print("Addr: 0x3E");

    delay(2000);
}

void loop()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hello from ARIES");
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(millis() / 1000);

    delay(2000);
}
