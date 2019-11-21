#include "ms_us_Timer.h"

mstimer ms_t1(500); //create a 500ms timer
mstimer ms_t2(1000); //create a 1000ms timer
uint8_t i = 0;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

}

void loop() {
  
  if (ms_t1.HasElapsed()) {
    if (i == 50) {
      Serial.println("t1 disabled");
      digitalWrite(13, LOW);
      ms_t1.ResetTime(0); //disable t1. could have also used this function to change the timer period
    }
    else {
      digitalWrite(13, !digitalRead(13));
      Serial.println(digitalRead(13));
    }
    ++i;
  }
  else if (ms_t2.HasElapsed()) {
    Serial.println("t2 triggered!");
  }

}
