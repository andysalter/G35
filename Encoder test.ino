//Code written by Chris Cameron. 
//Date written 12/03/2015
// The prupse of this code is to demonstrate the use of serial to check code, 
// and to demonstrate the use of the attachInterrupt function with wheel encoders. 

// Be sure to use the following pins for the interupt functions
// interrupt 0 -> pin 2
// interrupt 1 -> pin 3

volatile unsigned long positionL = 0;  //vehicle position count from left encoder
volatile unsigned long positionR = 0;  //vehicle position count from right encoder


void setup() 
{
  Serial.begin(9600); //Starts a serial connection with the computer at a baud rate of 9600. (Don't need to worry about this, just how to do it)
}

void loop() 
{
  
  // Need to reset the encoder values to ensure they start on 0
  positionL=0;
  positionR=0;
  
  // Specify an interrupt service routine to call when an interrupt occurs. Essentially when there is a change of signal on the interrupt pins (2 or 3), it will call the defined function
  // in our case that is encoder1 or encoder2. 
  attachInterrupt(0, encoder1, CHANGE);   
  attachInterrupt(1, encoder2, CHANGE);
  
  while(1) //Will loop here forever.
  {
    Serial.print(positionL); // This prints the current value of positionL in the serial monitor on the computer.
    Serial.print("\t"); // This creates a tab on the monitor 
    Serial.print(positionR);
    Serial.println(); // This creates a new line to print on
    delay(100);
  }
}


// When the interrupt pin is triggered it calls one of the following function. 
// All these do is increment our variables positionR or positionL by 1. 
void encoder1() 
{
  positionR++;
}

void encoder2()
{
  positionL++;
}


