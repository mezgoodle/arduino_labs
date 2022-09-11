#define pinNumberOutput 7
#define pinNumberDelay 6

const int dot = 1;
const int dash = 3*dot;
const int size_of_dictionary = 36;
const int max_symbols = 5;
const char dictionary[size_of_dictionary] = "abcvxz";
const int symbols_array[size_of_dictionary][max_symbols] = {
  {dot, dash},
  {dash, dot, dot, dot},
  {dash, dot, dash, dot},
  {dot, dot, dot, dash},
  {dash, dot, dot, dash},
  {dash, dash, dot, dot}
};

void setup()
{  
  pinMode(pinNumberOutput, OUTPUT);
  pinMode(pinNumberDelay, OUTPUT);
}

void loop()
{
  // dash dash dot dot pause dot dash pause dot dot dot dash
  const String surname = "zav";
  const int length = sizeof(dictionary)/sizeof(*dictionary);
  
  for (int i=0; i<surname.length(); i++) {
    int index = findIndex(surname[i], length);
    if (index == -1) continue;

    int symbols_length = sizeof(symbols_array[index])/sizeof(*symbols_array[index]);
    for (int y=0; y<symbols_length; y++) {
      if (symbols_array[index][y] == 0) continue;
      doLigthing(symbols_array[index][y]);
    }
    doLettersPause();
  }
}

void doLigthing(int seconds) {
  digitalWrite(pinNumberOutput, HIGH);
  delay(1000 * seconds);
  digitalWrite(pinNumberOutput, LOW);
  delay(1000 * dot);
}

void doLettersPause() {
  digitalWrite(pinNumberDelay, HIGH);
  delay(1000 * dash);
  digitalWrite(pinNumberDelay, LOW);
}

int findIndex(char letter, int length) {
  for(int index=0; index<length; index++) {
    if (dictionary[index] == letter) {
      return index;
    }
  
  }
  return -1;  
}
