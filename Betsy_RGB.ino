#include <RGB_LED.h> //library to control individual RGB LEDs (common Cathode)

#define Pin_b1 3 //RGB (Blue) LED output pin
#define Pin_g1 5 //RGB (Green) LED output pin
#define Pin_r1 6 // RGB (Red) LED output pin
#define Pin_button 8 // Button input pin

// -------- Pin Output Variables -----------
uint8_t maxBrightness; //value 0-255

// --------- Pin Input Variables -----------
bool pinButtonValue; 

// ----------- State Variables --------------
uint8_t lightShow_State; //light show's numerical identifier
uint8_t numberOfStates; //constant that equals the number of light shows programmed (including the "ALL LEDs OFF" show)  

//---------LED Classes---------- use with RGB_LED.h library
//RGB_LED LED1(Pin_r1, Pin_g1, Pin_b1);

void setup() {
  pinMode(Pin_button, INPUT_PULLUP); //INPUT_PULLUP connects the pin to 5V with the arduino's built in 20K resistor in between
  
  maxBrightness = 0; //0 is max for common anode RGB (255 for common cathode RGB)
  lightShow_State = 0; //initialize to 0, which is the "All LEDs OFF" state
  numberOfStates = 2; //constant that equals the number of light shows programmed (including the "ALL LEDs OFF" show)
  
  Serial.begin(9600); //for debugging

  //LED1.set(255,255,255); //common anode RGB LED so this sets led to OFF
}

void loop() {
  if (lightShow_State == 0){
    LightShow_0();
  }
  
  else if (lightShow_State == 1){
    LightShow_1();
  }
  
  pinButtonValue=digitalRead(Pin_button);
  Serial.println(pinButtonValue); //for debugging
  
  //LED1.setFunction(Step2);
  //LED1.run();
        
  if (pinButtonValue == LOW){
    lightShow_State = 1;   
  }
}

// ------------- Light Shows (States) ----------------
void LightShow_0() {
  analogWrite(Pin_r1,255);
  analogWrite(Pin_g1,255);
  analogWrite(Pin_b1,255);
}

void LightShow_1() {
  analogWrite(Pin_r1, maxBrightness);
  delay(500);
  analogWrite(Pin_r1, 255);
  analogWrite(Pin_g1, maxBrightness);
  delay(500);
  analogWrite(Pin_g1, 255);
  analogWrite(Pin_b1, maxBrightness);
  delay(500);
  analogWrite(Pin_b1,255);
      
  analogWrite(Pin_r1, maxBrightness);
  delay(500);
  analogWrite(Pin_g1, maxBrightness);
  delay(500);
  analogWrite(Pin_b1, maxBrightness);
  delay(500);
      
  analogWrite(Pin_r1, 255);
  analogWrite(Pin_g1, 255);
  analogWrite(Pin_b1, 255);
}

