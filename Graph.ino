/*
 Graph is an example of communication from Arduino board to computer.
 The value of analog input 0 is sent out to serial port(Its serial 
 communication because connection appears to both the Arduino and the
 computer as a serial port, even though it may actually use USB cable.
 Bytes are sent one after another (serially) from Arduino to computer.

 You can use the Arduino serial monitor to view the sent data, or it can
 be read by Processing, PD, Max/MSP, or any other program capable of reading
 data from a serial port.  The Processing code below graphs the data received
 so you can see the value of the analog input changing over time.

 The circuit connections are as follows:
 Any analog input sensor attached to analog in pin 0.

 */

void setup() {
  // Initializing the serial communication
  Serial.begin(9600);
}

void loop() {
  // Send the value of analog input 0:
  Serial.println(analogRead(A0));
  
  // Wait 2 sec for analog-to-digital converter to stabilize after last reading
  delay(2);
}

// Program takes ASCII-encoded strings from serial port at 9600 baud and graphs them.
// It expects values in range 0 to 1023, followed by a newline or carriage return

import processing.serial.*;

Serial myPort;        // The serial port
int xPos = 1;         // Horizontal position of the graph
float inByte = 0;

  void setup () {
  size(400, 300); // Setting the window size

  // List out all available Serial ports 
  println(Serial.list());

  // Check which port you're using & open the same
  myPort = new Serial(this, Serial.list()[0], 9600);

  // Don't generate a serialEvent() unless you get newline character
  myPort.bufferUntil('\n');

  // Set inital background
  background(0);
}

void draw () {
  // Draw the line
  stroke(127, 34, 255);
  line(xPos, height, xPos, height - inByte);

  // At the edge of screen, go back to the beginning
  if (xPos >= width) {
    xPos = 0;
    background(0);
  } 
  else {
    // increment the horizontal position:
    xPos++;
  }
}

void serialEvent (Serial myPort) {
  // Get the ASCII string
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // Trim off any whitespaces
    inString = trim(inString);
 
	// Convert to an int and map to the screen height
    inByte = float(inString);
    println(inByte);
    inByte = map(inByte, 0, 1023, 0, height);
  }
}