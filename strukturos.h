#ifndef STRUKTUROS_H
#define STRUKTUROS_H

#include "main.h"
class Studentas {

    private:
    string vardas, pavarde;
    int egz;
    vector<int> nd;
    double galutinis;

    public:
    Studentas() : egz(0), galutinis(0.0), vardas(""), pavarde("") {}

};
struct Pasirinkimas{
    int m=0, n=0, pasirinkimas=0, a=3, b=5, c=0, choice=0, e=0, ar_generuoti_failus=0, stud_kiekis=0, kur_isvesti=0, koks_konteineris=0, choice1=0;
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