# Grade Crossing
Arduino code for controlling a model railroad crossing gate's arms\
and flashers.\

Code has optional capability for 2 sensors for detection and a\
potentiometer for flash rate\

# Digital Pins
0: Input. Connect to ground to enable the potentiometer\
3: Output. For phase A LEDs, connect with a 120 to 480 Ohm resistor\
4: Output. For phase B LEDs, connect with a 120 to 480 Ohm resistor\
5: Input. For sensor A\
6: Input. For sensor B\

# Analog Pins
A2: Input. Potentiometer to control flash rate of the LEDs\

# Defaults
When not using a potentiometer, the flash rate defaults to 800ms\
