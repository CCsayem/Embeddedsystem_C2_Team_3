
int greenLED = 11;
int yellowLED = 12;
int redLED = 13;

int state = 1;  // 1 = Green, 2 = Yellow, 3 = Red, 4 = Yellow

unsigned long startTime = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {

  switch (state) {

    case 1:  // Green ON
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, LOW);

      if (millis() - startTime >= 4000) {
        state = 2;
        startTime = millis();
      }
      break;

    case 2:  // Yellow ON after Green
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      if (millis() - startTime >= 2000) {
        state = 3;
        startTime = millis();
      }
      break;

    case 3:  // Red ON
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(redLED, HIGH);

      if (millis() - startTime >= 4000) {
        state = 4;
        startTime = millis();
      }
      break;

    case 4:  // Yellow ON after Red
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(redLED, LOW);

      if (millis() - startTime >= 1000) {
        state = 1;
        startTime = millis();
      }
      break;
  }
}
