#include "encoder.h"

Encoder::Encoder(uint8_t pin_a, uint8_t pin_b)
    : pin_a_(pin_a), pin_b_(pin_b) {
}

void Encoder::begin() {
    ESP32Encoder::useInternalWeakPullResistors = puType::up;
    encoder_.attachFullQuad(pin_a_, pin_b_);
    encoder_.setFilter(1023);  // max PCNT glitch filter (~12.8us) to reject motor EMI noise
    encoder_.clearCount();
}

int32_t Encoder::getCount() {
    return encoder_.getCount();
}

void Encoder::reset() {
    encoder_.clearCount();
}