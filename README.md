# ADC-and-PWM-drivers-developed-from-scratch-to-simulate-a-car-throttle-valve

Bare-Metal ATMega328P: ADC & PWM Drivers for Throttle Control

## 📌 Overview
This project implements **custom, from-scratch embedded drivers** for the ATMega328P microcontroller on the Arduino Uno board, simulating the behavior of an **automotive throttle body**.

Just like in a car:
- Turning the potentiometer is equivalent to pressing the accelerator pedal.
- The servo motor acts as the throttle plate, opening or closing based on the analog input value.

All code was written **from scratch**, without using the Arduino core libraries, to provide full control over the hardware at the **bare-metal** level.

---

## ⚙️ Features
- **ADC Driver** (`ADC.c`, `ADC.h`)  
  Reads analog values from a potentiometer using the microcontroller’s internal Analog-to-Digital Converter.
  
- **PWM Driver** (`SERVO.c`, `SERVO.h`)  
  Generates a PWM signal to control a servo motor’s position between 0° and 180°.

- **Bare-Metal Implementation**  
  No Arduino functions like `analogRead()` or `Servo.write()`. All registers are configured manually.

- **Makefile-based Build**  
  The project compiles and links using a Makefile, ensuring clean and reproducible builds.

---

## 🛠 Hardware Requirements
- Arduino Uno (ATMega328P)
- Potentiometer
- Servo motor (e.g., SG90 or similar)
- Jumper wires
- Breadboard

---

---

## 🔌 Wiring Diagram
| Component     | ATMega328P Pin |
|---------------|---------------|
| Potentiometer | ADC0 (PC0)    |
| Servo Signal  | PD5 (OC0B)    |
| Power (Vcc)   | 5V            |
| Ground (GND)  | GND           |

---

## 🚀 How to Build and Flash
1. **Compile the project**:
   ```bash
   make

## 📂 Project Structure
.
├── src
│ ├── ADC.c
│ ├── ADC.h
│ ├── SERVO.c
│ ├── SERVO.h
│ └── main.c
├── Makefile
└── README.md
