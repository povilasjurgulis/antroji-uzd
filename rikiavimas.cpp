#include "deklaracijos.h"
void rikiavimasFun(vector<Studentas>& studentai, int rikiavimas){
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