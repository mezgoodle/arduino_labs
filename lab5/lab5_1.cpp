#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(34,16,2);
const int DELAY = 150;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.print("Zavalniuk");
  lcd.setCursor(0, 1);
  lcd.print("Maksym");
}

void loop()
{
  for (int positionCounter = 0; positionCounter < 9; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(DELAY);
  }
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(DELAY);
  }
}
