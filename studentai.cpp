#include "studentai.h"

Studentas::Studentas(string vardas, string pavarde, int egz, vector <int> nd)
{
    this->vardas = vardas;
    this->pavarde = pavarde;
    this->egz = egz;
    this->nd = nd;
}

Studentas::~Studentas()
{
    this->vardas.clear();
    this->pavarde.clear();
    this->nd.clear();
    this->egz = 0;
    this->galutinis = 0.0;
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
    if(egz < 0 || egz > 10)
    {
        cout << "Egzamino balas turi buti tarp 0 ir 10" << endl;
        return;
    }
    this->egz = egz;
}

void Studentas::SetNd(int &nd)
{
    if(nd < 0 || nd > 10)
    {
        cout << "Namu darbu balai turi buti tarp 0 ir 10" << endl;
        return;
    }
    this->nd.push_back(nd);
}

void Studentas::SetGalutinis(double galutinis)
{
    this->galutinis = galutinis;
}

void Studentas::NdClear()
{
    this->nd.clear();
}

int Studentas::GetVardasSize()
{
    return this->vardas.size();
}

int Studentas::GetPavardeSize()
{
    return this->pavarde.size();
}

void Studentas::SetAllNd(vector<int> nd)
{
    this->nd = nd;
}

void Studentas::CalcVid()
{
    double vidurkis=0.0;
        
    for(int j=0; j<nd.size(); j++)
        vidurkis+=nd[j];
    vidurkis/=nd.size();

    galutinis=0.4*vidurkis+0.6*egz;
}

void Studentas::CalcMed()
{
        //Mediana:
        sort(nd.begin(), nd.end());
        if(nd.size()%2==0)
            galutinis=0.4*(nd[nd.size()/2-1]+nd[nd.size()/2])/2+0.6*egz;
        else
            galutinis=0.4*nd[nd.size()/2]+0.6*egz;
}

void Studentas::Rikiavimas(vector<Studentas>& studentai, int rikiavimas)
{
        switch(rikiavimas) {
            case 1:
                sort(studentai.begin(), studentai.end(),
                     [](const Studentas &a, const Studentas &b){ // Lambda funkcija
                         return a.GetVardas() < b.GetVardas();
                     });
                break;
            case 2:
                sort(studentai.begin(), studentai.end(),
                     [](const Studentas &a, const Studentas &b){
                         return a.GetPavarde() < b.GetPavarde();
                     });
                break;
            case 3:
                sort(studentai.begin(), studentai.end(),
                     [](const Studentas &a, const Studentas &b){
                         return a.GetGalutinis() < b.GetGalutinis();
                     });
                break;
            default: // Kai nei 1, nei 2, nei 3
                cout << "Neteisingas pasirinkimas - nerikiuojame.\n";
                break;
        }
}