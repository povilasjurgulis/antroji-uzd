#ifndef LIST_DEKLARACIJOS_H
#define LIST_DEKLARACIJOS_H

#include "list_strukturos.h"

extern list<Studentas> studentai, kietiakai, nuskriaustukai;
extern list<string> vardai, pavardes;
extern Studentas st;
extern Pasirinkimas p;
extern int vard_size, pav_size;
extern string randomVyrVardai[20]; 
extern string randomMotVardai[20];
extern string randomVyrPavarde[20];
extern string randomMotPavarde[20]; 
void ivedimas1(int& pasirinkimas, string a, string b, int decider, int o1, int o2);
void file_generavimas(int &n);
void ivedimas2(int& pasirinkimas);
void ivedimas3(int& pasirinkimas);
void ifs(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, list<Studentas>& studentai, list<string> vardai, list<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], time_point<high_resolution_clock> &start);
void rikiavimasFun(list<Studentas>& studentai, int rikiavimas);
void isvedimasFun(Pasirinkimas p, list<Studentas> studentai, string failo_pav, int vard_size, int pav_size);
void file_skaitymas(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, list<Studentas>& studentai, list<string> vardai, list<string> pavardes, time_point<high_resolution_clock> &start, int *max_vardas_size, int *max_pavarde_size);
#endif
