#include <Servo.h>
# define pin 2

Servo myservo;

int n = 90, max_angle, pot_value;

void setup() {
  Serial.begin(9600);
  myservo.attach(pin);
}

void loop() {
  if (Serial.available()) {
    n = Serial.parseInt();
    Serial.print("N value: ");
    Serial.println(n);
    delay(500);
  }

  int max_angle = 90 * 3 + 20;
  pot_value = analogRead(pin) / (1023 / 360);

  if (n != 0) max_angle = n;
  if (pot_value != 0) max_angle = pot_value;
  
  Serial.println();
  Serial.print("Pot value: ");
  Serial.print(pot_value);
  Serial.println();
  Serial.print("N value: ");
  Serial.print(n);
  Serial.println();
  Serial.print("Max value: ");
  Serial.print(max_angle);
  Serial.println();
 
  
  for (int pos = 0; pos < max_angle; pos += 1) {
  	myservo.write(pos);
  }
  for (int pos = max_angle; pos >= 1; pos -= 1) {
  	myservo.write(pos);
    delay(6 * 10);
  }
}
