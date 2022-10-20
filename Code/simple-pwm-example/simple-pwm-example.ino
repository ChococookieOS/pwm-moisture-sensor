void setup() {
  Serial.begin(9600);
  // Enable pin 3 as output pin
  pinMode(3, OUTPUT);
  DDRD |= 0b00001000;

  // Setup fast pwm via registers
  TCCR2A = 0b10100001;
  TCCR2B = 0b00000001;

  // PWM dutycycle of 2
  // Can be between 0 and 255
  // Depending on the voltage of the microcontroller
  // this value has to be adjusted
  // try which value gives you the greates range of
  // analog results
  OCR2B = 2;
}

void loop() {
  Serial.println(analogRead(A0));
  delay(20);
}
