#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int buzzer = 7;
int button = 8;  
int tempof=0;
int timerf=0;
int portarossa = 13;
int portaverde = 9;
int portablu =10;
int led;
int risR;
int risB;

void setup()
{
  Serial.begin(9600); // nel caso serva
  lcd.begin(16, 2);
  pinMode(buzzer,OUTPUT);
  pinMode(button,INPUT);
  
  pinMode(portarossa, OUTPUT); 
  pinMode(portaverde, OUTPUT); 
  pinMode(portablu, OUTPUT); 
  
  tempof=0;
  timerf=0;
  risR = 0;
  risB = 0;
  led = 0;
}

void loop()
{
  Inizio();
  risR = LedRiflessi();
  if(risR == 1)
  {
    risB = BuzzerRiflessi();
  }
  if(risB == 1)
  {
    Risultati();
  }
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
  lcd.print("                ");
  
  while (digitalRead(button) == LOW){}
    digitalWrite(portablu, HIGH);
    delay(500);
    digitalWrite(portablu, LOW);
    tone(buzzer,500,500);
    lcd.setCursor(0,0);
    lcd.print("Avvio test in   ");
    lcd.setCursor(0,1);
    lcd.print("corso           ");
}
int LedRiflessi()
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
  lcd.print("led blu..        ");
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
  digitalWrite(portablu, HIGH);
  int timer = millis();
  while (digitalRead(button) == LOW){}
  digitalWrite(portablu, LOW);
  int timerr = millis();
  if ((timerr-timer)<80)
  {
    digitalWrite(portarossa, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Non vale!!!    ");
    lcd.setCursor(0,1);
    lcd.print("Hai barato     ");
    delay(2000);
    digitalWrite(portarossa, LOW);
    return 0;
  }
  else
  {
  lcd.setCursor(0,0);
  lcd.print("Tempo in ms:     ");
  lcd.setCursor(0,1);
  lcd.print(timerr-timer);
  tempof= timerr-timer;
  delay(5000);
  return 1;
  }
}

int BuzzerRiflessi()
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
  while (digitalRead(button) == LOW){}
  noTone(buzzer);
  int timerr = millis();
    if ((timerr-timer)< 80)
  {
    digitalWrite(portarossa, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Non vale!!!    ");
    lcd.setCursor(0,1);
    lcd.print("Hai barato     ");
    delay(2000);
    digitalWrite(portarossa, LOW);
    return 0;
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Tempo in ms:     ");
    lcd.setCursor(0,1);
    lcd.print(timerr-timer);
    timerf= timerr-timer;
    delay(5000);
    return 1;
  }
}
void Risultati()
{
    int tempomedio = (timerf+tempof)/2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tempo medio:");
    lcd.setCursor(0,1);
    lcd.print(tempomedio);
    delay(2500);
    lcd.clear();
    if (tempomedio<249)
    {
      lcd.clear();
      digitalWrite(portaverde, HIGH);
      lcd.setCursor(0,0);
      lcd.print("Congratulazioni! ");
      lcd.setCursor(0,1);
      lcd.print("Hai passato      ");
      delay(750);
      lcd.setCursor(0,1);
      lcd.print("il test!!        ");
      delay(1500);
      digitalWrite(portaverde, LOW);
    }
    else
    {
      digitalWrite(portarossa, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Peccato!!        ");
      lcd.setCursor(0,1);
      lcd.print("Non hai passato  ");
      delay(750);
      lcd.setCursor(0,1);
      lcd.print("il test..        ");
      delay(1500);
      digitalWrite(portarossa, LOW);
    }
}
void Riavvio ()
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Riavvio arduino    ");
    for (int i = 5;i>=0;i--)
    {
       lcd.setCursor(0,1);
       lcd.print(i);
       delay(1000);
    }
    setup();
}
