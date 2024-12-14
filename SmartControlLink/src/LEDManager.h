// LEDManager.h
#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include <Arduino.h>

// Enum Status LED
enum LEDStatus {
    CONNECTED,  // Nyala terus
    ALARM,      // Berkedip 1 kali per detik
    ERROR       // Berkedip 2 kali per detik
};

class LEDManager {
private:
    int ledPin;                    // Pin yang digunakan untuk LED
    LEDStatus status;              // Status LED saat ini
    unsigned long lastToggleTime;  // Waktu terakhir LED toggle
    bool ledState;                 // Status ON/OFF LED

    // Konstanta untuk waktu kedip dalam milidetik
    const unsigned long ALARM_BLINK_INTERVAL = 1000;  // 1 detik untuk ALARM
    const unsigned long ERROR_BLINK_INTERVAL = 500;   // 0,5 detik untuk ERROR

public:
    // Konstruktor
    LEDManager(int pin);

    // Inisialisasi LED
    void begin();

    // Mengatur status LED
    void setStatus(LEDStatus newStatus);

    // Mendapatkan status LED saat ini
    LEDStatus getStatus();

    // Memperbarui LED sesuai status
    void update();
};

#endif // LEDMANAGER_H
