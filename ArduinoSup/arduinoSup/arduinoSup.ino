#include <Servo.h>

Servo myservo;
int pos = 0;
bool isActive = false;
unsigned long previousMillis = 0;
const long interval = 5000; // 5 secondes

void setup() {
  Serial.begin(9600);
  myservo.attach(8); // Broche 9 pour le servo
  myservo.write(0); // Position initiale fermée
}

void loop() {
  // Gestion de la commande série
  if (Serial.available() > 0) {
    char command = Serial.read();
    
    if (command == '1' && !isActive) {
      // Ouvrir la porte
      for (pos = 0; pos <= 180; pos += 1) {
        myservo.write(pos);
        delay(15);
      }
      isActive = true;
      previousMillis = millis(); // Enregistrer le moment où la porte s'ouvre
    }
  }

  // Fermeture automatique après 5 secondes
  if (isActive && (millis() - previousMillis >= interval)) {
    // Fermer la porte
    for (pos = 180; pos >= 0; pos -= 1) {
      myservo.write(pos);
      delay(15);
    }
    isActive = false;
  }
}