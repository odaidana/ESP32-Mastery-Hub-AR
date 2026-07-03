#include <Arduino.h>

// تحديد منفذ الليد المستهدف
#define PWM_LED_PIN 5

// إعداد قنوات الـ PWM الخاصة ببنية معالج الـ ESP32
const int pwmChannel   = 0;
const int pwmFrequency = 5000; // ضبط التردد على 5 كيلو هرتز
const int pwmResolution = 8;    // دقة الإشارة 8 بت (من 0 إلى 255 خطوة)

void setup() {
    Serial.begin(115200);
    
    // ربط إعدادات القناة مع منفذ الـ PWM في الهاردوير
    ledcAttachChannel(PWM_LED_PIN, pwmFrequency, pwmResolution, pwmChannel);
    
    Serial.println("[BOOT] Module 02: Hardware PWM Architecture loaded.");
}

void loop() {
    // زيادة شدة الإشارة تدريجياً (رفع السطوع)
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
        ledcWrite(PWM_LED_PIN, dutyCycle);
        delay(5);
    }
    
    Serial.println("[PWM] Peak duty cycle reached.");
    delay(500);
    
    // تقليل شدة الإشارة تدريجياً (خفض السطوع)
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
        ledcWrite(PWM_LED_PIN, dutyCycle);
        delay(5);
    }
    
    Serial.println("[PWM] Zero duty cycle reached.");
    delay(500);
}
