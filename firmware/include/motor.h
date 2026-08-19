#pragma once
#include <Arduino.h>

class Motor {
public:
    Motor(uint8_t pwm_pin, uint8_t dir_pin, uint8_t ledc_channel);

    void begin();
    void setSpeed(int speed);   // -255 ~ 255
    void stop();

private:
    uint8_t pwm_pin_;
    uint8_t dir_pin_;
    uint8_t ledc_channel_;
};