/*
 This program prints out byte values in all possible formats:
 * As raw binary values
 * As ASCII-encoded decimal, hex, octal, and binary values

 NOTE:  No external hardware required.

 */
 
void setup() {
  //Initialize serial port and wait for port to open
  Serial.begin(9600);
 
 while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }

  // Prints title with ending line breaks
  Serial.println("ASCII Table ~ Character Map");
}

// The first visible ASCII Character '!' is number 33
int thisByte = 33;

// ASCII characters can be written in single quotes.
//int thisByte = '!'; //'!' is the same as 33

void loop() {
  // It prints value unaltered(i.e. the raw binary version of the byte)
  //The serial monitor interprets all bytes as  ASCII, so 33 will show up as '!'
  Serial.write(thisByte);

  Serial.print(", dec: ");
  // prints value as string as an ASCII-encoded decimal (base 10).
  // Decimal is the  default format for Serial.print() and Serial.println(),
  // so no modifier is needed:
  
  Serial.print(thisByte);
  
  // Declaring modifier for decimal
  Serial.print(thisByte, DEC);

  // Prints value as string in hexadecimal (base 16)
  Serial.print(", hex: ");
  Serial.print(thisByte, HEX);

  // Prints value as string in octal (base 8)
  Serial.print(", oct: ");
  Serial.print(thisByte, OCT);

  // Prints value as string in binary (base 2) and ending line break:
  Serial.print(", bin: ");
  Serial.println(thisByte, BIN);

  // If printed last visible character '~' or 126, then stop the execution
  if (thisByte == 126) {    
  
    // This loop loops forever and does nothing
    while (true) {
      continue;
    }
  } //End of if statement
 
  thisByte++; // Jump to the next character
}