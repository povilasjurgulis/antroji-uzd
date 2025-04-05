#ifndef DEKLARACIJOS_H
#define DEKLARACIJOS_H

#include "studentai.h"

extern vector<Studentas> studentai, kietiakai, nuskriaustukai;
extern vector<string> vardai, pavardes;
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
void ifs(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], time_point<high_resolution_clock> &start);
void rikiavimasFun(vector<Studentas>& studentai, int rikiavimas);
void vid_mediana(Studentas &st, Pasirinkimas p);
void isvedimasFun(Pasirinkimas p, vector<Studentas> studentai, string failo_pav, int vard_size, int pav_size);
void file_skaitymas(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, time_point<high_resolution_clock> &start, int *max_vardas_size, int *max_pavarde_size);
#endif
