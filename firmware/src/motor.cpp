#include "motor.h"
#include "config.h"

Motor::Motor(uint8_t pwm_pin, uint8_t dir_pin, uint8_t ledc_channel)
    : pwm_pin_(pwm_pin), dir_pin_(dir_pin), ledc_channel_(ledc_channel) {}

void Motor::begin() {
    pinMode(dir_pin_, OUTPUT);
    digitalWrite(dir_pin_, LOW);

    ledcSetup(ledc_channel_, 20000, 8);      // 20 kHz, 8-bit
    ledcAttachPin(pwm_pin_, ledc_channel_);
    ledcWrite(ledc_channel_, 0);
}

void Motor::setSpeed(int speed) {
    if (speed > MOTOR_PWM_MAX) speed = MOTOR_PWM_MAX;
    if (speed < -MOTOR_PWM_MAX) speed = -MOTOR_PWM_MAX;

    // Any nonzero command is bumped up to MOTOR_PWM_MIN so it clears
    // stiction instead of silently doing nothing below that duty.
    if (speed > 0 && speed < MOTOR_PWM_MIN) speed = MOTOR_PWM_MIN;
    if (speed < 0 && speed > -MOTOR_PWM_MIN) speed = -MOTOR_PWM_MIN;

    // DIR HIGH decreased the count during the digital test, so that
    // direction is treated as "negative" and inverted here: speed > 0 = forward
    if (speed >= 0) {
        digitalWrite(dir_pin_, LOW);
        ledcWrite(ledc_channel_, (uint32_t)speed);
    } else {
        digitalWrite(dir_pin_, HIGH);
        ledcWrite(ledc_channel_, (uint32_t)(-speed));
    }
}

void Motor::stop() {
    ledcWrite(ledc_channel_, 0);
}