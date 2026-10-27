// Car traffic lights
const int greenLED  = 11;
const int yellowLED = 12;
const int redLED    = 13;

// Pedestrian traffic lights
const int pedGreenLED = 9;
const int pedRedLED   = 10;

// Pedestrian button (wired between pin 2 and GND)
const int buttonPin = 2;

const unsigned long GREEN_TIME         = 10000;  // 10 s
const unsigned long YELLOW_AFTER_GREEN = 5000;   // 5 s
const unsigned long RED_TIME           = 10000;  // 10 s
const unsigned long YELLOW_AFTER_RED   = 5000;   // 5 s
const unsigned long PED_CLEAR_TIME     = 2000;   // 2 s all-red before and after pedestrian green

int state = 1;  // 1 = Green, 2 = Yellow, 3 = Red, 4 = Yellow

unsigned long startTime = 0;

// Button / pedestrian request
bool pedestrianRequest = false;
bool pedServed = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(pedGreenLED, OUTPUT);
  pinMode(pedRedLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  startTime = millis();
}

void loop() {

  // Remember a button press (falling edge)
  bool currentButtonState = digitalRead(buttonPin);
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    pedestrianRequest = true;
  }
  lastButtonState = currentButtonState;

  switch (state) {

    case 1:  // Green ON
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);

      digitalWrite(pedGreenLED, LOW);
      digitalWrite(pedRedLED, HIGH);

      if (millis() - startTime >= GREEN_TIME) {
        state = 2;
        startTime = millis();
      }
      break;

    case 2:  // Yellow ON after Green
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      digitalWrite(pedGreenLED, LOW);
      digitalWrite(pedRedLED, HIGH);

      if (millis() - startTime >= YELLOW_AFTER_GREEN) {
        state = 3;
        startTime = millis();
      }
      break;

    case 3: {  // Red ON (pedestrians may cross in the middle of this phase)
      unsigned long elapsed = millis() - startTime;

      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);

      // Pedestrian green only if requested, with all-red margin at both ends
      bool pedWalk = pedestrianRequest &&
                     elapsed >= PED_CLEAR_TIME &&
                     elapsed <  RED_TIME - PED_CLEAR_TIME;

      if (pedWalk) pedServed = true;

      digitalWrite(pedGreenLED, pedWalk ? HIGH : LOW);
      digitalWrite(pedRedLED,   pedWalk ? LOW  : HIGH);

      if (elapsed >= RED_TIME) {
        if (pedServed) {           // only clear the request if it was actually served
          pedestrianRequest = false;
          pedServed = false;
        }
        state = 4;
        startTime = millis();
      }
      break;
    }

    case 4:  // Yellow ON after Red
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      digitalWrite(pedGreenLED, LOW);
      digitalWrite(pedRedLED, HIGH);

      if (millis() - startTime >= YELLOW_AFTER_RED) {
        state = 1;
        startTime = millis();
      }
      break;
  }
}
