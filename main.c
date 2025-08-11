#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "SERVO.h"

int main(void) {
    adc_init();
    servo_init();

    while (1) {
        uint16_t adc_val = adc_read(0); // Lire le potentiomètre
        uint8_t angle = (adc_val * 180UL) / 1023; // Conversion en angle
        servo_set_angle(angle); // Déclencher une impulsion pour l’angle
        _delay_ms(20); // Attendre la période (20 ms)
    }
}