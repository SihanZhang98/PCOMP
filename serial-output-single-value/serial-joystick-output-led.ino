int brightness;
void setup() {
//  pinMode(8,OUTPUT);
Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    brightness=Serial.read();
    analogWrite(6,brightness);
    Serial.write(brightness);
    }
}
