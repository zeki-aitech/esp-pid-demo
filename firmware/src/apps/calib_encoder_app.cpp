// Encoder calibration app - measures ENCODER_COUNTS_PER_REV (config.h).
//
// Build & flash:  pio run -e calib_encoder -t upload -t monitor
//
// Procedure:
//   1. Flash this app and open the serial monitor. Motors stay stopped
//      (PWM=0) the whole time - safe to touch the wheels.
//   2. Rotate one wheel by hand, slowly, exactly 1 full revolution.
//      Pausing/regripping mid-turn is fine - the count only depends on
//      total rotation, not speed or continuity.
//   3. Wait for the printed count (L/R in the log) to stop changing -
//      that settled value is counts/revolution for that wheel.
//   4. Repeat for the other wheel.
//   5. For more precision: rotate N full revolutions (count out loud)
//      and divide the settled value by N instead of using N=1.
//   6. Update ENCODER_COUNTS_PER_REV in config.h with the result.
//
// Reference for the Wheeltec MG513P30 (1:30 gear ratio, optical
// encoder 500 PPR): measured ~61068-61883 counts/rev on the left wheel,
// matching the theoretical 500 * 4 * 30 = 60000 counts/rev.

#include <Arduino.h>
#include "config.h"
#include "motor.h"
#include "encoder.h"

Motor motor_left (MOTOR_LEFT_PWM,  MOTOR_LEFT_DIR,  0);
Motor motor_right(MOTOR_RIGHT_PWM, MOTOR_RIGHT_DIR, 1);

Encoder encoder_left (ENC_LEFT_A,  ENC_LEFT_B);
Encoder encoder_right(ENC_RIGHT_A, ENC_RIGHT_B);

extern void encoder_task(void *pvParameters);

void setup() {
    Serial.begin(115200);
    delay(500);

    motor_left.begin();
    motor_right.begin();

    encoder_left.begin();
    encoder_right.begin();

    ESP_LOGI("MAIN", "Encoder calibration - motors stopped, rotate wheels by hand");

    xTaskCreate(encoder_task, "encoder_task", 4096, nullptr, 1, nullptr);
}

void loop() {
    vTaskDelay(pdMS_TO_TICKS(1000));
}
