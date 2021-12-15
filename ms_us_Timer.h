#ifndef	MS_US_TIMER_H
#define	MS_US_TIMER_H

/*ms timer using macro with example

  #define msTimer(x)  for(static unsigned long pm = millis(); millis() - pm >= x; pm = millis())

  msTimer(500) {
    digitalWrite(13, !digitalRead(13));
    Serial.print("Blink @ ");
    Serial.println(millis());
  }

*/

//millisecond non-blocking timer class using millis()
class mstimer {
  private:
    unsigned long _oldtime;
    unsigned long _period;

  public:
    //returns if period has elapsed or not
    inline uint8_t HasElapsed()
    {
      if (_period > 0 && millis() - _oldtime >= _period) {
        _oldtime = millis();
        return 1;
      }
      
      return 0;
    }

    //update period
    inline void ResetTime(unsigned long period) {
      //using setTime to set period=0 essentially stops the instated timer
      _period = period;
      _oldtime = millis();
    }

    //constructor
    mstimer(unsigned long period = 0)
    {
      _oldtime = millis();
      _period = period;
    }

    //deconstructor
    ~mstimer() {}
};

//microsecond non-blocking timer class using micros()
class ustimer {
  private:
    unsigned long _oldtime;
    unsigned long _period;

  public:
    //returns if time has elapsed or not
    inline uint8_t HasElapsed()
    {
      if (_period > 0 && micros() - _oldtime >= _period) {
        _oldtime = micros();
        return 1;
      }
      
      return 0;
    }

    //update period
    inline void ResetTime(unsigned long period) {
      //using setTime to set period=0 essentially stops the instated timer
      _period = period;
      _oldtime = micros();
    }

    //constructor
    ustimer(unsigned long period = 0)
    {
      _oldtime = micros();
      _period = period;
    }

    //deconstructor
    ~ustimer() {}
};

#endif
