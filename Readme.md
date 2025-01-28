# RFID-Based Security System

## Overview

This project is an RFID-based security system that uses an **MFRC522 RFID reader**, **I2C LCD display**, a **servo motor**, and additional components like LEDs and a buzzer to control access to a secured area. When an RFID card is scanned, the system reads its UID and grants or denies access based on predefined authorized UIDs.

## Features

- Reads RFID cards using the MFRC522 module.
- Displays status messages on a 16x2 I2C LCD.
- Controls access with a servo motor (opens for authorized cards).
- Provides visual feedback using LEDs (Green for access granted, Red for access denied).
- Emits sound feedback using a buzzer.
- Predefined master RFID tags for access control.

## Components Required

- **Arduino Uno/Nano**
- **MFRC522 RFID Module**
- **16x2 I2C LCD Display**
- **Servo Motor**
- **Red LED**
- **Green LED**
- **Buzzer**
- **Jumper Wires**
- **Breadboard**

## Circuit Diagram

Connect the components as follows:

### RFID Module (MFRC522):

| RFID Pin | Arduino Pin |
|----------|-------------|
| SDA      | 10          |
| SCK      | 13          |
| MOSI     | 11          |
| MISO     | 12          |
| IRQ      | Not Connected |
| GND      | GND         |
| RST      | 9           |
| 3.3V     | 3.3V        |

### I2C LCD:

| LCD Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

### Servo Motor:

| Servo Pin | Arduino Pin |
|-----------|-------------|
| Signal    | 6           |
| VCC       | 5V          |
| GND       | GND         |

## Software Setup

1. **Install Arduino IDE:**
   Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Libraries Used:**
   - [MFRC522 Library](https://github.com/miguelbalboa/rfid): For RFID card communication.
   - [LiquidCrystal_I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C): For LCD control.

3. **Install the libraries via Arduino IDE:**
   - Open the Arduino IDE.
   - Go to **Tools > Manage Libraries**.
   - Search for `MFRC522` and `LiquidCrystal_I2C`.
   - Install them.

## Code

Copy and upload the provided Arduino code to your board using the Arduino IDE. The code includes predefined master RFID tags for access control. Modify these tags in the code as needed:

```cpp
String MasterTag1 = "D9 F5 BB 99";
String MasterTag2 = "39 94 89 65";
```

Replace the values with the UIDs of your authorized RFID cards.

## License

This project is open-source and licensed under the MIT License. Feel free to modify and share!
