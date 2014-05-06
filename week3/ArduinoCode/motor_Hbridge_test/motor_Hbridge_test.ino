/*
testing H-bridge with DC motor
 L293NE
 */

//assign the pins controlling the H bridge
int EN = 8;
int pin1 = 7;
int pin2 = 6;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(EN, OUTPUT);  
  pinMode(pin1, OUTPUT);  
  pinMode(pin2, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  // Turn Right
  digitalWrite(EN,HIGH);
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  delay(1000);               

  //stop
  digitalWrite(EN,LOW);
  delay(500);   

  // Turn Left
  digitalWrite(EN,HIGH);
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  delay(1000);              

  //stop
  digitalWrite(EN,LOW);
  delay(500);   
}

