#ifndef ZMOGUS_H
#define ZMOGUS_H

#include "main.h"

// Bazine (abstrakti) klase Zmogus is kurios darysime isvestine klase Studentas
class Zmogus{

    protected:
    string vardas, pavarde;

    public:
    Zmogus() : vardas(""), pavarde(""){} // Default konstruktorius
    Zmogus(string vardas, string pavarde); // Konstruktorius
    virtual ~Zmogus(){} // Destruktorius

    string GetVardas() const; // Grazina varda
    string GetPavarde() const; // Grazina pavarde
    void SetVardas(string vardas); // Nustato varda
    void SetPavarde(string pavarde); // Nustato pavarde
    int GetVardasSize(); // Grazina vardo dydi
    int GetPavardeSize(); // Grazina pavardes dydi

};

#endif