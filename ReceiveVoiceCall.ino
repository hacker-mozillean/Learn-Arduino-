/*
 Receive Voice Call: This sketch (for Arduino GSM shield) 
 receives voice calls, then displays the calling number,
 waits a few seconds and finally hangs up.

 Circuit:
 * GSM shield
 * Voice circuit
 * SIM card to accept voice calls

 NOTE: Without voice circuit the call will connect,
       but will not send or receive the sound

*/

// Include the GSM library
#include <GSM.h>

// PIN Number
#define PINNUMBER ""

// Initialize the library instance
GSM gsmAccess;
GSMVoiceCall vcs;

// Array to hold the number for the incoming call
char numtel[20];

void setup() {
  // Initialize serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Receive Voice Call");

  // Current Connection state
  boolean notConnected = true;

  // Start the GSM shield. If your SIM has PIN, 
  // pass it as parameter of begin() in quotes
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } 
	else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  // It make sure that modem correctly reports incoming events
  vcs.hangCall();

  Serial.println("Waiting for a call");
}

void loop() {
  // Checks the status of voice call
  switch (vcs.getvoiceCallStatus()) {
    // Nothing is happening. No-one is calling
    case IDLE_CALL: 
      break;
    
	// Yes! Someone is calling us
    case RECEIVINGCALL: 
	  Serial.println("RECEIVING CALL");

      // Retrieve the calling number
      vcs.retrieveCallingNumber(numtel, 20);

      // Print the calling number
      Serial.print("Number:");
      Serial.println(numtel);

      // Answer the call & establish the call
      vcs.answerCall();
      break;

	// The call would be established in this case 
    case TALKING:  
      Serial.println("TALKING. Press enter to hang up.");
      while (Serial.read() != '\n') {
        delay(100);
      }
	  
      vcs.hangCall();
      
	  Serial.println("Hanging up and waiting for the next call.");
      break;
  }
  delay(1000);
}