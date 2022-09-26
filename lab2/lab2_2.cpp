#define n 90

const int led = n % 14;

const int start = n;
const int finish = 100 * (n % 5) + 1000;
const int step = n + 100;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for (int i = start; i <= finish; i = i + step) {
    digitalWrite(led, HIGH);
    delay(i);
    digitalWrite(led, LOW);
    delay(i);
    Serial.println(i);
  }
}
