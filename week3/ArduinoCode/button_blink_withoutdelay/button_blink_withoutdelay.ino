const int buttonPin = 2; // the number of the pushbutton pin
const int ledPin = 13; // the number of the LED pin

// variables will change:
int buttonState = 0; // variable for reading the pushbutton status

int PressCount=0;

int lastButtonState=0;

int LEDstate=LOW;

int t=0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
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
    digitalWrite(ledPin,HIGH);
  }
  
  if (PressCount==2){
    t=t+1;
    
    if (t>1000){
      t=0;
      
    if (LEDstate==HIGH) {
    LEDstate=LOW;
    }
    else{
    LEDstate=HIGH;
    }
    digitalWrite(ledPin,LEDstate);
    
    }
  }

  if (PressCount==3){
    digitalWrite(ledPin,LOW);
    PressCount=0;
  }
    
    
    delay(1);
    
  lastButtonState=buttonState;
}
