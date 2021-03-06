 /*
 *  Author: Asaf Chertkoff (asaf.chertkoff at gmail.com)
 *  SoC tested: ESP-12E 8266 nodeMCU 
 *  
 *  2/3/2021
 *  Reference:
 *  Configure nodeMCU:
 *  https://create.arduino.cc/projecthub/electropeak/getting-started-w-nodemcu-esp8266-on-arduino-ide-28184f 
 *  
 */

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
