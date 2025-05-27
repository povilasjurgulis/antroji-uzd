#include <iostream>
#include <vector>
#include "Vector.h"
#include "deklaracijos.h"
#include <iomanip>
void spartos_test()
{
    Timer t1; // Laiko matavimo pradžia
    unsigned int sz = 100000000; //, 1000000, 10000000, 100000000
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i) v1.push_back(i);
    // Baigti v1 užpildymo laiko matavimą
    double elapsed_v1 = t1.elapsed();
    std::cout << "std::vector "<<sz<<" elementu uzpildymo laikas: " << std::fixed << std::setprecision(4) << elapsed_v1 << " s" << std::endl;


    // Pradėti v2 užpildymo laiko matavimą
    Timer t2; // Laiko matavimo pradžia
    Vector<int> v2;
    // v2.reserve(sz);
    for (int i = 1; i <= sz; ++i) v2.push_back(i);
    // Baigti v2 užpildymo laiko matavimą
    double elapsed_v2 = t2.elapsed();
    std::cout << "Vector<int> "<<sz<<" elementu uzpildymo laikas: " << std::fixed << std::setprecision(4) << elapsed_v2 << " s" << std::endl;
};