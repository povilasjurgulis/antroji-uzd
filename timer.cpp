#include "timer.h"

Timer::Timer(){  
    start = hrClock::now(); 
}

void Timer::reset() {
    start = hrClock::now();
  }

double Timer::elapsed() const{
    return durationDouble(hrClock::now() - start).count();
}
