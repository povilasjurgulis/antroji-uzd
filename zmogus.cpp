#include "zmogus.h"

Zmogus::Zmogus(string vardas, string pavarde) //Konstruktorius
{ 
    this->vardas = vardas;
    this->pavarde = pavarde;
}

Zmogus::~Zmogus() //Destruktorius
{
    this->vardas.clear();
    this->pavarde.clear();
}

string Zmogus::GetVardas() const 
{ 
    return this->vardas; 
}

string Zmogus::GetPavarde() const 
{ 
    return this->pavarde; 
}

void Zmogus::SetVardas(string vardas) 
{ 
    this->vardas = vardas; 
}

void Zmogus::SetPavarde(string pavarde) 
{ 
    this->pavarde = pavarde; 
}

int Zmogus::GetVardasSize()
{
    return this->vardas.size();
}

int Zmogus::GetPavardeSize()
{
    return this->pavarde.size();
}