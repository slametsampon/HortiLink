#include <Arduino.h>
#include "SmartControlLink.h"  // Definisi Pin
#include "src/LEDManager.h"    // Manajer LED

// Inisialisasi Objek LED
LEDManager ledNutrisiA(PIN_NUTRISI_A);
LEDManager ledNutrisiB(PIN_NUTRISI_B);
LEDManager ledAsam(PIN_ASAM);
LEDManager ledBasa(PIN_BASA);
LEDManager ledPompa(PIN_POMPA_SIRKULASI);

void setup() {
    Serial.begin(115200);

    // Inisialisasi LED
    ledNutrisiA.begin();
    ledNutrisiB.begin();
    ledAsam.begin();
    ledBasa.begin();
    ledPompa.begin();
}

void loop() {
    // Perbarui Status LED
    ledNutrisiA.update();
    ledNutrisiB.update();
    ledAsam.update();
    ledBasa.update();
    ledPompa.update();

    delay(100);  // Loop Refresh
}
