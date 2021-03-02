/*  
 *  Encoder Module Tutorial 
 *  -----------------------
 *  
 *  Author: Asaf Chertkoff (asaf.chertkoff at gmail.com)
 *  SoC tested: ESP-12E 8266 nodeMCU 
 *  
 *  2/10/2021
 *  Reference:
 *  Configure nodeMCU:
 *  https://create.arduino.cc/projecthub/electropeak/getting-started-w-nodemcu-esp8266-on-arduino-ide-28184f 
 *  Rotery encoder:
 *  https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
 *  https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
 */
 
 #define outputA D4
 #define outputB D3
 #define outputC D5

 int counter = 0; 
 int aState;
 int aLastState;  
 int pressed; 
 unsigned long lastButtonPress = 0;

 
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (outputC,INPUT_PULLUP);
  
   Serial.begin (9600);
   aLastState = digitalRead(outputA);   
 } 

 void loop() { 
   aState = digitalRead(outputA); 
   if (aState != aLastState){     
     if (digitalRead(outputB) != aState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState;
   pressed = digitalRead(outputC);
   if (pressed == LOW) {
    if (millis() - lastButtonPress > 50) {
      Serial.println("Button pressed!");
    }
    lastButtonPress = millis();
   }
 }
