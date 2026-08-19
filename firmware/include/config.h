#pragma once

#include <Arduino.h>

// Left wheel encoder (quadrature A/B)
#define ENC_LEFT_A  15
#define ENC_LEFT_B  2

// Right wheel encoder (quadrature A/B)
#define ENC_RIGHT_A 14
#define ENC_RIGHT_B 17

// Left motor (Cytron PWM + DIR)
#define MOTOR_LEFT_PWM  25 //10
#define MOTOR_LEFT_DIR  13

// Right motor (Cytron PWM + DIR)
#define MOTOR_RIGHT_PWM 26 //9
#define MOTOR_RIGHT_DIR 16

// PWM range (8-bit LEDC, 0-255).
// MOTOR_PWM_MIN is the minimum duty needed to overcome stiction and
// actually turn the wheel - tune by testing (100 was too low, 180 worked).
#define MOTOR_PWM_MIN 140
#define MOTOR_PWM_MAX 255

// Wheeltec MG513P30 gearmotor: 1:30 gear ratio, optical encoder (500 PPR).
// Theoretical: 500 PPR * 4 (quadrature x4) * 30 (gear ratio) = 60000 counts/rev.
// Measured by hand-rotating the wheel exactly 1 revolution: ~61068-61883
// counts (matches the optical variant, not the 13 PPR Hall variant).
// Refine with more measurements if precision matters for PID tuning.
#define ENCODER_COUNTS_PER_REV 61475
