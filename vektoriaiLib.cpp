#include "main.h"
//Su vektoriais:
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Isvalome ivesties buferi iki naujos eilutes
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
void ivedimas7(int& pasirinkimas)
{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 1 && pasirinkimas != 2) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 1 (pradeti) arba 2 (baigti): ";
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
void ivedimas8(vector<Studentas>& studentai, int& pasirinkimas)
{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 1 (viska paciam rasyti) arba 2 (generuoti tik pazymius), arba 3 (generuoti pazymius, vardus ir pavardes), ";
        cout<<"arba 4 (nuskaityti visus duomenis is failo: )";
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
        if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4) {
            cout << "(Neteisingas skaiciaus pasirinkimas, spauskite 1 arba 2, arba 3, arba 4!)\n";
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
