#include <avr/io.h>
#include "ADC.h"

void adc_init(void) {
    ADMUX = (1 << REFS0); // Référence AVCC
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Activer + prescaler
}

uint16_t adc_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // Canal
    ADCSRA |= (1 << ADSC); // Démarrer conversion
    while (ADCSRA & (1 << ADSC)); // Attente
    return ADC;
}
