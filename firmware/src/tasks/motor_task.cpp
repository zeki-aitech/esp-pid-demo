#include <Arduino.h>
#include "motor.h"
#include "encoder.h"
#include "config.h"

extern Motor motor_left;
extern Motor motor_right;
extern Encoder encoder_right;

static const uint32_t RUN_MS = 3000;

static void logSpeed(const char *label) {
    int32_t counts = encoder_right.getCount();
    int32_t counts_per_sec = counts * 1000 / (int32_t)RUN_MS;
    ESP_LOGI("MOTOR", "%s: %ld counts / %lums -> %ld counts/s", label, (long)counts, (unsigned long)RUN_MS, (long)counts_per_sec);
}

void motor_task(void *pvParameters) {
    ESP_LOGI("MOTOR", "Test RIGHT only");
    motor_left.stop();

    while (true) {
        ESP_LOGI("MOTOR", "Right Forward");
        encoder_right.reset();
        motor_right.setSpeed(100);
        vTaskDelay(pdMS_TO_TICKS(RUN_MS));
        logSpeed("Right Forward");

        ESP_LOGI("MOTOR", "Right Stop");
        motor_right.stop();
        vTaskDelay(pdMS_TO_TICKS(1500));

        ESP_LOGI("MOTOR", "Right Backward");
        encoder_right.reset();
        motor_right.setSpeed(-100);
        vTaskDelay(pdMS_TO_TICKS(RUN_MS));
        logSpeed("Right Backward");

        motor_right.stop();
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}