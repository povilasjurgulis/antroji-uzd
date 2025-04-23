#ifndef ZMOGUS_H
#define ZMOGUS_H

#include "main.h"

// Bazine (abstrakti) klase Zmogus is kurios darysime isvestine klase Studentas
class Zmogus{
    protected:
    string vardas, pavarde;
    public:
    Zmogus() : vardas(""), pavarde(""){} // Default konstruktorius
    Zmogus(string vardas, string pavarde) : vardas(vardas), pavarde(pavarde){} // Konstruktorius
    virtual ~Zmogus(){} // Destruktorius
    

};

#endif