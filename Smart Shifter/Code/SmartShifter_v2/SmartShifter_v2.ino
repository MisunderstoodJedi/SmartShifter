#include "SevSeg.h"
SevSeg sevseg; 

const int  buttonUpPin = 12;    
int buttonUpState = 0;          
int lastUpButtonState = LOW;    

const int  buttonDownPin = 11;    
int buttonDownState = 0;          
int lastDownButtonState = LOW;    

const int  buttonResetPin = 10;    
int buttonResetState = 0;          
int lastResetButtonState = LOW;    

int gear = 2;

void setup(){ 
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;
    
    byte hardwareConfig = COMMON_ANODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(40);

    pinMode(buttonUpPin, INPUT_PULLUP);
    pinMode(buttonDownPin, INPUT_PULLUP);
    pinMode(buttonResetPin, INPUT_PULLUP);
    lastUpButtonState = LOW;
    lastDownButtonState = LOW;
    lastResetButtonState = LOW;
    Serial.begin(9600);
  }

void loop() {
    switch (gear) {
        case 0:
            reverseGear();
            break;
        case 1:
            neutralGear();
            break;
        case 2:
            firstGear();
            break;
        case 3:
            secondGear();
            break;
        case 4:
            thirdGear();
            break;
        case 5:
            fourthGear();
            break;
        case 6:
            fithGear();
            break;
        case 7:
            sixthGear();
            break;
        case 8:
            seventhGear();
            break;
        case 9:
            eighthGear();
            break;
        case 10:
            ninthGear();
            break;
      }

    buttonUpState = digitalRead(buttonUpPin);
    if(buttonUpState == LOW){
            gear++;
            delay(200);
      }

    buttonDownState = digitalRead(buttonDownPin);
    if(buttonDownState == LOW){
            gear--;
            delay(200);
      }

    buttonResetState = digitalRead(buttonResetPin);
    if(buttonResetState == LOW){
            gear = 2;
            delay(200);
      }
}

void reverseGear() {
    sevseg.setChars("r");   
    sevseg.refreshDisplay();
  }

void neutralGear() {
    sevseg.setChars("n");   
    sevseg.refreshDisplay();
  }

void firstGear() {
    sevseg.setNumber(1);    
    sevseg.refreshDisplay();
  }

void secondGear() {
    sevseg.setNumber(2);    
    sevseg.refreshDisplay();
  }

void thirdGear() {
    sevseg.setNumber(3);    
    sevseg.refreshDisplay();
  }

void fourthGear() {
    sevseg.setNumber(4);    
    sevseg.refreshDisplay();
  }

void fithGear() {
    sevseg.setNumber(5);    
    sevseg.refreshDisplay();
  }

void sixthGear() {
    sevseg.setNumber(6);    
    sevseg.refreshDisplay();
  }

void seventhGear() {
    sevseg.setNumber(7);    
    sevseg.refreshDisplay();
  }

void eighthGear() {
    sevseg.setNumber(8);    
    sevseg.refreshDisplay();
}

void ninthGear() {
    sevseg.setNumber(9);    
    sevseg.refreshDisplay();
  }
