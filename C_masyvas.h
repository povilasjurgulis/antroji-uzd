#ifndef C_MASYVAS_H
#define C_MASYVAS_H

//Su masyvais:
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

struct CStudentas {
    string vardas="", pavarde="";
    int egz=0;
    int *nd=nullptr;
    int nd_size=0;
    double galutinis=0.0;
    CStudentas(int nd1=0) {
        if(nd1>0)
        {
        nd = new int[nd1];
        nd_size = nd1;
        }
    }
};
void resize(CStudentas& st, int newSize);
void ivedimas2(vector<CStudentas>& studentai, int& pasirinkimas);
void ivedimas3(vector<CStudentas>& studentai, int& m);
void ivedimas4(vector<CStudentas>& studentai, int& pasirinkimas);
void ivedimas5(vector<CStudentas>& studentai, int& pasirinkimas);
void ivedimas6(vector<CStudentas>& studentai, int& pasirinkimas);
void ivedimas7(int& pasirinkimas);
#endif