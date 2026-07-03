#include <Arduino.h>

// تحديد منفذ المحول التناظري الرقمي (ADC) لقراءة الحساسات
#define ANALOG_INPUT_PIN 34

void setup() {
    Serial.begin(115200);
    
    // ضبط دقة القراءة الخاصة بمعالج الـ ESP32
    analogReadResolution(12); // القراءة بدقة 12 بت تعطي قيم بين (0 و 4095)
    
    Serial.println("[BOOT] Module 03: Analog-to-Digital Converter active.");
}

void loop() {
    // سحب وقراءة القيمة الخام الحالية من المنفذ
    int rawAnalogValue = analogRead(ANALOG_INPUT_PIN);
    
    // تحويل القيمة الرقمية الخام إلى قيمة جهد حقيقية بالفولت
    float calculatedVoltage = (rawAnalogValue * 3.3) / 4095.0;
    
    // طباعة البيانات وإرسالها إلى شاشة الـ Serial Monitor
    Serial.print("[ADC] Raw Value: ");
    Serial.print(rawAnalogValue);
    Serial.print(" | Calibrated Voltage: ");
    Serial.println(calculatedVoltage);
    
    delay(1000); // تحديث القراءات كل ثانية واحدة
}
