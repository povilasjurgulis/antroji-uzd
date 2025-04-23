#ifndef STUDENTAI_H
#define STUDENTAI_H

#include "zmogus.h"

class Studentas : public Zmogus{

    private:
    int egz;
    vector<int> nd;
    double galutinis;

    public:
    Studentas() : Zmogus(), egz(0), nd {}, galutinis(0){} // Default konstruktorius
    Studentas(string vardas, string pavarde, int egz, vector <int> nd); // Konstruktorius
    ~Studentas(); // Destruktorius
    
    Studentas(const Studentas &naujas); //Copy konstruktorius
    Studentas& operator=(const Studentas& naujas); //Copy priskyrimo operatorius
    Studentas(Studentas&& naujas) noexcept; //Move konstruktorius
    Studentas& operator=(Studentas&& naujas) noexcept; //Move priskyrimo operatorius
    friend istream& operator>>(istream& is, Studentas& studentas); // Ivedimo operatorius
    friend ifstream& operator>>(ifstream& is, Studentas& studentas); // Ivedimo operatorius is failo
    friend ostream& operator<<(ostream& os, const Studentas& studentas); // Isvedimo operatorius
    friend ofstream& operator<<(ofstream& os, const vector<Studentas>& studentai); // Isvedimo operatorius i faila
    friend ostream& operator<<(ostream& os, const vector<Studentas>& studentai); // Isvedimo operatorius i ekrana

    int GetEgz() const; // Grazina egzamino bala
    vector<int> GetNd() const; // Grazina namu darbu balus
    double GetGalutinis() const; // Grazina galutini bala
    void SetEgz(int egz); // Nustato egzamino bala 
    void SetNd(int &nd); // Nustato namu darbu balus
    void SetGalutinis(double galutinis); // Nustato galutini bala
    void NdClear(); // Istrina namu darbu rezultatus
    void SetAllNd(vector<int> nd); // Prideda visus namu darbu balus i vektoriu
    void CalcVid(); // Apskaiciuoja galutini bala pagal vidurki
    void CalcMed(); // Apskaiciuoja galutini bala pagal mediana
    static void Rikiavimas(vector<Studentas>& studentai, int rikiavimas); // Rikiuoja studentus pagal varda, pavarde arba galutini bala
};

#endif