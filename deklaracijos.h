#ifndef DEKLARACIJOS_H
#define DEKLARACIJOS_H

#include "strukturos.h"

extern vector<Studentas> studentai;
extern vector<string> vardai, pavardes;
extern Studentas st;
extern Pasirinkimas p;
extern string randomVyrVardai[20]; 
extern string randomMotVardai[20];
extern string randomVyrPavarde[20];
extern string randomMotPavarde[20]; 
void ivedimas1(int& pasirinkimas, string a, string b, int decider, int o1, int o2);
void ivedimas2(int& pasirinkimas);
void ivedimas3(int& pasirinkimas);
void ifs(Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void rikiavimasFun(vector<Studentas>& studentai, int rikiavimas);
void isvedimasFun(Pasirinkimas p, vector<Studentas>& studentai);
#endif
