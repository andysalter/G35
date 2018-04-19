#include <math.h>

// interupt 0 -> pin 2
// interupt 1 -> pin 3
volatile unsigned long positionL = 0;  //vehicle position count from left encoder
volatile unsigned long positionR = 0;  //vehicle position count from right encoder

// pin declarations
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
  // give some time from power on
  delay(2000);

  //start
  moveFWD_mm(300, 0, 0, 255); //move 300mm with 0 acceleration, max speed
  delay(500);
  turnL(450);
  delay(500);
  moveFWD_mm(500, 300, 0, 255);
  delay(2000);

  while(1);
}
