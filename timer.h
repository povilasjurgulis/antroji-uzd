#ifndef TIMER_H
#define TIMER_H

#include "main.h"

class Timer {
    private:
      using hrClock = high_resolution_clock;
      using durationDouble = duration<double>;
      std::chrono::time_point<hrClock> start;
    public:
    Timer();
    void reset();
    double elapsed() const;
  };
#endif