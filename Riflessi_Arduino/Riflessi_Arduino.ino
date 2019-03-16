#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzer = 7;
int led = 6;
int button = 8;
int decisione;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);

}

void loop()
{
Inizio();
LedRiflessi();
BuzzerRiflessi();
Riavvio();
}

void Inizio()
{
  
  lcd.setCursor(0,0);
  lcd.print("<TEST RIFLESSI>");
  lcd.setCursor(0,1);
  lcd.print("Premi il");
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print("pulsante per    ");
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print("iniziare        ");
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print("                ");;

  while (digitalRead(button) == LOW)
  {

  }
    digitalWrite(led, HIGH);
    delay(500);
    digitalWrite(led, LOW); 
    tone(buzzer,500,500);
    lcd.setCursor(0,0);
    lcd.print("Avvio test in   ");
    lcd.setCursor(0,1);
    lcd.print("corso           ");
}
void LedRiflessi()
{
  lcd.setCursor(0,0);
  lcd.print("Avvio primo      ");
  lcd.setCursor(0,1);
  lcd.print("test con led     ");
  delay(2000);
  
  lcd.setCursor(0,0);
  lcd.print("Schiaccia il     ");
  lcd.setCursor(0,1);
  lcd.print("bottone all'     ");
  delay(1500);
  lcd.setCursor(0,0);
  lcd.print("accensione del   ");
  lcd.setCursor(0,1);
  lcd.print("led rosso..      ");
  delay(2000);
  lcd.clear();
  lcd.print("3..              ");
  delay(1000);
  lcd.clear();
  lcd.print("2..              ");
  delay(1000);
  lcd.clear();
  lcd.print("1..              ");
  delay(1000);
  lcd.clear();
  int tempo = random(500,7500);
  delay (tempo);
  digitalWrite(led, HIGH);
  int timer = millis();
  while (digitalRead(button) == LOW)
  {

  }
  digitalWrite(led, LOW);
  int timerr = millis();
  lcd.setCursor(0,0);
  lcd.print("Tempo in ms:     ");
  lcd.setCursor(0,1);
  lcd.print(timerr-timer);
  delay(5000);
  
}
void BuzzerRiflessi()
{
  lcd.setCursor(0,0);
  lcd.print("Avvio secondo    ");
  lcd.setCursor(0,1);
  lcd.print("test con buzzer  ");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Schiaccia il     ");
  lcd.setCursor(0,1);
  lcd.print("bottone all'     ");
  delay(1500);
  lcd.setCursor(0,0);
  lcd.print("accensione del   ");
  lcd.setCursor(0,1);
  lcd.print("input sonoro..   ");
  delay(2000);
  lcd.clear();
  lcd.print("3..              ");
  delay(1000);
  lcd.clear();
  lcd.print("2..              ");
  delay(1000);
  lcd.clear();
  lcd.print("1..              ");
  delay(1000);
  lcd.clear();
  int tempo = random(500,7500);
  delay (tempo);
  tone(buzzer,1000);
  int timer = millis();
  while (digitalRead(button) == LOW)
  {
    
  }
  noTone(buzzer);
  int timerr = millis();
  lcd.setCursor(0,0);
  lcd.print("Tempo in ms:     ");
  lcd.setCursor(0,1);
  lcd.print(timerr-timer);
  delay(5000);
  
}
void Riavvio ()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Riavvio arduino    ");
    for (int i = 9;i>=0;i--)
    {
       lcd.setCursor(0,1);
       lcd.print(i);
       delay(1000);
    }
    setup();
}