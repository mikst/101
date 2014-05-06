int RedPin=11;
int BluePin=9;
int GreenPin=10;

int sensorPin=A0;
int sensorVal=0;

int outputValue=0;

int R_intensity=0;
int G_intensity=0;
int B_intensity=0;


void setup() {
  pinMode(RedPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
  pinMode(GreenPin,OUTPUT); 
  
  Serial.begin(9600);
}

void loop() { 
  // read sensor as analogRead
  sensorVal=analogRead(sensorPin);
  outputValue=map(sensorVal, 0, 1023,0,765);
 
  // apply the light intensity to each color with analogWrite
    // map the sensor input value to light intensity
  
  if (outputValue<255){
  R_intensity=constrain(outputValue,0,255);
  }
  else R_intensity=0;
  analogWrite(RedPin,R_intensity);
  
  if (outputValue<510){
  G_intensity=constrain(outputValue-255,0,255);
  } else G_intensity=0;
  analogWrite(BluePin,G_intensity);
  
 
   B_intensity=constrain(outputValue-510,0,255);
  analogWrite(GreenPin,B_intensity);
  
  Serial.println(sensorVal);
  
  delay(1);

}


