#include <max6675.h>
#include <Wire.h>

int ktcSO = D2;
int ktcCS = D3;
int ktcCLK = D4;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);
  
void setup() {
  Serial.begin(9600);
  delay(2000);
}

void loop() {
   float DC = ktc.readCelsius();
   
   Serial.print("C = "); 
   Serial.print(ktc.readCelsius());
   Serial.println();
// 

 delay(1000);
}
