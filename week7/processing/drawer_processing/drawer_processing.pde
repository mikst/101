
//  This example code is in the public domain.

import processing.serial.*;

float redValue = 0;        // red value
float greenValue = 0;      // green value
float blueValue = 0;       // blue value
float xPos=0;
float yPos=0;
float last_xPos=0;
float last_yPos=0;

Serial myPort;

void setup() {
  size(400, 400);
  

  // List all the available serial ports
  println(Serial.list());
  // I know that the first port in the serial list on my mac
  // is always my  Arduino, so I open Serial.list()[0].
  // Open whatever port is the one you're using.
  myPort = new Serial(this, Serial.list()[0], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  background(255);
}

void draw() {
  
  // set the stroke color to the sensor value
  stroke(greenValue, blueValue,redValue);
  // thickness of the line
  strokeWeight(4);
  // draw a line between the last x, y position to the current x, y position determined from the sensor value
  line(last_xPos, last_yPos, xPos, yPos);
  // render it in smooth mode
  smooth();
  

  
  // store the current xPos value to last_xPos
  last_xPos=xPos;
  // store the current yPos value to last_yPos
  last_yPos=yPos;

}

void serialEvent(Serial myPort) { 
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // split the string on the commas and convert the 
    // resulting substrings into an integer array:
    float[] colors = float(split(inString, ","));
    // if the array has at least three elements, you know
    // you got the whole thing.  Put the numbers in the
    // color variables:
    if (colors.length >=3) {
      
        redValue = map(colors[0], 0, 1023, 0, 255);
      greenValue = map(colors[1], 0, 1023, 0, 255);
      blueValue = map(colors[2], 0, 1023, 0, 255);
      
      // map the x,yPos from the incoming sensor value
      xPos=map(colors[0], 0, 1023, 0, width);
      yPos=map(colors[1], 0, 1023, 0, height);
    }
  }
}

