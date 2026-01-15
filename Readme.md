Grove 16x2 LCD Interfacing with ARIES Board
1. Introduction

This document explains how to interface the Grove – 16x2 LCD (I2C based) with the ARIES development board using the Arduino IDE. It covers hardware connections, I2C details, software setup, and a working example.

The Grove 16x2 LCD uses an I2C interface and is supported by the rgb_lcd library provided by Seeed Studio.

2. Hardware Requirements

ARIES Development Board (v2.0 / v3.0)

Grove – 16x2 LCD module

Grove I2C cable

USB cable for programming

3. LCD Overview

Display: 16 columns × 2 rows

Interface: I2C

Default I2C Address: 0x3E

Operating Voltage: 3.3V / 5V

Official reference: https://wiki.seeedstudio.com/Grove-16x2_LCD_Series/

4. Pin Connections
Using Grove I2C Port (Recommended)

Simply connect the Grove LCD to the Grove I2C port on the ARIES board using a Grove cable.

Grove LCD Pin	ARIES Board
VCC	3.3V / 5V
GND	GND
SDA	SDA (I2C)
SCL	SCL (I2C)

Note: No manual pin wiring is required when using the Grove connector.

5. I2C Bus Information (Important)

ARIES boards support multiple I2C buses.

The Grove LCD in this setup was detected on I2C Bus 1.

I2C Scanner output confirmed the device at address 0x3E.

Example scanner output:

/*
 ARIES + Grove 16x2 LCD (Library-based)
 I2C Bus : I2C-1
 Address : 0x3E
*/


#include <Wire.h>


// Bind default Wire to I2C-1
TwoWire Wire(1);


#include "rgb_lcd.h"


rgb_lcd lcd;


void setup()
{
    Serial.begin(115200);


    // Start I2C communication
    Wire.begin();


    // Initialize LCD
    lcd.begin(16, 2);


    lcd.setCursor(0, 0);
    lcd.print("ARIES Board");
    lcd.setCursor(0, 1);
    lcd.print("Grove LCD OK");


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

Therefore, the default Wire object must be explicitly bound to I2C-1 in the code.

6. Software Requirements
Arduino IDE

Version: 1.8.19 (recommended)

Board Package

ARIES / VEGA board package installed

Required Library

Install the following library using Arduino Library Manager:

Grove LCD RGB Backlight (by Seeed Studio)

Note: Even though the LCD is non-RGB, this library is still required.

7. Example Code (Library-based, Tested)
/*
 ARIES + Grove 16x2 LCD
 I2C Bus : I2C-1
 Address : 0x3E
*/


8. Example Code (Low-level / Register-based – RGB Supported)

This project also includes a low-level implementation of the Grove 16x2 RGB LCD without using the rgb_lcd library. It directly controls:

LCD controller at 0x3E

RGB backlight controller at 0x62

Key Features

Direct I2C register access

Full LCD command set implementation

RGB backlight color control

No external LCD library dependency

I2C Addresses Used
Device	I2C Address
LCD Controller	0x3E
RGB Controller	0x62
Notes

Uses Wire I2C interface

Suitable for driver development, teaching, and understanding LCD internals

Recommended for advanced users

9. Working Description

LCD initializes in 16x2 mode

Displays a welcome message

Continuously updates system uptime in seconds

10. Common Issues and Troubleshooting
Issue	Possible Cause	Solution
Blank display	Wrong I2C bus	Use TwoWire Wire(1)
No text	Library missing	Install Grove LCD RGB Backlight
Compilation error	Wire undefined	Explicitly define TwoWire Wire(x)
Garbled text	Power issue	Check Grove cable & supply
11. Key Points (For Viva / Interview)

Grove 16x2 LCD uses I2C communication

Default I2C address is 0x3E

ARIES requires explicit I2C bus binding

rgb_lcd library is used for control

12. Conclusion

This document demonstrates successful interfacing of a Grove 16x2 LCD with the ARIES development board using I2C communication. The setup is suitable for beginners and can be extended for sensor data display, IoT dashboards, and embedded system demonstrations.

Author: Ganesh
Platform: ARIES Development Board
IDE: Arduino IDE
