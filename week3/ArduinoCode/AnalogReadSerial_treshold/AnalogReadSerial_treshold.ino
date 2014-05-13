/*
  AnalogReadSerial + threshold
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
  If the sensor value is smaller than threashold value, it turns on the switch to SMA (shape memory alloy)
  we used mosFET IRLB8743 for transistor switch N type.
  
  D9 to Gate of the mosFET
  SMA to Drain of the mosFET
  GND to SOuce of the mosFET
  
 This example code is in the public domain.
 */
int sensorValue=0;
int SMA=9;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(SMA,OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  
  // if the sensorValue is smaller than 550 (threashold)
  if (sensorValu5 > 550){
    //Turn on the SMA pin
    digitalWrite(SMA,HIGH);
    // and wait for 1 sec
    delay(1000);
    // turn off the SMA pin
    digitalWrite(SMA,LOW);
  }
  else{ //otherwise
    // do nothing
  }
  
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);        // delay in between reads for stability
}
