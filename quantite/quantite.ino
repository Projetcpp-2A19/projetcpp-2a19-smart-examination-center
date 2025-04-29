#include <TM1637Display.h>

#define CLK 7
#define DIO 6

#define BUTTON_RIGHT 2
#define BUTTON_LEFT 1
#define LED_GREEN 4
#define LED_RED 5

TM1637Display display(CLK, DIO);

// Variables pour recevoir série
String receivedData = "";
bool newDataAvailable = false;

void setup() {
    Serial.begin(9600);

    pinMode(BUTTON_RIGHT, INPUT_PULLUP);
    pinMode(BUTTON_LEFT, INPUT_PULLUP);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);


    display.setBrightness(5);
    display.showNumberDec(0);  // Affiche 0 au départ
}

void loop() {
    // Lire le port série
    while (Serial.available() > 0) {
        char receivedChar = Serial.read();
        if (receivedChar == '\n') {
            newDataAvailable = true;
        } else {
            receivedData += receivedChar;
        }
    }

    if (newDataAvailable) {
        if (receivedData.startsWith("SOMME:")) {
            String sommeStr = receivedData.substring(6);  // Après "SOMME:"
            int somme = sommeStr.toInt();

            display.showNumberDec(somme);  // Affiche la somme sur 7 segments

            Serial.println("✅ Somme reçue et affichée !");
        } else {
            Serial.println("❌ Donnée inattendue reçue:" + receivedData);
        }

        // Reset
        receivedData = "";
        newDataAvailable = false;
    }
}
