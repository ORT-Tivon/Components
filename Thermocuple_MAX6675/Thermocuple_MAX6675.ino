#include <max6675.h>
#include <Wire.h>

int ktcSO = D2;
int ktcCS = D3;
int ktcCLK = D4;
const int buzzer = D5;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
  
void setup() {
  Serial.begin(9600);
  delay(2000);
}

void loop() {
   float DC = ktc.readCelsius();
   
   Serial.print("C = "); 
   Serial.print(ktc.readCelsius());
   if (DC > 40) {
    tone(buzzer, 1000, 300);
   }
   Serial.println();
// 

 delay(1000);
}
