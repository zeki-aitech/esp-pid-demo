#include <Arduino.h>
#include "encoder.h"
#include "config.h"

extern Encoder encoder_left;
extern Encoder encoder_right;

void encoder_task(void *pvParameters) {
    ESP_LOGI("ENC", "Encoder task started");

    int32_t last_left = 0;
    int32_t last_right = 0;

    while (true) {
        int32_t left  = encoder_left.getCount();
        int32_t right = encoder_right.getCount();

        if (left != last_left || right != last_right) {
            ESP_LOGI("ENC", "L: %ld | R: %ld", left, right);
            last_left = left;
            last_right = right;
        }

        vTaskDelay(pdMS_TO_TICKS(50));  // 20 Hz
    }
}