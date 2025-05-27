#ifndef STUDENTAI_H
#define STUDENTAI_H

#include "zmogus.h"
#include <stdexcept>


class Studentas : public Zmogus{

    private:
    int egz;
    Vector<int> nd;
    double galutinis;

    public:
    Studentas() : Zmogus(), egz(0), nd {}, galutinis(0){} // Default konstruktorius
    Studentas(const std::string& v, const std::string& p, int egz, const Vector<int>& nd_vec); // Konstruktorius
    ~Studentas(); // Destruktorius
    
    Studentas(const Studentas &naujas); //Copy konstruktorius
    Studentas& operator=(const Studentas& naujas); //Copy priskyrimo operatorius
    Studentas(Studentas&& naujas) noexcept; //Move konstruktorius
    Studentas& operator=(Studentas&& naujas) noexcept; //Move priskyrimo operatorius
    friend istream& operator>>(istream& is, Studentas& studentas); // Ivedimo operatorius
    friend ifstream& operator>>(ifstream& is, Studentas& studentas); // Ivedimo operatorius is failo
    friend ostream& operator<<(ostream& os, const Studentas& studentas); // Isvedimo operatorius
    friend ofstream& operator<<(ofstream& os, const Vector<Studentas>& studentai); // Isvedimo operatorius i faila
    friend ostream& operator<<(ostream& os, const Vector<Studentas>& studentai); // Isvedimo operatorius i ekrana

    int GetEgz() const; // Grazina egzamino bala
    Vector<int> GetNd() const; // Grazina namu darbu balus
    double GetGalutinis() const; // Grazina galutini bala
    void SetEgz(int egz); // Nustato egzamino bala 
    void SetNd(int &nd); // Nustato namu darbu balus
    void SetNd(const Vector<int>& nd); // Nustato namu darbu balus
    void SetGalutinis(double galutinis); // Nustato galutini bala
    void NdClear(); // Istrina namu darbu rezultatus
    void SetAllNd(Vector<int> &nd); // Prideda visus namu darbu balus i vektoriu
    void CalcVid(); // Apskaiciuoja galutini bala pagal vidurki
    void CalcMed(); // Apskaiciuoja galutini bala pagal mediana
    static void Rikiavimas(Vector<Studentas>& studentai, int rikiavimas); // Rikiuoja studentus pagal varda, pavarde arba galutini bala
    void Spausdinti(std::ostream&) const override; // Isvedimo funkcija
};

#endif