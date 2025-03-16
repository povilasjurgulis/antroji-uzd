#include "list_deklaracijos.h"
void rikiavimasFun(list<Studentas>& studentai, int rikiavimas){
switch(rikiavimas) {
    case 1:
        studentai.sort([](const Studentas &a, const Studentas &b){ // Lambda funkcija
                 return a.vardas < b.vardas;
             });
        break;
    case 2:
        studentai.sort([](const Studentas &a, const Studentas &b){
                 return a.pavarde < b.pavarde;
             });
        break;
    case 3:
        studentai.sort([](const Studentas &a, const Studentas &b){
                 return a.galutinis < b.galutinis;
             });
        break;
    default: // Kai nei 1, nei 2, nei 3
        cout << "Neteisingas pasirinkimas - nerikiuojame.\n";
        break;
}
}