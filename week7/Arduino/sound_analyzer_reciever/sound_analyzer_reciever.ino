
int array[16] =    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int i;

int LEDpin=13;

void setup ()
{  
  // open the serial communication
   Serial.begin(9600);
   // set the example LEDpin to output mode
   pinMode(LEDpin,OUTPUT);

}
  
  void loop()
{
 
    
  if(Serial.read() == 0xff){
    for(i=0; i<16; i++){
      array[i] = Serial.read();   
  }
 }

// for example, if frequency between 2201-3000Hz is bigger than 100
  if (array[13]>100){
    // then do the following
    digitalWrite(LEDpin,HIGH);    
  }
  else 
  { // or otherwise do the following
  digitalWrite(LEDpin,LOW);
  }
    
    delay(10); //so you can see the LEDs

}

