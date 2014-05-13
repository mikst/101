/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
int thisTone;
int previousTone;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
   int sensorValue2 = analogRead(A1);
   
   if (sensorValue>10 && sensorValue<200){
     thisTone=1;
   }
   
    if (sensorValue>200 && sensorValue<300){
     thisTone=3;
   }
   if (sensorValue>300 && sensorValue<400){
     thisTone=5;
   }
    if (sensorValue>400 ){
     thisTone=7;
   }
    if (sensorValue2>10 && sensorValue<200){
     thisTone=2;
   }
   
    if (sensorValue2>200 && sensorValue<300){
     thisTone=4;
   }
   
    if (sensorValue2>300 && sensorValue<400){
     thisTone=6;
   }
    if (sensorValue2>400 ){
     thisTone=8;
   }
   
   if (thisTone!= previousTone){
     if (thisTone==1){
       tone(6,350,200);
     }
     if (thisTone==2){
       tone(6,550,200);
     }
     if (thisTone==3){
       tone(6,350,200);
     }
     if (thisTone==4){
       tone(6,550,200);
     }
     if (thisTone==5){
       tone(6,350,200);
     }
     if (thisTone==6){
       tone(6,550,200);
     }
      if (thisTone==7){
       tone(6,350,200);
     }
      if (thisTone==8){
       tone(6,550,200);
     }
     
   }
   previousTone=thisTone;
   
  // print out the value you read:
  Serial.print("sensorValue   ");
   Serial.print(sensorValue);
    Serial.print("   sensorValue2  ");
     Serial.println(sensorValue2);
  delay(100);        // delay in between reads for stability
}
