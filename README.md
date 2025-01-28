<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>RFID-Based Security System</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0;
            padding: 0 20px;
            background-color: #f9f9f9;
        }
        h1, h2, h3 {
            color: #333;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border: 1px solid #ddd;
            overflow-x: auto;
        }
        code {
            background-color: #f4f4f4;
            padding: 2px 4px;
            border-radius: 4px;
        }
        ul {
            margin: 10px 0;
            padding-left: 20px;
        }
        .license {
            margin-top: 30px;
            font-size: 0.9em;
            color: #555;
        }
    </style>
</head>
<body>
    <h1>RFID-Based Security System</h1>
  
    <h2>Overview</h2>
    <p>
        This project is an RFID-based security system that uses an <strong>MFRC522 RFID reader</strong>,
        <strong>I2C LCD display</strong>, a <strong>servo motor</strong>, and additional components like LEDs and a buzzer
        to control access to a secured area. When an RFID card is scanned, the system reads its UID and grants or denies
        access based on predefined authorized UIDs.
    </p>

    <h2>Features</h2>
    <ul>
        <li>Reads RFID cards using the MFRC522 module.</li>
        <li>Displays status messages on a 16x2 I2C LCD.</li>
        <li>Controls access with a servo motor (opens for authorized cards).</li>
        <li>Provides visual feedback using LEDs (Green for access granted, Red for access denied).</li>
        <li>Emits sound feedback using a buzzer.</li>
        <li>Predefined master RFID tags for access control.</li>
    </ul>

    <h2>Components Required</h2>
    <ul>
        <li><strong>Arduino Uno/Nano</strong></li>
        <li><strong>MFRC522 RFID Module</strong></li>
        <li><strong>16x2 I2C LCD Display</strong></li>
        <li><strong>Servo Motor</strong></li>
        <li><strong>Red LED</strong></li>
        <li><strong>Green LED</strong></li>
        <li><strong>Buzzer</strong></li>
        <li><strong>Jumper Wires</strong></li>
        <li><strong>Breadboard</strong></li>
    </ul>

    <h2>Circuit Diagram</h2>
    <p>Connect the components as follows:</p>

    <h3>RFID Module (MFRC522):</h3>
    <table border="1" cellpadding="5" cellspacing="0">
        <thead>
            <tr>
                <th>RFID Pin</th>
                <th>Arduino Pin</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>SDA</td>
                <td>10</td>
            </tr>
            <tr>
                <td>SCK</td>
                <td>13</td>
            </tr>
            <tr>
                <td>MOSI</td>
                <td>11</td>
            </tr>
            <tr>
                <td>MISO</td>
                <td>12</td>
            </tr>
            <tr>
                <td>IRQ</td>
                <td>Not Connected</td>
            </tr>
            <tr>
                <td>GND</td>
                <td>GND</td>
            </tr>
            <tr>
                <td>RST</td>
                <td>9</td>
            </tr>
            <tr>
                <td>3.3V</td>
                <td>3.3V</td>
            </tr>
        </tbody>
    </table>

    <h3>I2C LCD:</h3>
    <table border="1" cellpadding="5" cellspacing="0">
        <thead>
            <tr>
                <th>LCD Pin</th>
                <th>Arduino Pin</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>VCC</td>
                <td>5V</td>
            </tr>
            <tr>
                <td>GND</td>
                <td>GND</td>
            </tr>
            <tr>
                <td>SDA</td>
                <td>A4</td>
            </tr>
            <tr>
                <td>SCL</td>
                <td>A5</td>
            </tr>
        </tbody>
    </table>

    <h3>Servo Motor:</h3>
    <table border="1" cellpadding="5" cellspacing="0">
        <thead>
            <tr>
                <th>Servo Pin</th>
                <th>Arduino Pin</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Signal</td>
                <td>6</td>
            </tr>
            <tr>
                <td>VCC</td>
                <td>5V</td>
            </tr>
            <tr>
                <td>GND</td>
                <td>GND</td>
            </tr>
        </tbody>
    </table>

    <h2>Software Setup</h2>
    <ol>
        <li>
            <strong>Install Arduino IDE:</strong> Download and install the
            <a href="https://www.arduino.cc/en/software">Arduino IDE</a>.
        </li>
        <li>
            <strong>Libraries Used:</strong>
            <ul>
                <li><a href="https://github.com/miguelbalboa/rfid">MFRC522 Library</a>: For RFID card communication.</li>
                <li><a href="https://github.com/johnrickman/LiquidCrystal_I2C">LiquidCrystal_I2C Library</a>: For LCD control.</li>
            </ul>
        </li>
        <li>
            Install the libraries via Arduino IDE:
            <ul>
                <li>Open the Arduino IDE.</li>
                <li>Go to <strong>Tools > Manage Libraries</strong>.</li>
                <li>Search for <code>MFRC522</code> and <code>LiquidCrystal_I2C</code>.</li>
                <li>Install them.</li>
            </ul>
        </li>
    </ol>

    <h2>Code</h2>
    <p>Copy and upload the provided Arduino code to your board using the Arduino IDE. The code includes predefined master RFID tags for access control. Modify these tags in the code as needed:</p>
    <pre><code>String MasterTag1 = "D9 F5 BB 99";
String MasterTag2 = "39 94 89 65";</code></pre>
    <p>Replace the values with the UIDs of your authorized RFID cards.</p>

    <h2>License</h2>
    <p class="license">This project is open-source and licensed under the MIT License. Feel free to modify and share!</p>
</body>
</html>
