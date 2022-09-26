const int led = 6;
const int btn = 4;
const int DELAY = 90 % 5;

boolean PREV_STATE = LOW;
boolean CURRENT_STATE = LOW;
boolean SWITCH_ON = false;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  Serial.begin(9600);
}

void loop(){
  CURRENT_STATE = debounce(PREV_STATE);
  if (PREV_STATE == LOW && CURRENT_STATE == HIGH) {
    SWITCH_ON = !SWITCH_ON;
  }
  PREV_STATE = CURRENT_STATE;
  Serial.println(SWITCH_ON);
  digitalWrite(led, SWITCH_ON);
}

boolean debounce(boolean previous){
  boolean current = digitalRead(btn);
  if (previous != current) delay(DELAY);
  current = digitalRead(btn);
  return current;
}
