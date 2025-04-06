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
    Studentas() : vardas(""), pavarde(""), egz(0), nd {}, galutinis(0) {} // Default konstruktorius
    Studentas(string vardas, string pavarde, int egz, vector <int> nd); // Konstruktorius
    ~Studentas(); // Destruktorius

    string GetVardas() const; // Grazina varda
    string GetPavarde() const; // Grazina pavarde
    int GetEgz() const; // Grazina egzamino bala
    vector<int> GetNd() const; // Grazina namu darbu balus
    double GetGalutinis() const; // Grazina galutini bala
    void SetVardas(string vardas); // Nustato varda
    void SetPavarde(string pavarde); // Nustato pavarde
    void SetEgz(int egz); // Nustato egzamino bala 
    void SetNd(int *nd); // Nustato namu darbu balus
    void SetGalutinis(double galutinis); // Nustato galutini bala
    void NdClear(); // Istrina namu darbu rezultatus
    int GetVardasSize(); // Grazina vardo dydi
    int GetPavardeSize(); // Grazina pavardes dydi
    void PushBackAllNd(vector<int> nd); // Prideda visus namu darbu balus i vektoriu
    void Calc_vid(); // Apskaiciuoja galutini bala pagal vidurki
    void Calc_med(); // Apskaiciuoja galutini bala pagal mediana
    static void Rikiavimas(vector<Studentas>& studentai, int rikiavimas); // Rikiuoja studentus pagal varda, pavarde arba galutini bala
};


#endif