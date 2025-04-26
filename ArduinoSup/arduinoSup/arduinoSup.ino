#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

#define LED_ROUGE 6
#define LED_VERTE 7

MFRC522 rfid(SS_PIN, RST_PIN);
String tagUID = "";

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_VERTE, OUTPUT);

  digitalWrite(LED_ROUGE, HIGH);  // LED rouge allumée par défaut
  digitalWrite(LED_VERTE, LOW);
}

void loop() {
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    tagUID = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      tagUID += String(rfid.uid.uidByte[i], HEX);
    }

    Serial.println(tagUID);  // envoie l’UID au PC
    delay(1000);
    rfid.PICC_HaltA();
  }

  if (Serial.available()) {
    char etat = Serial.read(); // Qt envoie '1' ou '0'
    if (etat == '1') {
      digitalWrite(LED_VERTE, HIGH);
      digitalWrite(LED_ROUGE, LOW);
    } else {
      digitalWrite(LED_VERTE, LOW);
      digitalWrite(LED_ROUGE, HIGH);
    }
  }
}
