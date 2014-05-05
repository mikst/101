/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */


int photocellValue=0;
int buttonValue=0;

int buttonPin=5;
int photocellPin=A4;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // specify the pin mode, is it input or output?
  pinMode(buttonPin,INPUT);
  pinMode(photocellPin,INPUT);
}

// the loop routine runs over and over again forever:
  void loop() {
  // read the input on photocellpin:
  photocellValue = analogRead(photocellPin);
  
    Serial.print("photocell: ");
  Serial.print(photocellValue);
  
  // read the input on buttonPin:
  buttonValue= digitalRead(buttonPin);
  
  // print out the value you read:
  Serial.print("     button: ");
  Serial.println(buttonValue);

  delay(100);        // delay in between reads for stability
}
