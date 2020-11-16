#include <Stepper.h>

const int stepsPerRevolution = 2048;
int incomingByte;
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

void setup() {
  pinMode(6,OUTPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
      if (incomingByte == 1) {
//        delay(10000);
        for(int i=0;i<255;i++){analogWrite(6,i);delay(15);}
//         Serial.println("message sent");
        myStepper.step(stepsPerRevolution);
        for(int i=254;i>=0;i--){analogWrite(6,i);delay(15);}
//        digitalWrite(6,HIGH);
//        delay(5000);
//        digitalWrite(6,LOW);
       
        
      }
   }
}
