/*  
 *  PH meter Tutorial 
 *  -----------------------
 *  
 *  Editor: Asaf Chertkoff (asaf.chertkoff at gmail.com)
 *  SoC tested: Arduino uno
 *  
 *  3/12/2021
 *  Reference:
 *  https://circuitdigest.com/microcontroller-projects/arduino-ph-meter
 *  
 */

#include <Wire.h>
float calibration_value = 21.34+8.2;    /* needed to be calibrated with distilled solution with a buffer */
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;     

void setup() 
{
 Serial.begin(9600);
  Serial.println("init complete");
}

void loop() {
 for(int i=0;i<10;i++) {             
    buffer_arr[i]=analogRead(A0);        /* getting ten inputs from A0 pin and push them into an array */
    delay(30);
 }
 
 for(int i=0;i<9;i++){                                
    for(int j=i+1;j<10;j++){
      if(buffer_arr[i]>buffer_arr[j]) {
        temp=buffer_arr[i];
        buffer_arr[i]=buffer_arr[j];
        buffer_arr[j]=temp;
      }
    }
 }
 
 avgval=0;
 for(int i=2;i<8;i++) avgval+=buffer_arr[i];
 float volt=(float)avgval*5.0/1024/6;
 float ph_act = -5.70 * volt + calibration_value;

 Serial.println("pH Val:");
 Serial.println(ph_act);
 delay(1000);
}
