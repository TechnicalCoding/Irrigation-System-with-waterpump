#include <LiquidCrystal_I2C.h> //LCD I2C liberary 
                                              
#include <Wire.h> //wire library 

LiquidCrystal_I2C lcd(0x27, 16, 2); 
int waterpump = 4; //pin number of rice pump
void setup()
{
  Serial.begin(9600);
  pinMode(waterpump,OUTPUT);//declaring rice pump as output 
  lcd.begin();   
  lcd.backlight(); 
}
void loop()
{
  int S1= analogRead(A0);//declaring sensor 1 pin
  Serial.print(S1);    
  Serial.print(" - ");
  if(S1>=1000)//when sensor is not in soil
  {
    lcd.setCursor(0,0);
    lcd.print("  Soil Status   ");
    lcd.setCursor(0,1);
    lcd.print("  Not in soil   ");
    digitalWrite(waterpump,LOW);
  }
    if(S1 < 1000 && S1>=800)//when sensor indicates dry soil
  {
    lcd.setCursor(0,0);
    lcd.print("  Soil Status   ");
    lcd.setCursor(0,1);
    lcd.print("     -:DRY:-    ");
    digitalWrite(waterepump,HIGH);
  }
    if(S1 <800 && S1 >=370)//when sensor indicates humid soil
  {
    lcd.setCursor(0,0);
    lcd.print("  Soil Status   ");
    lcd.setCursor(0,1);
    lcd.print("    -:HUMID:-   ");
    digitalWrite(waterpump,LOW);
  }
  if(S1 < 370)//when sensor indicates water 
  {
    lcd.setCursor(0,0);
    lcd.print("  Soil Status   ");
    lcd.setCursor(0,1);
    lcd.print("  Water logging ");
    digitalWrite(waterpump,LOW);
  }
}
