#pragma once

#include <Arduino.h>
#include <ESP32Encoder.h>

class Encoder {
public:
    Encoder(uint8_t pin_a, uint8_t pin_b);

    void begin();
    int32_t getCount();       
    void reset();

private:
    ESP32Encoder encoder_;
    uint8_t pin_a_;
    uint8_t pin_b_;
};