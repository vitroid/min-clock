# A simple mechanical clock engine for Arduino

This repository serves a clock engine that turn a stepping motor one cycle per a minute or an hour.

## Requirements

###  Hardware

* Arduino
* DS3231 clock module
* ULN2003 stepper motor
* Contack switch (option, for fast winding)

### Software modules for Arduino

* DS3231
* Stepper

## Wiring

### DS3231 Realtime clock

See Instructable https://www.instructables.com/id/Real-time-clock-using-DS3231-EASY/ .
A4 and A5 are assigned.

### ULN2003 Stepper controller

See https://coeleveld.com/arduino-stepper-uln2003a/ .
D8..D11 are assigned inthe sample code.

### Contack switch

See https://www.arduino.cc/en/tutorial/button .
D2 is assigned in the sample code.

## Codes

* The stepper rotates one cycle per minnute with min-clock.
* The stepper rotates one cycle per hour with hour-clock.
* Press the contact switch to fast winding. If you keep pressing, the motor rotates faster.


