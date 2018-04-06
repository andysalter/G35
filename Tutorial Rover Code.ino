

// interupt 0 -> pin 2
// interupt 1 -> pin 3

volatile unsigned long positionL = 0;  //vehicle position count from left encoder
volatile unsigned long positionR = 0;  //vehicle position count from right encoder

int motorLa = 5;
int motorLb = 6;
int dirLa = 4;
int dirLb = 7;
int motorRa = 9;
int motorRb = 10;
int dirRa = 8;
int dirRb = 11;

void setup()
{
  pinMode (motorLa, OUTPUT);
  pinMode (motorLb, OUTPUT);
  pinMode (dirLa, OUTPUT);
  pinMode (dirLb, OUTPUT);
  pinMode (motorRa, OUTPUT);
  pinMode (motorRb, OUTPUT);
  pinMode (dirRa, OUTPUT);
  pinMode (dirRb, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  moveFWD(1000);
  delay(1000);
  turnL(550);
  delay(1000);
  moveFWD(1000);
  delay(1000);
  turnL(550);
  delay(1000);
  moveFWD(1000);
  delay(1000);
  turnL(550);
  delay(1000);
  moveFWD(1000);
  delay(1000);
  turnL(550);


  while(1);
}

void encoder1()
{
  positionR++;
}

void encoder2()
{
  positionL++;
}

void moveFWD(unsigned int x)
{
  positionL=0;
  positionR=0;
  attachInterrupt(1, encoder1, CHANGE);
  attachInterrupt(0, encoder2, CHANGE);
  digitalWrite(dirLa, HIGH); // Left a Forward
  digitalWrite(dirLb, LOW); // Left b Forward
  digitalWrite(dirRa, HIGH); //Right a Forward
  digitalWrite(dirRb, LOW); //Right b Forward

  while((positionL <= x) || (positionR <= x))
  {

    if (positionL > positionR)
    {
      analogWrite(motorLa, 20);
      analogWrite(motorLb, 20);
      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }

    else if (positionR > positionL)
    {
      analogWrite(motorRa, 20);
      analogWrite(motorRb, 20);
      analogWrite(motorLa, 200); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 200);
    }

    else
    {
      analogWrite(motorLa, 200); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 200);

      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }



    Serial.print(positionL); // This prints the current value of positionL in the serial monitor on the computer.
    Serial.print("\t"); // This creates a tab on the monitor
    Serial.print(positionR);
    Serial.println(); // This creates a new line to print on

  }


  // Stop all motors
  analogWrite(motorLa, 0);
  analogWrite(motorLb, 0);
  analogWrite(motorRa, 0);
  analogWrite(motorRb, 0);

  // Disables the encoders interrupt
  detachInterrupt(0);
  detachInterrupt(1);
}

void moveREV(unsigned int x)
{
  positionL=0;
  positionR=0;
  attachInterrupt(0, encoder1, CHANGE);
  attachInterrupt(1, encoder2, CHANGE);
  digitalWrite(dirLa, LOW); // Left a Forward
  digitalWrite(dirLb, HIGH); // Left b Forward
  digitalWrite(dirRa, LOW); //Right a Forward
  digitalWrite(dirRb, HIGH); //Right b Forward

  while((positionL <= x) || (positionR <= x))
  {

    if (positionL > positionR)
    {
      analogWrite(motorLa, 20);
      analogWrite(motorLb, 20);
      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }

    else if (positionR > positionL)
    {
      analogWrite(motorRa, 20);
      analogWrite(motorRb, 20);
      analogWrite(motorLa, 180); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 180);
    }

    else
    {
      analogWrite(motorLa, 180); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 180);

      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }



    Serial.print(positionL); // This prints the current value of positionL in the serial monitor on the computer.
    Serial.print("\t"); // This creates a tab on the monitor
    Serial.print(positionR);
    Serial.println(); // This creates a new line to print on

  }


  // Stop all motors
  analogWrite(motorLa, 0);
  analogWrite(motorLb, 0);
  analogWrite(motorRa, 0);
  analogWrite(motorRb, 0);

  // Disables the encoders interrupt
  detachInterrupt(0);
  detachInterrupt(1);
}

void turnL(unsigned int x)
{
  positionL=0;
  positionR=0;
  attachInterrupt(1, encoder1, CHANGE);
  attachInterrupt(0, encoder2, CHANGE);
  digitalWrite(dirLa, LOW); // Left a Forward
  digitalWrite(dirLb, HIGH); // Left b Forward
  digitalWrite(dirRa, HIGH); //Right a Forward
  digitalWrite(dirRb, LOW); //Right b Forward

  while((positionL <= x) || (positionR <= x))
  {

    if (positionL > positionR)
    {
      analogWrite(motorLa, 20);
      analogWrite(motorLb, 20);
      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }

    else if (positionR > positionL)
    {
      analogWrite(motorRa, 20);
      analogWrite(motorRb, 20);
      analogWrite(motorLa, 180); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 180);
    }

    else
    {
      analogWrite(motorLa, 180); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 180);

      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }



    Serial.print(positionL); // This prints the current value of positionL in the serial monitor on the computer.
    Serial.print("\t"); // This creates a tab on the monitor
    Serial.print(positionR);
    Serial.println(); // This creates a new line to print on

  }


  // Stop all motors
  analogWrite(motorLa, 0);
  analogWrite(motorLb, 0);
  analogWrite(motorRa, 0);
  analogWrite(motorRb, 0);

  // Disables the encoders interrupt
  detachInterrupt(0);
  detachInterrupt(1);
}

void turnR(unsigned int x)
{
  positionL=0;
  positionR=0;
  attachInterrupt(1, encoder1, CHANGE);
  attachInterrupt(0, encoder2, CHANGE);
  digitalWrite(dirLa, HIGH); // Left a Forward
  digitalWrite(dirLb, LOW); // Left b Forward
  digitalWrite(dirRa, LOW); //Right a Forward
  digitalWrite(dirRb, HIGH); //Right b Forward

  while((positionL <= x) || (positionR <= x))
  {

    if (positionL > positionR)
    {
      analogWrite(motorLa, 20);
      analogWrite(motorLb, 20);
      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }

    else if (positionR > positionL)
    {
      analogWrite(motorRa, 20);
      analogWrite(motorRb, 20);
      analogWrite(motorLa, 180); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 180);
    }

    else
    {
      analogWrite(motorLa, 180); // Sets the motor speed at a value of 180
      analogWrite(motorLb, 180);

      analogWrite(motorRa, 180);
      analogWrite(motorRb, 180);
    }



    Serial.print(positionL); // This prints the current value of positionL in the serial monitor on the computer.
    Serial.print("\t"); // This creates a tab on the monitor
    Serial.print(positionR);
    Serial.println(); // This creates a new line to print on

  }


  // Stop all motors
  analogWrite(motorLa, 0);
  analogWrite(motorLb, 0);
  analogWrite(motorRa, 0);
  analogWrite(motorRb, 0);

  // Disables the encoders interrupt
  detachInterrupt(0);
  detachInterrupt(1);
}
