#define n 90
#define led 3

const int MIN_VALUE = n;
const int MAX_VALUE = 255 - n;
const int DELAY = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  for (int i = MIN_VALUE; i < MAX_VALUE; i++) {
    analogWrite(led, i);
    Serial.println(i);
    delay(DELAY);
  }
  for (int i = MAX_VALUE; i >= MIN_VALUE; i--) {
    analogWrite(led, i);
    Serial.println(i);
    delay(DELAY);
  }
}
