
// Graphing sketch


// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return

// Created 20 Apr 2005
// Updated 18 Jan 2008
// by Tom Igoe
// This example code is in the public domain.

import processing.serial.*;

Serial myPort;        // The serial port
  String buff = "";

void setup () {
  // set the window size: width, height
  size(200, 200);   
  // set inital background:
  background(255);  

  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  //myPort.bufferUntil('\n');

}
void draw () {
  // everything happens in the serialEvent()
}

void serialEvent (Serial myPort) {
  int test= myPort.read();

  if (test != 10) {
     // Store all the characters on the line.
    buff += char(test);
    print(test);
  print(" ");
  }
  else {
     buff = buff.substring(0, buff.length()-1);
     int val = Integer.parseInt(buff);
     // Clear the value of "buff"
    buff = "";
    
    print(" sensorInput: ");
    println(val);
  }
  
  
  
  

}


