#include <Arduino.h>
#include "config.h"
#include "motor.h"
#include "encoder.h"

Motor motor_left (MOTOR_LEFT_PWM,  MOTOR_LEFT_DIR,  0);
Motor motor_right(MOTOR_RIGHT_PWM, MOTOR_RIGHT_DIR, 1);

Encoder encoder_left (ENC_LEFT_A,  ENC_LEFT_B);
Encoder encoder_right(ENC_RIGHT_A, ENC_RIGHT_B);

extern void motor_task(void *pvParameters);

void setup() {
    Serial.begin(115200);
    delay(500);

    motor_left.begin();
    motor_right.begin();

    encoder_left.begin();
    encoder_right.begin();

    ESP_LOGI("MAIN", "Motor driver test - LEFT & RIGHT");

    xTaskCreate(motor_task, "motor_task", 4096, nullptr, 1, nullptr);
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000));
}
