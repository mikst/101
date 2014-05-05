/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2. 
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
int led = 9;           // the pin that the LED is attached to

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int PressCount=0;

int lastButtonState=0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     
}

void loop(){


  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);



  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (lastButtonState != buttonState){
    if (buttonState == HIGH) {     
      // count up PressCount   
      PressCount = PressCount+1; 
    } 

  }


  if (PressCount == 1){
    brightness = brightness + fadeAmount;
    if (brightness > 255) {
      fadeAmount = -5 ; 
    }  
    else{
      // set the brightness of pin 9:
      brightness=constrain(brightness, 0,255);
      analogWrite(led, brightness);
    }
  }

  if (PressCount==2){
    if (brightness < 0 ) {
      fadeAmount = 5 ; 
      PressCount=0;
    }
    else{
      // set the brightness of pin 9:
      brightness=constrain(brightness, 0,255);
      analogWrite(led, brightness);
    }


  }




  lastButtonState=buttonState;
}

