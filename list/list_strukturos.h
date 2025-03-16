#ifndef LIST_STRUKTUROS_H
#define LIST_STRUKTUROS_H

#include "list_main.h"
struct Studentas {
    string vardas="", pavarde="";
    int egz=0;
    vector<int> nd;
    double galutinis=0.0;
};
struct Pasirinkimas{
    int m=0, n=0, pasirinkimas=0, a=3, b=5, c=0, choice=0, e=0, choice1=0, stud_kiekis=0;
};
class Timer {
    private:
      using hrClock = high_resolution_clock;
      using durationDouble = duration<double>;
      std::chrono::time_point<hrClock> start;
    public:
      Timer() : start{ hrClock::now() } {}
      void reset() {
        start = hrClock::now();
      }
      double elapsed() const {
        return durationDouble (hrClock::now() - start).count();
      }
  };
#endif