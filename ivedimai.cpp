#include "deklaracijos.h"
vector<Studentas> studentai;
vector<string> vardai, pavardes;
Studentas st;
Pasirinkimas p;
string randomVyrVardai[20] = {
    "Povilas", "Eligijus", "Nikita", "Marius", "Justinas", "Karolis", "Arnas", "Matas", "Rokas",
    "Kristupas", "Justas", "Kajus", "Ovidijus", "Jonas", "Arminas", "Kristijonas", "Eimantas", "Dominykas", "Nerijus", "Gitanas"
};
string randomMotVardai[20] = {
    "Ieva", "Justina", "Karolina", "Laura", "Monika", "Neringa", "Sandra", "Simona", "Viktorija", "Emilija",
    "Lina", "Raminta", "Ana", "Erika", "Inga", "Julija", "Kamila", "Marina", "Nora", "Sofija"
};
string randomVyrPavarde[20] = {
    "Jurgulis", "Alencikas", "Adamonis", "Bagdonas", "Simutis", "Girdenis", "Janonis", "Kairys", "Kavaliauskas",
    "Kvedaras", "Lapinskas", "Matulis", "Adomauskas", "Noreika", "Petronis", "Ragauskas", "Simonaitis", "Tautkus", "Vasiliauskas", "Zubovas"
};
string randomMotPavarde[20] = {
    "Adamoniene", "Bagdonaite", "Daugelaite", "Girdenyte", "Janoniene", "Kairyte", "Kavaliukiene", "Kvedaraite",
    "Lapinskiene", "Matuliene", "Morkunaite", "Noreikaite", "Petroniene", "Ragauskaite", "Simonaitiene", "Tautkute",
    "Vasiliauskiene", "Zuboviene", "Jankauskaite", "Urboniene"
};
void ivedimas1(int& pasirinkimas, string a, string b, int decider, int o1, int o2)
{
    try{
    if(decider==1)
    {
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != o1 && pasirinkimas != o2) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: "<<o1<<" ("<<a<<") arba "<<o2<<" ("<<b<<"): ";
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
        if (pasirinkimas != o1 && pasirinkimas != o2) {
            cout << "(Neteisingas skaiciaus pasirinkimas, spauskite "<<o1<<"  arba "<<o2<<"!)\n";
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
    else if(decider==0)
    {
        if (cin.fail() || cin.peek() != '\n' || pasirinkimas < 1 || pasirinkimas > 10) 
        {
            cin.clear();  
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        while (true) {
            cout << "Iveskite skaiciu (nuo 1 iki 10 (iskaitant 10), be kablelio): ";
            if (!(cin >> pasirinkimas)) {
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
            if (pasirinkimas < 1 || pasirinkimas > 10) {
                cout << "(Skaicius turi buti bent 1, bet mazesnis (arba lygus) uz 10!)\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }    
    }
}
    }
    catch(const std::exception& e)
    {
        std::cerr << "Įvyko klaida " << '\n'; // e.what()
    }
}

void ivedimas2(int& pasirinkimas)
{
    try{
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
    catch(const std::exception& e)
    {
        std::cerr << "Įvyko klaida " << '\n'; // e.what()
    }
}
void ivedimas3(int& pasirinkimas)
{
    try{
    if (cin.fail() || cin.peek() != '\n' || pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) 
    {
        cin.clear();  
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    while (true) {
        cout << "Pasirinkite: 1 (rikiuoti pagal varda) arba 2 (rikiuoti pagal pavarde), arba 3 (rikiuoti pagal galutini bala): ";
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
        if (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3) {
            cout << "(Neteisingas skaiciaus pasirinkimas, spauskite 1 arba 2, arba 3!)\n";
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
    catch(const std::exception& e)
    {
        std::cerr << "Įvyko klaida " << '\n'; // e.what()
    }
}