// กำหนดขาที่เชื่อมกับ LED ดวงที่ 1 และ 2
int ledPin1 = 2;
int ledPin2 = 3;

void setup() {
  // กำหนดขาเป็น OUTPUT
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  
  // ตั้งค่า Timer ให้เรียกฟังก์ชันทุก 0.1 วินาที
  TCCR1A = 0; // ตั้งค่าให้ไม่ใช้ PWM
  TCCR1B = (1 << WGM12) | (1 << CS10); // ตั้งค่าให้ Timer 1 เป็น CTC mode และใช้ prescaler 1
  OCR1A = 1562; // ค่านับให้เรียกทุก 0.1 วินาที
  TIMSK1 = (1 << OCIE1A); // เปิดใช้งานการเรียกฟังก์ชัน ISR(TIMER1_COMPA_vect)
}

void loop() {
  // โปรแกรมหลักไม่ต้องทำอะไร
}

// ฟังก์ชันที่เรียกเมื่อ Timer 1 เรียก
ISR(TIMER1_COMPA_vect) {
  static int led1State = LOW;
  static int led2State = LOW;

  // กระพริบ LED ดวงที่ 1 ทุก 0.5 วินาที
  if (led1State == LOW) {
    led1State = HIGH;
  } else {
    led1State = LOW;
  }
  digitalWrite(ledPin1, led1State);

  // กระพริบ LED ดวงที่ 2 ทุก 0.3 วินาที
  if (led2State == LOW) {
    led2State = HIGH;
  } else {
    led2State = LOW;
  }
  digitalWrite(ledPin2, led2State);
}
