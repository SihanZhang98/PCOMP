#include <pitchToFrequency.h>
#include <pitchToNote.h>
#include <frequencyToNote.h>
#include <MIDIUSB_Defs.h>
#include <MIDIUSB.h>


//for dance monkey
int keys[] = {11, 10, 9, 8, 6, 5, 4, 3, 14, 15, 16, 17, 18, 19}; // pins for pushbuttons (keys)
int lastKeyState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // previous state of the keys
int keyCount = 14;             // number of keys
int baseNote = pitchC4 + 1;    // C4 sharp, used as the base note
int inc[] = {0, 1, 3, 5, 7, 8, 10, 12, 13, 15, 17, 19, 20, 22};
int noteValue = baseNote;
//int count=0;
int lastCount;
int lastButtonState15 = 0;
int lastButtonState16 = 0;

void setup() {
  for (int k = 0; k < keyCount; k++) { 
    pinMode(keys[k], INPUT_PULLUP);          
  }
  //  Serial.begin(9600);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
}

void loop() {
  int count = 0;
  for (int k = 0; k < keyCount; k++) {
    int keyState = digitalRead(keys[k]);
    count = count + !keyState;
    if (keyState != lastKeyState[k]) {
      delay(20);
      if (keyState == LOW) {
        Serial.println(keyState);
        noteValue = baseNote + inc[k];
        midiCommand(0x90, noteValue, 0x7F);
      } else  {
        Serial.println(keyState);
        midiCommand(0x80, noteValue, 0);
      }
      lastKeyState[k] = keyState;
    }
  }
  if (lastCount != count && count == 0) {
    Serial.println("hello");
    midiCommand(0xb0, 0x7b, 0);
  }
  lastCount = count;

  int buttonState15 = digitalRead(20);
  if (lastButtonState15 != buttonState15) {
    if (buttonState9 ==  LOW) {
      baseNote = baseNote - 12;
    }
    lastButtonState9 = buttonState9;
  }

  int buttonState16 = digitalRead(21);
  if (lastButtonState16 != buttonState16) {
    if (buttonState16 == LOW) {
      baseNote = baseNote + 12;
    }
    lastButtonState10 = buttonState10;
  }

}

// send a 3-byte midi message
void midiCommand(byte cmd, byte data1, byte  data2) {

  midiEventPacket_t midiMsg = {cmd >> 4, cmd, data1, data2};
  MidiUSB.sendMIDI(midiMsg);
}
