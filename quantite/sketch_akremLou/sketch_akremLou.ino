#include <TM1637Display.h>

#define CLK 7
#define DIO 6

#define BUTTON_RIGHT 2
#define BUTTON_LEFT 1
#define LED_GREEN 4
#define LED_RED 5

TM1637Display display(CLK, DIO);

int quantite = 0;
unsigned long lastActionTime = 0;
unsigned long inactivityTimeout = 10000;


// Variables for reading serial data safely
String receivedData = "";
bool newDataAvailable = false;

void setup() {
    Serial.begin(9600);

    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);

    display.setBrightness(5);
    display.showNumberDec(quantite);
}

void loop() {
    unsigned long currentMillis = millis();

    // Buttons logic stays the same
    if (digitalRead(BUTTON_LEFT) == LOW) {
        delay(50);
        if (digitalRead(BUTTON_LEFT) == LOW) {
            quantite--;
            digitalWrite(LED_RED, HIGH);
            delay(200);
            digitalWrite(LED_RED, LOW);
            display.showNumberDec(quantite);
            lastActionTime = currentMillis;
            while (digitalRead(BUTTON_LEFT) == LOW);
        }
    }

    if (digitalRead(BUTTON_RIGHT) == LOW) {
        delay(50);
        if (digitalRead(BUTTON_RIGHT) == LOW) {
            quantite++;
            digitalWrite(LED_GREEN, HIGH);
            delay(200);
            digitalWrite(LED_GREEN, LOW);
            display.showNumberDec(quantite);
            lastActionTime = currentMillis;
            while (digitalRead(BUTTON_RIGHT) == LOW);
        }
    }

    if (currentMillis - lastActionTime >= inactivityTimeout) {
        Serial.print("QUANTITE:");
        Serial.println(quantite);
        lastActionTime = currentMillis;
    }
    // 🆕 New Serial reading
    while (Serial.available() > 0) {
        char receivedChar = Serial.read();
        if (receivedChar == '\n') {
            newDataAvailable = true;  // End of message
        } else {
            receivedData += receivedChar;  // Add char to string
        }
    }

    if (newDataAvailable) {
        if (receivedData.startsWith("NOUVELLE_QUANTITE:")) {
            String quantiteStr = receivedData.substring(18);
            int nouvelleQuantite = quantiteStr.toInt();

            quantite = nouvelleQuantite;
            display.showNumberDec(quantite);

            Serial.println("Nouvelle quantité reçue et affichée !");

            // 🛠 ADD THIS LINE:
            //quantite = 0;
        }
        // Reset
        receivedData = "";
        newDataAvailable = false;
    }
}














/*
    // 🆕 New Serial reading
    while (Serial.available() > 0) {
        char receivedChar = Serial.read();
        if (receivedChar == '\n') {
            newDataAvailable = true;  // End of message
        } else {
            receivedData += receivedChar;  // Add char to string
        }
    }

    if (newDataAvailable) {
        if (receivedData.startsWith("NOUVELLE_QUANTITE:")) {
            String quantiteStr = receivedData.substring(18);
            int nouvelleQuantite = quantiteStr.toInt();

            quantite = nouvelleQuantite;
            display.showNumberDec(quantite);

            Serial.println("Nouvelle quantité reçue et affichée !");

            // 🛠 ADD THIS LINE:
            quantite = 0;
        }
        // Reset
        receivedData = "";
        newDataAvailable = false;
    }
    */