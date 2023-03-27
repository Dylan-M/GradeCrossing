# Grade Crossing
Arduino code for controlling a model railroad crossing gate's arms\
and flashers.

Code has optional capability for 2 sensors for detection and a\
potentiometer for flash rate

# Digital Pins
13: Input. Connect to ground to enable the potentiometer\

## User Defined Digital Pins
In GradeCrossing.ino starting on line 125, the user must define the pins for each grade crossing.\
By default, only a single crossing is set up. Two additional crossings showing different options\
are there as comments.

# Analog Pins
A2: Input. Potentiometer to control flash rate of the LEDs

# Defaults
When not using a potentiometer, the flash rate defaults to 800ms
