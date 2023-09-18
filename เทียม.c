// กำหนดขาที่เชื่อมกับ LED ดวงที่ 1 และ 2
int ledPin1 = 2;
int ledPin2 = 3;

void setup() {
  // กำหนดขาเป็น OUTPUT
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // กระพริบ LED ดวงที่ 1 ทุก 0.5 วินาที
  digitalWrite(ledPin1, HIGH);
  delay(500);
  digitalWrite(ledPin1, LOW);
  delay(500);

  // กระพริบ LED ดวงที่ 2 ทุก 0.3 วินาที
  digitalWrite(ledPin2, HIGH);
  delay(300);
  digitalWrite(ledPin2, LOW);
  delay(300);
}
