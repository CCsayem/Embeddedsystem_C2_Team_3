
## Circuit Description

This circuit shows the car and pedestrian traffic light system, built on a small breadboard and connected to an Arduino Uno R3.

### Components in the diagram

- 1 Arduino Uno R3
- 1 small breadboard
- 5 LEDs:
  - 3 car traffic light LEDs: red, yellow, green
  - 2 pedestrian traffic light LEDs: red, green
- 5 resistors (one per LED; verify the actual resistance value)
- 1 push button
- Jumper wires for the connections

### Wiring

| Component | From | To |
|---|---|---|
| Car red LED | Arduino pin 6 | Anode (long leg) of the red LED |
| Car yellow LED | Arduino pin 5 | Anode (long leg) of the yellow LED |
| Car green LED | Arduino pin 7 | Anode (long leg) of the green LED |
| Pedestrian green LED | Arduino pin 11 | Anode (long leg) of the green LED |
| Pedestrian red LED | Arduino pin 12 | Anode (long leg) of the red LED |
| Push button | Arduino pin 2 | One terminal of the push button |
| Push button | Arduino GND | Opposite terminal of the push button |
| GND wire | Arduino GND | Breadboard negative (–) ground rail |

The cathode (short leg) of each LED is connected to the common ground rail through the circuit.

**Note:** Each LED must have its own suitable current-limiting resistor. Check the actual resistor value before listing it in the component list.
