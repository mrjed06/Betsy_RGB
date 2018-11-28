#include <RGB_LED.h> //library to control individual RGB LEDs (common Cathode)

/*NOTES ON PIN ASSIGNMENT:
12 of the arduino Mega PWM outputs are used to create 4 independent LED Color Signals (3 pins -R, G, and B-  for each LED signal).
In physical terms, 4 different colors can be shown at once across the total number of LEDs. For example, 4 LEDs can show
4 different colors at a given time (one for each LED Color Signal) and 8 LEDs also can also only show 4 different 
colors at a given time (two for each LED Color Signal). 
*/
#define Pin_r1 2 //Color Signal 1 (RED) output pin
#define Pin_g1 3 //Color Signal 1 (GREEN) output pin
#define Pin_b1 4 //Color Signal 1 (BLUE) output pin
#define Pin_r2 5 //Color Signal 2 (RED) output pin
#define Pin_g2 6 //Color Signal 2 (GREEN) output pin
#define Pin_b2 7 //Color Signal 2 (BLUE) output pin
#define Pin_r3 8 //Color Signal 3 (RED) output pin
#define Pin_g3 9 //Color Signal 3 (GREEN) output pin
#define Pin_b3 10 //Color Signal 3 (BLUE) output pin
#define Pin_r4 11 //Color Signal 4 (RED) output pin
#define Pin_g4 12 //Color Signal 4 (GREEN) output pin
#define Pin_b4 13 //Color Signal 4 (BLUE) output pin
byte all_rPins[] = {2,5,8,11}; // group all RED pins into one array
byte all_gPins[] = {3,6,9,12}; //group all GREEN pins into one array
byte all_bPins[] = {4,7,10,13}; //group all BLUE pins into one array
byte all_colorPins[] = {2,3,4,5,6,7,8,9,10,11,12,13}; //group all LED RGB pins into one array (useful for turning all LEDs "off")

#define Pin_button 1 // light show "Mode"Button input pin

// -------- Pin Output Variables -----------
uint8_t maxBrightness; //value 0-255

// --------- Pin Input Variables -----------
bool pinButtonValue; //is "Mode" button being pressed or not?

// ----------- State Variables --------------
uint8_t lightShow_State; //light show's numerical identifier
uint8_t numberOfStates; //constant that equals the number of light shows programmed (including the "ALL LEDs OFF" show)  

//---------LED Classes---------- use with RGB_LED.h library
//RGB_LED LED1(Pin_r1, Pin_g1, Pin_b1);

void setup() {
  pinMode(Pin_button, INPUT_PULLUP); //INPUT_PULLUP connects the pin to 5V with the arduino's built in 20K resistor in between
  
  maxBrightness = 255; //255 is max for common cathode RGB (0 for common anode RGB)
  lightShow_State = 0; //initialize to 0, which is the "All LEDs OFF" state
  numberOfStates = 2; //constant that equals the number of light shows programmed (including the "ALL LEDs OFF" show)
  
  Serial.begin(9600); //for debugging
}

void loop() {
  LightShow_0();
  delay(1000);
  LightShow_1();
  /*if (lightShow_State == 0){
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
   
  }*/
}

// ------------- Light Shows (States) ----------------
void LightShow_0() { //turns all LEDs "off"
  uint16_t n; //declare indexing variable
  
  for (n=0; n<12; n++){
    analogWrite (all_colorPins[n], 0);
  }
}

void LightShow_1() { 
  uint8_t n; //declare indexing variable
  
  for (n=0; n<4; n++){
    analogWrite (all_rPins[n], maxBrightness);
  }
  delay(500);
  for (n=0; n<4; n++){
    analogWrite (all_rPins[n], 0);
  }
  
  for (n=0; n<4; n++){
    analogWrite (all_gPins[n], maxBrightness);
  }
  delay(500);
  for (n=0; n<4; n++){
    analogWrite (all_gPins[n], 0);
  }
  
  for (n=0; n<4; n++){
    analogWrite (all_bPins[n], maxBrightness);
  }
  delay(500);
  for (n=0; n<4; n++){
    analogWrite (all_bPins[n], 0);
  }
      
  for (n=0; n<4; n++){
    analogWrite (all_rPins[n], maxBrightness);
  }
  delay(500);

  for (n=0; n<4; n++){
    analogWrite (all_gPins[n], maxBrightness);
  }
  delay(500);
  
  for (n=0; n<4; n++){
    analogWrite (all_bPins[n], maxBrightness);
  }
  delay(500);
      
for (n=0; n<12; n++){
    analogWrite (all_colorPins[n], 0);
  }
}

