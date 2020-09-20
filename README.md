# Yeebutton
Extension of the original Python script for controlling Yeelight bulbs, and ESP8266 code (Arduino IDE) for a control device that changes scenes with physical buttons.

# Where to start
Yeelight has a [webpage for developers](https://www.yeelight.com/en_US/developer) and a [handy inter-operation specification document](https://www.yeelight.com/download/Yeelight_Inter-Operation_Spec.pdf)

# What is different from the original Python script
I added 3 pre-defined scenes that I use (called ``low``, ``mid``, and ``full_fire``) as well as a shut-off command

# What does the Arduino script do
The script is made for an ESP8266 NodeMCU board with 4 buttons attached to it (pin-~-ground). 3 buttons trigger the 3 predefined scenes and 4th one turns the light off. The main loop could be written more efficiently (lots of repetitive code), but it is a rework of an older project and not worth my time.
