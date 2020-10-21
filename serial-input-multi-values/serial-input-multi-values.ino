void setup() {
   // start serial port at 9600 bps:
   Serial.begin(9600);
   pinMode(8,INPUT_PULLUP);
}
 
void loop() {
   int xpos = analogRead(A0);
   int ypos = analogRead(A1);
   int buttonState = digitalRead(8);
   
   Serial.print(xpos);
   Serial.print(",");
   Serial.print(ypos);
   Serial.print(",");
   Serial.println(buttonState);
}
