#include <Servo.h>

// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 
Servo myServo;  // create servo object to control a servo 
 
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 
 
void setup() 
{ 
  myServo.attach(9);  // attaches the servo on pin 9 to the servo object 
  
  Serial.begin(9600);
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
 
  Serial.println(val);                 // print the sensor value to serial monitor
 
  val = map(val, 120, 590, 0, 179);     // scale the sensor value to use it with the servo (value between 0 and 179) 
  val = constrain(val,0,179);          // constrain the "val" to stay between 0 and 179 in case the sensor value goes out of the range
  myServo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 
