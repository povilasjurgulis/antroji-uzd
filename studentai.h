#ifndef STUDENTAI_H
#define STUDENTAI_H

#include "main.h"
class Studentas {

    private:
    string vardas, pavarde;
    int egz;
    vector<int> nd;
    double galutinis;

    public:
    Studentas(string vardas, string pavarde, int egz, vector <int> nd, double galutinis); // Konstruktorius
    ~Studentas(); // Destruktorius
};
struct Pasirinkimas{
    int m=0, n=0, pasirinkimas=0, a=3, b=5, c=0, choice=0, e=0, ar_generuoti_failus=0, stud_kiekis=0, kur_isvesti=0, koks_konteineris=0, choice1=0;
  };

#endif