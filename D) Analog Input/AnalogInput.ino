/*
 This program illustrates analog input by reading an analog sensor on analog pin 0 
 and turning on and off a light LED  connected to digital pin 13.
 
 The amount of time LED will be ON/OFF depends on value obtained by analogRead().

 The connections are as follows:
 * Potentiometer attached to analog input 0
 * Center pin of the Potentiometer to the analog pin
 * One side pin (either one) to the ground
 * The other side of the pin to +5V
 * LED anode (longer leg) attached to digital output 13
 * LED cathode (short leg) attached to ground

*/

int sensorPin = A0;   // Selects the input pin for the potentiometer
int ledPin = 13;      // Selects the pin for the LED
int sensorValue = 0;  // Variable for storing value coming from the sensor

void setup() {
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT:
}

void loop() {
  // Read value from sensor
  sensorValue = analogRead(sensorPin);
  
  // Turn ledPin ON
  digitalWrite(ledPin, HIGH);
  
  // Stop program for <sensorValue> milliseconds
  delay(sensorValue);
  
  // Turn the ledPin off
  digitalWrite(ledPin, LOW);
  
  // Stop program for <sensorValue> milliseconds
  delay(sensorValue);
}