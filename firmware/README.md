# esp-pid-demo firmware

## Hardware

- **MCU board**: ESP32-EVB (Olimex), Arduino framework via PlatformIO.
- **Motor driver**: Cytron MDD10A REV2.0, dual-channel, PWM + DIR mode.
- **Motors**: 2x Wheeltec MG513P30 DC gearmotor (left + right wheel).
  - Gear ratio: 1:30.
  - Encoder: optical quadrature, 500 PPR (confirmed by manual calibration -
    not the 13 PPR Hall variant of the same model).
  - Effective resolution: 500 * 4 (quadrature x4) * 30 (gear ratio) = 60000
    counts/wheel-revolution in theory; measured ~61068-61883 counts/rev by
    hand-rotating the wheel. See `ENCODER_COUNTS_PER_REV` in
    `include/config.h`.

## Pinout

| Signal           | GPIO |
|------------------|------|
| Left motor PWM   | 25   |
| Left motor DIR   | 13   |
| Right motor PWM  | 26   |
| Right motor DIR  | 16   |
| Left encoder A   | 15   |
| Left encoder B   | 2    |
| Right encoder A  | 14   |
| Right encoder B  | 17   |

See `include/config.h` for pin definitions and tunable constants
(`MOTOR_PWM_MIN`/`MAX`, `ENCODER_COUNTS_PER_REV`).
