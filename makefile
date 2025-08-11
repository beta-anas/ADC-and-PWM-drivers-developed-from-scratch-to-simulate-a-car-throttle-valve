main: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

main.elf: main.o ADC.o SERVO.o
	avr-gcc -mmcu=atmega328p -o main.elf main.o ADC.o SERVO.o

main.o: main.c ADC.h SERVO.h
	avr-gcc -c -mmcu=atmega328p -DF_CPU=16000000UL -Os main.c

ADC.o: ADC.c ADC.h
	avr-gcc -c -mmcu=atmega328p -DF_CPU=16000000UL -Os ADC.c

SERVO.o: SERVO.c SERVO.h
	avr-gcc -c -mmcu=atmega328p -DF_CPU=16000000UL -Os SERVO.c

upload: main.hex
	avrdude -c arduino -p m328p -P COM28 -b 115200 -U flash:w:main.hex:i

clean:
	del *.o *.elf *.hex