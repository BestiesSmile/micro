
int ledPin1 = 2;
int ledPin2 = 4;


unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
const long interval1 = 50; // 0.5 วินาที
const long interval2 = 40; // 0.3 วินาที

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // 0.5 วินาที
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;

    if (digitalRead(ledPin1) == LOW) {
      digitalWrite(ledPin1, HIGH);
    } else {
      digitalWrite(ledPin1, LOW);
    }
  }

  // 0.3 วินาที
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;

    if (digitalRead(ledPin2) == LOW) {
      digitalWrite(ledPin2, HIGH);
    } else {
      digitalWrite(ledPin2, LOW);
    }
  }
}
