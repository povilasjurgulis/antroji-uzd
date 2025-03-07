#ifndef DEKLARACIJOS_LIST_H
#define DEKLARACIJOS_LIST_H

#include "strukturos_list.h"

extern list<Studentas> studentai, kietiakai, nuskriaustukai;
extern list<string> vardai, pavardes;
extern Studentas st;
extern Pasirinkimas p;
extern string randomVyrVardai[20]; 
extern string randomMotVardai[20];
extern string randomVyrPavarde[20];
extern string randomMotPavarde[20]; 
void ivedimas1(int& pasirinkimas, string a, string b, int decider, int o1, int o2);
void file_generavimas(int &n);
void ivedimas2(int& pasirinkimas);
void ivedimas3(int& pasirinkimas);
void ifs(Pasirinkimas p, Studentas st, list<Studentas>& studentai, list<string> vardai, list<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void rikiavimasFun(list<Studentas>& studentai, int rikiavimas);
void isvedimasFun(Pasirinkimas p, list<Studentas> studentai, string failo_pav);
#endif
