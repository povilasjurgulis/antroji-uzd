#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

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
    if (cin.fail() || cin.peek() != '\n' || m < 1)
    {
        // Clear any fail bits or leftover if user typed something invalid (e.g. 1.2)
        cin.clear(); // Clear the fail bit  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer (any invalid input)
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
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ivedimas2(vector<Studentas>& studentai, int& pasirinkimas)
{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 1 && pasirinkimas != 2) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 1 (vidurkis) arba 2 (mediana): ";
            if (!(cin >> pasirinkimas)) {
            cout << "(Negalima rasyti raidziu ar kitokiu simboliu!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cin.peek() != '\n') { //Jeigu po pirmojo skaiciaus dar kazkas yra, tarkim kablelis ar taskas ar kitas skaicius, tai netinka
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
        else
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ivedimas3(vector<Studentas>& studentai, int& m)
{
    if (cin.fail() || cin.peek() != '\n' || m < 1 || m > 10) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Iveskite skaiciu (nuo 1 iki 10 (iskaitant 10), be kablelio): ";
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
        if (m < 1 || m > 10) {
            cout << "(Skaicius turi buti bent 1, bet mazesnis (arba lygus) uz 10!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}
    else
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ivedimas4(vector<Studentas>& studentai, int& pasirinkimas)
{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 3 && pasirinkimas != 4) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 3 (rasyti daugiau) arba 4 (nutraukti): ";
            if (!(cin >> pasirinkimas)) {
            cout << "(Negalima rasyti raidziu ar kitokiu simboliu!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cin.peek() != '\n') { //Jeigu po pirmojo skaiciaus dar kazkas yra, tarkim kablelis ar taskas ar kitas skaicius, tai netinka
            cout << "(Prasome ivesti sveika skaiciu BE kablelio!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (pasirinkimas != 3 && pasirinkimas != 4) {
            cout << "(Neteisingas skaiciaus pasirinkimas, spauskite 3 arba 4!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}
        else
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ivedimas5(vector<Studentas>& studentai, int& pasirinkimas)
{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 5 && pasirinkimas != 6) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 5 (rasyti daugiau) arba 6 (nutraukti): ";
            if (!(cin >> pasirinkimas)) {
            cout << "(Negalima rasyti raidziu ar kitokiu simboliu!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cin.peek() != '\n') { //Jeigu po pirmojo skaiciaus dar kazkas yra, tarkim kablelis ar taskas ar kitas skaicius, tai netinka
            cout << "(Prasome ivesti sveika skaiciu BE kablelio!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (pasirinkimas != 5 && pasirinkimas != 6) {
            cout << "(Neteisingas skaiciaus pasirinkimas, spauskite 5 arba 6!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}
        else
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void ivedimas6(vector<Studentas>& studentai, int& pasirinkimas)
{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 1 && pasirinkimas != 2) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 1 (sugeneruoti) arba 2 (paciam rasyti): ";
            if (!(cin >> pasirinkimas)) {
            cout << "(Negalima rasyti raidziu ar kitokiu simboliu!)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (cin.peek() != '\n') { //Jeigu po pirmojo skaiciaus dar kazkas yra, tarkim kablelis ar taskas ar kitas skaicius, tai netinka
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
        else
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
#endif