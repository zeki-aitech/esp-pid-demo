#include <Arduino.h>
#include "esp_log.h"

static const char *TAG = "main";

void setup() {
  Serial.begin(115200);
  delay(500);  
  ESP_LOGI(TAG, "Setup done");
}

void loop() {
  ESP_LOGI(TAG, "Hello, World!");
  delay(1000);
}
