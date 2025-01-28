#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);
String UIDCard = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan your RFID Card:");
  for (int i = 0; i < 20; i++) {
    Serial.print(".");
    delay(50);
  }
  Serial.println("");
}

void loop() {
  // Wait until a new tag is available
  if (getUID()) {
    Serial.print("UID: ");
    Serial.println(UIDCard);
    for (int i = 0; i < 20; i++) {
      Serial.print(".");
      delay(50);
    }
    delay(3000); // Delay for 3 seconds before scanning again
  }
}

boolean getUID() {
  // Check if a new card is present
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return false;
  }

  // Try to read the card
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
  }

  UIDCard.toUpperCase(); // Convert UID to uppercase
  mfrc522.PICC_HaltA();  // Halt communication with the card
  return true;
}
