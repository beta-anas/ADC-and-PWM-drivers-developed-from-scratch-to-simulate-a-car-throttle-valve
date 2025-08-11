#include <avr/io.h>
#include "SERVO.h"

#define SERVO_PIN PD7
#define SERVO_PORT PORTD
#define SERVO_DDR DDRD

void delay_us_soft(uint16_t us) {
    while (us--) {
        // Environ 1 µs avec ce nombre d’instructions (à 16 MHz)
        asm volatile("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t"
                     "nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
    }
}

void servo_init(void) {
    SERVO_DDR |= (1 << SERVO_PIN); // D7 en sortie
}

void servo_set_angle(uint8_t angle) {
    // largeur impulsion entre 1000 et 2000 µs
    uint16_t pulse_width = 1000 + ((uint32_t)angle * 1000) / 180;

    // Générer l'impulsion
    SERVO_PORT |= (1 << SERVO_PIN);
    delay_us_soft(pulse_width);
    SERVO_PORT &= ~(1 << SERVO_PIN);
}
