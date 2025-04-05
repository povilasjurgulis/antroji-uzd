#include "studentai.h"

Studentas::Studentas(string vardas, string pavarde, int egz, vector <int> nd, double galutinis)
{
    this->vardas = vardas;
    this->pavarde = pavarde;
    this->egz = egz;
    this->nd = nd;
    this->galutinis = galutinis;
}

Studentas::~Studentas()
{
    this->vardas.clear();
    this->pavarde.clear();
    this->nd.clear();
}
