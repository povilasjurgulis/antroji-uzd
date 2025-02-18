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

using std::cout; using std::cin; using std::endl; using std::string; using std::vector;
using std::fixed; using std::setprecision; using std::setw; using std::left;
using std::sort; using std::numeric_limits; using std::streamsize;
struct Studentas {
    string vardas="", pavarde="";
    int egz=0;
    vector<int> nd;
    double galutinis=0.0;
};
void ivedimas2(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas3(vector<Studentas>& studentai, int& m);
void ivedimas4(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas5(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas6(vector<Studentas>& studentai, int& pasirinkimas);
void ivedimas7(int& pasirinkimas);
#endif