//        sevseg.setNumber(6);
//        sevseg.refreshDisplay(); 

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

int gear = 1;

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

void loop(){
//////////////
//  GEAR UP //
//////////////
    buttonUpState = digitalRead(buttonUpPin);
    if(buttonUpState == HIGH){
        buttonUpState = LOW;
    }
    else
        buttonUpState = HIGH;

    if(buttonUpState == HIGH){
        // Serial.println("on");
        lastUpButtonState = HIGH;
        gear++;
        Serial.println(gear);
        delay(200);
        //sevseg.setNumber();    
        //sevseg.refreshDisplay();     
    }
     else{
        //  Serial.println("off");
     if(buttonUpState == LOW){
        sevseg.setNumber(gear);    
        sevseg.refreshDisplay();
      }
    }

////////////////
//  GEAR DOWN //
////////////////
    buttonDownState = digitalRead(buttonDownPin);
    if(buttonDownState == HIGH){
        buttonDownState = LOW;
    }
    else
        buttonDownState = HIGH;

    if(buttonDownState == HIGH){
        // Serial.println("on");
        lastDownButtonState = HIGH;
        gear--;
        Serial.println(gear);
        delay(200);
        //sevseg.setNumber();    
        //sevseg.refreshDisplay();     
    }
    else{
        //  Serial.println("off");
    if(buttonDownState == LOW){
       sevseg.setNumber(gear);    
       sevseg.refreshDisplay();
    }
    }

////////////////
//  RESET PIN //
////////////////
    buttonResetState = digitalRead(buttonResetPin);
    if(buttonResetState == HIGH){
        buttonResetState = LOW;
    }
    else
        buttonResetState = HIGH;

    if(buttonResetState == HIGH){
        // Serial.println("on");
        lastResetButtonState = HIGH;
        gear = 1;
        Serial.println(gear);
        delay(200);
        //sevseg.setNumber();    
        //sevseg.refreshDisplay();     
    }
    else{
        //  Serial.println("off");
    if(buttonResetState == LOW){
       sevseg.setNumber(gear);    
       sevseg.refreshDisplay();
    }
    }
  

}
