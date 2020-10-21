
void setup() {
  Serial.begin(9600);    
  Serial.setTimeout(10); 
}
 
void loop() {
  if (Serial.available() > 0) { 
    int inDataX = Serial.parseInt(); 
    int inDataY = Serial.parseInt();
    // read it
    if (Serial.read() == '\n') {     
      analogWrite(5, inDataX);    
      analogWrite(6, inDataY);
    }
  }
}
