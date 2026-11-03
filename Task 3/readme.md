## Task 3 – Circuit Description: Car Traffic Light

The car traffic light circuit is built using an Arduino Uno R3, a small breadboard, three LEDs (red, yellow, and green), and three 330 Ω resistors.

### Wiring Connections

- **Red wire:** Connects Arduino digital pin 13 to the red LED anode (long leg) through a 330 Ω resistor.
- **Yellow wire:** Connects Arduino digital pin 12 to the yellow LED anode (long leg) through a 330 Ω resistor.
- **Green wire:** Connects Arduino digital pin 11 to the green LED anode (long leg) through a 330 Ω resistor.
- **Black wire:** Connects Arduino GND to the negative (–) ground rail of the breadboard.

The short leg (cathode) of each LED is connected to the breadboard's ground rail. Each LED has its own resistor to limit the current and protect the LED.

### Working Principle

The Arduino controls the three LEDs automatically using the programmed traffic light sequence:

1. Green LED turns ON for 10 seconds.
2. Yellow LED turns ON for 5 seconds.
3. Red LED turns ON for 10 seconds.
4. Yellow LED turns ON again for 5 seconds.

This sequence repeats continuously.

The system uses a switch-case structure and the `millis()` function to control the LED states and timing without blocking the Arduino program.
