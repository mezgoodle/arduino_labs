#define led_pin 4
#define pot_pin 1

int n, start, end, pot_value;


void setup() {
	Serial.begin(9600);
  	pinMode(led_pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    n = Serial.parseInt();
    Serial.print("n value: ");
    Serial.println(n);
    start = n * 20;
    Serial.print("start value: ");
    Serial.println(start);
  	end = n * 40;
    Serial.print("end value: ");
    Serial.println(end);
    delay(100);
  }
  pot_value = analogRead(pot_pin);
  Serial.println(pot_value);

  if (pot_value > start && pot_value < end) {
    digitalWrite(led_pin, HIGH);
    delay(1000);
    digitalWrite(led_pin, LOW);
    delay(1000);
  }
}
