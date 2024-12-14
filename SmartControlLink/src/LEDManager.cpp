// LEDManager.cpp
#include "LEDManager.h"

// Konstruktor
LEDManager::LEDManager(int pin) 
    : ledPin(pin), status(CONNECTED), lastToggleTime(0), ledState(false) {}

// Inisialisasi LED
void LEDManager::begin() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);  // Matikan LED saat mulai
}

// Mengatur status LED
void LEDManager::setStatus(LEDStatus newStatus) {
    status = newStatus;
}

// Mendapatkan status LED saat ini
LEDStatus LEDManager::getStatus() {
    return status;
}

// Memperbarui LED sesuai status
void LEDManager::update() {
    unsigned long currentMillis = millis();

    switch (status) {
        case CONNECTED:
            digitalWrite(ledPin, HIGH);  // Nyala terus
            break;

        case ALARM:
            if (currentMillis - lastToggleTime >= ALARM_BLINK_INTERVAL) {
                ledState = !ledState;
                digitalWrite(ledPin, ledState ? HIGH : LOW);
                lastToggleTime = currentMillis;
            }
            break;

        case ERROR:
            if (currentMillis - lastToggleTime >= ERROR_BLINK_INTERVAL) {
                ledState = !ledState;
                digitalWrite(ledPin, ledState ? HIGH : LOW);
                lastToggleTime = currentMillis;
            }
            break;
    }
}
