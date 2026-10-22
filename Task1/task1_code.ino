const int greenLED  = 11;
const int yellowLED = 12;
const int redLED    = 13;

const unsigned long GREEN_TIME        = 10000;  // 10 s
const unsigned long YELLOW_AFTER_GREEN = 5000;  // 5 s
const unsigned long RED_TIME          = 10000;  // 10 s
const unsigned long YELLOW_AFTER_RED  = 5000;   // 5 s

int state = 1;  // 1 = Green, 2 = Yellow, 3 = Red, 4 = Yellow

unsigned long startTime = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  startTime = millis();
}

void loop() {

  switch (state) {

    case 1:  // Green ON
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);

      if (millis() - startTime >= GREEN_TIME) {
        state = 2;
        startTime = millis();
      }
      break;

    case 2:  // Yellow ON after Green
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      if (millis() - startTime >= YELLOW_AFTER_GREEN) {
        state = 3;
        startTime = millis();
      }
      break;

    case 3:  // Red ON
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);

      if (millis() - startTime >= RED_TIME) {
        state = 4;
        startTime = millis();
      }
      break;

    case 4:  // Yellow ON after Red
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      if (millis() - startTime >= YELLOW_AFTER_RED) {
        state = 1;
        startTime = millis();
      }
      break;
  }
}
