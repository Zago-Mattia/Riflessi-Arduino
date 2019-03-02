#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzer = 7;
int led = 6;
int button = 8;

void setup()
{
lcd.begin(16, 2);
pinMode(buzzer,OUTPUT);
pinMode(led,OUTPUT);
}

void loop()
{
lcd.print("Ciao prof!!!!");
delay(1000);
lcd.clear();
delay(1000);
lcd.print("EXPLOSION!!!!");
delay(1000);
lcd.clear();
delay(1000);
for(int i =1000; 1 > 0; i = i-50)
{
tone(buzzer,38,200);
delay(i);
digitalWrite(led, HIGH);
delay(50);
digitalWrite(led, LOW);
}



}
