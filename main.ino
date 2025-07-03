// تعريف دبابيس الأزرار
const int buttonPins[3] = {2, 3, 4};

// تعريف دبابيس LEDs
const int ledPins[3] = {8, 9, 10};

// حالات الأزرار المؤثرة على وضعية كل زر
bool lastButtonState[3];
bool ledState[3];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    lastButtonState[i] = HIGH; // كونه مفعل pullup
    ledState[i] = LOW;
    digitalWrite(ledPins[i], ledState[i]);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    bool currentState = digitalRead(buttonPins[i]);
    if (lastButtonState[i] == HIGH && currentState == LOW) {
      // اكتشفنا ضغط على الزر
      ledState[i] = !ledState[i];
      digitalWrite(ledPins[i], ledState[i]);
      Serial.print("زر #"); Serial.print(i);
      Serial.print(" -> LED "); Serial.println(ledState[i] ? "ON" : "OFF");
      delay(50); // debouncing بسيط
    }
    lastButtonState[i] = currentState;
  }
}
