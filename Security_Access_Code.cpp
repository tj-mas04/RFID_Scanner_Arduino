#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define RST_PIN 9
#define SS_PIN 10
#define GreenLED 4  // Green LED pin
#define RedLED 3    // Red LED pin
#define Buzzer 5    // Buzzer pin

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

// Master RFID tags
String MasterTag1 = "D9 F5 BB 99";
String MasterTag2 = "39 94 89 65";

String UIDCard = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  servo.attach(6);  // Servo connected to pin 6
  servo.write(120); // Initial position

  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  // Welcome message
  lcd.print(" HELLO ");
  delay(2500);
  lcd.clear();
  lcd.print("SECURITY CONTROL");
  lcd.setCursor(0, 1);
  lcd.print("using RFID Tech");
  delay(2500);
  lcd.clear();
  lcd.print(" TO GAIN Access ");
  lcd.setCursor(0, 1);
  lcd.print("<Scan Your Card>");
}

void loop() {
  digitalWrite(RedLED, LOW);
  digitalWrite(GreenLED, LOW);
  noTone(Buzzer);
  servo.write(120); // Keep servo in locked position

  if (getUID()) {
    Serial.print("UID: ");
    Serial.println(UIDCard);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" SCANNING ");
    delay(500);

    // Check if the UID matches a Master Tag
    if (UIDCard == MasterTag1 || UIDCard == MasterTag2) {
      // Access granted
      lcd.clear();
      lcd.print("Access Granted->");
      digitalWrite(GreenLED, HIGH);
      digitalWrite(RedLED, LOW);
      servo.write(10); // Unlock servo

      // Buzzer feedback
      for (int i = 0; i < 2; i++) {
        tone(Buzzer, 2000);
        delay(250);
        noTone(Buzzer);
        delay(250);
      }

      delay(300);
      lcd.clear();
      lcd.print(" YOU MAY ");
      lcd.setCursor(0, 1);
      lcd.print(" WALK IN ");
      delay(2000);
    } else {
      // Access denied
      lcd.clear();
      lcd.print("Access Denied !!");
      digitalWrite(GreenLED, LOW);
      tone(Buzzer, 1000);
      servo.write(120); // Keep servo locked

      // Blink Red LED
      for (int i = 0; i < 6; i++) {
        digitalWrite(RedLED, HIGH);
        delay(250);
        digitalWrite(RedLED, LOW);
        delay(250);
      }
      noTone(Buzzer);
    }

    // Reset display after scan
    delay(700);
    lcd.clear();
    lcd.print(" TO GAIN Access ");
    lcd.setCursor(0, 1);
    lcd.print("<Scan Your Card>");
  }
}

boolean getUID() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return false;
  }

  // Construct the UID string
  UIDCard = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      UIDCard += "0"; // Add leading zero for single-digit hex values
    }
    UIDCard += String(mfrc522.uid.uidByte[i], HEX);
    if (i < mfrc522.uid.size - 1) {
      UIDCard += " "; // Add space between bytes
    }
  }

  UIDCard.toUpperCase(); // Convert to uppercase
  mfrc522.PICC_HaltA();  // Halt communication with the card
  return true;
}
