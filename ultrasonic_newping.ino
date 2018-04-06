// Uses NewPing library with ultrasonic sensor module and a pushbutton 




#include <NewPing.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 500

int inPin = 7;   // choose the input pin (for a pushbutton)
int state = HIGH;
int reading;
int previous = LOW;

 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
void setup() {
   Serial.begin(9600);
   pinMode(inPin, INPUT);
}
 
void loop() {
    reading = digitalRead(inPin);
    if (reading == HIGH && previous == LOW) {
        if (state == HIGH) {
            state = LOW;
        } else {
          state = HIGH;
        }
    }
    if (state == HIGH) {
        delay(50);
        unsigned int uS = sonar.ping_cm();
        Serial.print(uS);
        Serial.println("cm");
    }
    previous = reading;
}
