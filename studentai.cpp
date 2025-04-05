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

string Studentas::GetVardas() const
{
    return this->vardas;
}

string Studentas::GetPavarde() const
{
    return this->pavarde;
}

int Studentas::GetEgz() const
{
    return this->egz;
}

vector<int> Studentas::GetNd() const
{
    return this->nd;
}

double Studentas::GetGalutinis() const
{
    return this->galutinis;
}

void Studentas::SetVardas(string vardas)
{
    this->vardas = vardas;
}

void Studentas::SetPavarde(string pavarde)
{
    this->pavarde = pavarde;
}

void Studentas::SetEgz(int egz)
{
    this->egz = egz;
}

void Studentas::SetNd(vector<int> nd)
{
    this->nd = nd;
}

void Studentas::SetGalutinis(double galutinis)
{
    this->galutinis = galutinis;
}


