// Now turn this trash into treasure!
#define REGULAR_LED_PIN 16
#define RED_PIN 17
#define GREEN_PIN 18
#define BLUE_PIN 19
#define BUTTON_PIN 20

int currentColor = 0;
bool ledState = false;

void setup() {
  pinMode(REGULAR_LED_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  digitalWrite(REGULAR_LED_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Setup complete.");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    delay(50);
    if (digitalRead(BUTTON_PIN) == LOW) {
      ledState = !ledState;
      currentColor = (currentColor + 1) % 8;
      updateLEDs();
      
      Serial.print("Button pressed. LED State: ");
      Serial.print(ledState);
      Serial.print(", Current Color: ");
      Serial.println(currentColor);

      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }
    }
  }
}

void updateLEDs() {
  digitalWrite(REGULAR_LED_PIN, ledState ? HIGH : LOW);

  switch (currentColor) {
    case 0:
      setColor(LOW, LOW, LOW);    // Off
      break;
    case 1:
      setColor(HIGH, LOW, LOW);   // Red
      break;
    case 2:
      setColor(LOW, HIGH, LOW);   // Green
      break;
    case 3:
      setColor(LOW, LOW, HIGH);   // Blue
      break;
    case 4:
      setColor(HIGH, HIGH, LOW);  // Yellow
      break;
    case 5:
      setColor(HIGH, LOW, HIGH);  // Magenta
      break;
    case 6:
      setColor(LOW, HIGH, HIGH);  // Cyan
      break;
    case 7:
      setColor(HIGH, HIGH, HIGH); // White
      break;
  }

  Serial.print("RGB LED Color Updated: ");
  Serial.print("R:");
  Serial.print(digitalRead(RED_PIN));
  Serial.print(" G:");
  Serial.print(digitalRead(GREEN_PIN));
  Serial.print(" B:");
  Serial.println(digitalRead(BLUE_PIN));
}

void setColor(bool red, bool green, bool blue) {
  digitalWrite(RED_PIN, red);
  digitalWrite(GREEN_PIN, green);
  digitalWrite(BLUE_PIN, blue);
}