#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
using std::fixed; using std::setprecision; using std::setw; using std::left;
using std::sort; using std::numeric_limits; using std::streamsize;
struct Studentas {
    string vardas="", pavarde="";
    int egz=0;
    vector<int> nd;
    double galutinis=0.0;
};

void ivedimas1(vector<Studentas>& studentai, int& m)
{
    while (true) {
        cout << "Iveskite skaiciu (bent 1, be kablelio): ";
        if (!(cin >> m)) {
            cout << "(Negalima rasyti raidziu ar kableliu!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cin.peek() != '\n') {
            cout << "(Prasome ivesti sveika skaiciu BE kablelio!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (m < 1) {
            cout << "(Skaicius turi buti bent 1!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}

void ivedimas3(vector<Studentas>& studentai, int& pasirinkimas)
{
    while (true) {
        cout << "Pasirinkite: 1 (vidurkis) arba 2 (mediana): ";
            if (!(cin >> pasirinkimas)) {
            cout << "(Negalima rasyti raidziu ar kitokiu simboliu!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cin.peek() != '\n') {
            cout << "(Prasome ivesti sveika skaiciu BE kablelio!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (pasirinkimas != 1 && pasirinkimas != 2) {
            cout << "(Neteisingas skaiciaus pasirinkimas, spauskite 1 arba 2!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}