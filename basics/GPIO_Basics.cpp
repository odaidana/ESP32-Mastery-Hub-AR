#include <Arduino.h>

// تحديد منافذ الهاردوير بشكل آمن وصحيح
#define INPUT_BUTTON_PIN  4
#define OUTPUT_LED_PIN    2

void setup() {
    // تشغيل نظام الاتصال السيريال السريع مع الكمبيوتر
    Serial.begin(115200);
    
    // إعداد وتجهيز منافذ الإدخال والإخراج في المعالج
    pinMode(OUTPUT_LED_PIN, OUTPUT);
    pinMode(INPUT_BUTTON_PIN, INPUT_PULLUP); // تفعيل المقاومة الداخلية لمنع تذبذب الإشارة
    
    Serial.println("[BOOT] Module 01: GPIO Subsystem initialized successfully.");
}

void loop() {
    // قراءة الحالة المنطقية الحالية لمنفذ الزر
    int buttonState = digitalRead(INPUT_BUTTON_PIN);
    
    if (buttonState == LOW) { // إذا تم الضغط على الزر (اتصل بالأرضي)
        digitalWrite(OUTPUT_LED_PIN, HIGH); // تشغيل الليد
        Serial.println("[GPIO] Input triggered: LED turned ON");
    } else {
        digitalWrite(OUTPUT_LED_PIN, LOW); // إطفاء الليد
    }
    delay(50); // تأخير برمجى بسيط لمنع قراءة الضغطات الوهمية
}
