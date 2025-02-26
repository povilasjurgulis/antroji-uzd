#ifndef MAIN_H
#define MAIN_H

//Su vektoriais:
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <chrono>

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
using std::fixed; using std::setprecision; using std::setw; using std::left;
using std::sort; using std::numeric_limits; using std::streamsize;
using std::ifstream; using std::ofstream;
using std::istringstream; using std::getline; 

struct Studentas {
    string vardas="", pavarde="";
    int egz=0;
    vector<int> nd;
    double galutinis=0.0;
};
struct Pasirinkimas{
    int m=0, n=0, pasirinkimas, a=3, b=5, c=0, d=0;
};
vector<Studentas> studentai;
    vector<string> vardai, pavardes;
    Studentas st;
    Pasirinkimas p;
    string randomVyrVardai[20] = {"Povilas", "Eligijus", "Nikita", "Marius", "Justinas", "Karolis", "Arnas", "Matas", "Rokas", 
        "Kristupas", "Justas", "Kajus", "Ovidijus", "Jonas", "Arminas", "Kristijonas", "Eimantas", "Dominykas", "Nerijus", "Gitanas",};
    string randomMotVardai[20] = {"Ieva",  "Justina", "Karolina", "Laura", "Monika", "Neringa", "Sandra", "Simona", "Viktorija", "Emilija", "Lina", "Raminta", 
        "Ana", "Erika", "Inga", "Julija", "Kamila", "Marina", "Nora", "Sofija"};
    string randomVyrPavarde[20] = {"Jurgulis", "Alencikas", "Adamonis", "Bagdonas", "Simutis", "Girdenis", "Janonis", "Kairys", "Kavaliauskas",
        "Kvedaras", "Lapinskas", "Matulis", "Adomauskas", "Noreika", "Petronis", "Ragauskas", "Simonaitis", "Tautkus", "Vasiliauskas", "Zubovas" };
    string randomMotPavarde[20] = {"Adamoniene",  "Bagdonaite", "Daugelaite", "Girdenyte", "Janoniene", "Kairyte", "Kavaliukiene", "Kvedaraite",  "Lapinskiene", 
        "Matuliene", "Morkunaite", "Noreikaite", "Petroniene", "Ragauskaite", "Simonaitiene", "Tautkute", "Vasiliauskiene", "Zuboviene", "Jankauskaite", "Urboniene"};
void ivedimas2(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas3(vector<Studentas>& studentai, int& m);
void ivedimas4(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas5(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas6(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas7(int& pasirinkimas, string a, string b);
void ivedimas8(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas9(vector<Studentas>& studentai, int& pasirinkimas);
#endif