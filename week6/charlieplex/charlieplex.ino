

void setup() {
  
}

void loop() {
  
  // LED1 is on
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,INPUT);
  pinMode(5,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  // keep it on for 1 sec
  delay(10);
  
  //LED2 is on
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
  pinMode(3,INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
  delay(10);
  
  //LED3 is on
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,INPUT);
  pinMode(5,INPUT);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  delay(10);
  
  //LED4 is on
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
  pinMode(2,INPUT);
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
  delay(10);

  
}
