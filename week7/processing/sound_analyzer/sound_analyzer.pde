/**
  * Live Spectrum to Arduino
  *
  * Run an FFT on live line-in input, splits into 16 frequency bands, and send this data to an Arduino in 16 byte packets.
  * Based on http://processing.org/learning/libraries/forwardfft.html by ddf.
  */
 
import ddf.minim.analysis.*;
import ddf.minim.*;
import processing.serial.*; //library for serial communication
 
Serial port; //creates object "port" of serial class
 
Minim minim;
AudioInput in;
FFT fft;
float[] peaks;

int peak_hold_time = 1;  // how long before peak decays
int[] peak_age;  // tracks how long peak has been stable, before decaying

// how wide each 'peak' band is, in fft bins
int binsperband = 5;
int peaksize; // how many individual peak bands we have (dep. binsperband)
float gain = 40; // in dB
float dB_scale = 2.0;  // pixels per dB

int buffer_size = 1024;  // also sets FFT size (frequency resolution)
float sample_rate = 44100;

int spectrum_height = 176; // determines range of dB shown

int[] freq_array = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int i,g;
float f;

int rectW;
int amp=150; // amplitude of the frequency height

float[] freq_height = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};  //avg amplitude of each freq band

void setup()
{
  size(600, 600);
  
  rectW=width/16;
  background(255);

  minim = new Minim(this);
  port = new Serial(this, Serial.list()[1],9600); //set baud rate
 
  in = minim.getLineIn(Minim.MONO,buffer_size,sample_rate);
 
  // create an FFT object that has a time-domain buffer 
  // the same size as line-in's sample buffer
  fft = new FFT(in.bufferSize(), in.sampleRate());
  // Tapered window important for log-domain display
  fft.window(FFT.HAMMING);

  // initialize peak-hold structures
  peaksize = 1+Math.round(fft.specSize()/binsperband);
  peaks = new float[peaksize];
  peak_age = new int[peaksize];
}


void draw()
{
for(int k=0; k<16; k++){
freq_array[k] = 0;
}

  // perform a forward FFT on the samples in input buffer
  fft.forward(in.mix);
  
// Frequency Band Ranges      
  freq_height[0] = fft.calcAvg((float) 0, (float) 50);
  freq_height[1] = fft.calcAvg((float) 51, (float) 69);
  freq_height[2] = fft.calcAvg((float) 70, (float) 94);
  freq_height[3] = fft.calcAvg((float) 95, (float) 129);
  freq_height[4] = fft.calcAvg((float) 130, (float) 176);
  freq_height[5] = fft.calcAvg((float) 177, (float) 241);
  freq_height[6] = fft.calcAvg((float) 242, (float) 331);
  freq_height[7] = fft.calcAvg((float) 332, (float) 453);
  freq_height[8] = fft.calcAvg((float) 454, (float) 620);
  freq_height[9] = fft.calcAvg((float) 621, (float) 850);
  freq_height[10] = fft.calcAvg((float) 851, (float) 1241);
  freq_height[11] = fft.calcAvg((float) 1242, (float) 1600);
  freq_height[12] = fft.calcAvg((float) 1601, (float) 2200);
  freq_height[13] = fft.calcAvg((float) 2201, (float) 3000);
  freq_height[14] = fft.calcAvg((float) 3001, (float) 4100);
  freq_height[15] = fft.calcAvg((float) 4101, (float) 5600);
  
 
   
   // draw the frequency on the processing screen
   fill(0);
   noStroke();
   rect(rectW*0,height-freq_height[0]*amp,rectW,freq_height[0]*amp);
   rect(rectW*1,height-freq_height[1]*amp,rectW,freq_height[1]*amp);
   rect(rectW*2,height-freq_height[2]*amp,rectW,freq_height[2]*amp);
   rect(rectW*3,height-freq_height[3]*amp,rectW,freq_height[3]*amp);
   rect(rectW*4,height-freq_height[4]*amp,rectW,freq_height[4]*amp);
   rect(rectW*5,height-freq_height[5]*amp,rectW,freq_height[5]*amp);
   rect(rectW*6,height-freq_height[6]*amp,rectW,freq_height[6]*amp);
   rect(rectW*7,height-freq_height[7]*amp,rectW,freq_height[7]*amp);
   rect(rectW*8,height-freq_height[8]*amp,rectW,freq_height[8]*amp);
   rect(rectW*9,height-freq_height[9]*amp,rectW,freq_height[9]*amp);
   rect(rectW*10,height-freq_height[10]*amp,rectW,freq_height[10]*amp);
   rect(rectW*11,height-freq_height[11]*amp,rectW,freq_height[11]*amp);
   rect(rectW*12,height-freq_height[12]*amp,rectW,freq_height[12]*amp);
   rect(rectW*13,height-freq_height[13]*amp,rectW,freq_height[13]*amp);
   rect(rectW*14,height-freq_height[14]*amp,rectW,freq_height[14]*amp);
   rect(rectW*15,height-freq_height[15]*amp,rectW,freq_height[15]*amp);
   
  
   
   fill(255,255,255,25);
   rect(0,0,width,height);

  //send to serial
  port.write(0xff); //write marker (0xff) for synchronization
  
  //after the marker, the frequency information is sent
  for(i=0; i<16; i++){
    freq_array[i]=int(freq_height[i]*amp);
    if (i==13) println(freq_array[i]);
port.write((byte)(freq_array[i]));
  }
  
   
  delay(2); //delay for safety
  
}
 
 
void stop()
{
  // always close Minim audio classes when you finish with them
  in.close();
  minim.stop();
 
  super.stop();
}



