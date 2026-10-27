
# Arduino Traffic Light with Pedestrian Crossing

This project is a traffic light built with an Arduino Uno. It controls a car traffic light with green, yellow and red lights, and a pedestrian light with green and red. A pushbutton lets pedestrians request a crossing. After the button is pressed, the pedestrian light turns green during the next car red phase, then returns to red before the cars get green again.

The program uses `millis()` for timing instead of `delay()`, so the button is checked all the time.

## Components

- **Arduino Uno R3**: the controller that runs the program and switches the LEDs.
- **Breadboard (small)**: used to build the circuit without soldering.
- **2 red LEDs**: one for the car light, one for the pedestrian light.
- **1 yellow LED**: the yellow light for cars.
- **2 green LEDs**: one for the car light, one for the pedestrian light.
- **5 resistors (330 Ω)**: one per LED, to limit the current and protect the LEDs and the Arduino pins.
- **1 pushbutton**: the pedestrian request button.
- **Jumper wires**: to connect everything.

## Pins

| Function | Pin |
|----------|-----|
| Car green | 11 |
| Car yellow | 12 |
| Car red | 13 |
| Pedestrian green | 9 |
| Pedestrian red | 10 |
| Button | 2 |

Each LED is connected through a 330 Ω resistor to its pin, with the other leg to GND. The button connects pin 2 to GND and uses the Arduino's internal pull-up, so no extra resistor is needed.

## How It Works

Cars: Green (10 s) → Yellow (5 s) → Red (10 s) → Yellow (5 s) → repeat.

Pedestrians: red by default. If the button was pressed, the pedestrian light turns green 2 s after the cars turn red and goes back to red 2 s before the car red phase ends.


2. Open `traffic_light.ino` in the Arduino IDE.
3. Select Arduino Uno as the board and upload.
