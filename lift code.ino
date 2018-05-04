
#include <Stepper.h>
#include <math.h>


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(400, 8, 9, 10, 11);


void setup() {
  //set RPM (max 255 I think)
  myStepper.setSpeed(80);
  Serial.begin(9600);
}

void loop() {
  delay(3000);

  int pulses = 6500;
  for (int i=0;i<pulses;i=i+4){
    Serial.println(i);
    myStepper.step(4);
  }
  myStepper.setSpeed(30);
  int pulses2 = 2700;
  for (int i=0;i<pulses2;i=i+4){
    Serial.println(i);
    myStepper.step(4);
  }
    myStepper.setSpeed(5);
  int pulses3 = 200;  
  for (int i=0;i<pulses3;i=i+4){
    Serial.println(i);
    myStepper.step(4);
  }
  while(1);
}
