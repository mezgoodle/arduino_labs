#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(34,16,2);
String surname = "Завальню";

byte letters[8][8] = {
  {B00110, B00001, B00001, B00110, B00001, B00001, B00110, B00000, },
  {B00000, B00000, B01110, B01010, B01110, B01010, B01010, B00000, },
  {B00000, B11000, B10100, B11100, B10100, B11000, B00000, B00000, },
  {B00000, B00000, B01110, B01010, B01110, B01010, B01010, B00000, },
  {B00000, B00111, B00101, B00101, B00101, B01101, B00000, B00000, },
  {B00000, B10000, B10000, B11110, B10010, B11110, B00000, B00000, },
  {B00000, B10001, B10001, B11111, B10001, B10001, B00000, B00000, },
  {B00000, B10010, B10101, B11001, B10101, B10010, B00000, B00000, },
};

void setup()
{
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  for (int index = 0; index < 8; index++){
    lcd.createChar(index, letters[index]);
  }
  for (int index = 0; index < 8; index++){
    lcd.setCursor(index,0);
    lcd.write(index);
  }
}

void loop()
{
}
