// בלוחות esp הפונקציה noTone לא עובדת, צריך להשתמש בdigitalWrite(buzzer, HIGH)
const int buzzer = D5;
  
void setup() {
  Serial.begin(9600);
}

void loop() {
   tone(buzzer, 1000);
   Serial.print("buzzer is 1000");
   delay(2000);
   tone(buzzer, 2000, 2000);
   Serial.print("buzzer is 2000 for 2000 ms");

   noTone(buzzer);
   delay(1000);
   digitalWrite(buzzer, HIGH);
   delay(3000);
}
