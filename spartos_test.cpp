#include <iostream>
#include <vector>
#include "Vector.h"
#include "deklaracijos.h"
#include <iomanip>
void spartos_test()
{
    Timer t1; // Laiko matavimo pradžia
    unsigned int sz = 100000000; //, 1000000, 10000000, 100000000
    int count = 0;
    std::vector<int> v1;
    for (int i = 1; i <= sz; ++i) 
    {
        if(v1.capacity() == v1.size())
            count++;

        v1.push_back(i);
    }
    cout<<"std::vector capacity() == size()" << " kartu: " << count << endl;
    // Baigti v1 užpildymo laiko matavimą
    double elapsed_v1 = t1.elapsed();
    std::cout << "std::vector "<<sz<<" elementu uzpildymo laikas: " << std::fixed << std::setprecision(4) << elapsed_v1 << " s" << std::endl;


    // Pradėti v2 užpildymo laiko matavimą
    Timer t2; // Laiko matavimo pradžia
    int count2 = 0;
    Vector<int> v2;
    // v2.reserve(sz);
    for (int i = 1; i <= sz; ++i) 
    {
        if(v2.capacity() == v2.size()) 
            count2++;

        v2.push_back(i);      
    }
    cout<<"Vector.h capacity() == size()" << " kartu: " << count2 << endl;
    // Baigti v2 užpildymo laiko matavimą
    double elapsed_v2 = t2.elapsed();
    std::cout << "Vector<int> "<<sz<<" elementu uzpildymo laikas: " << std::fixed << std::setprecision(4) << elapsed_v2 << " s" << std::endl;
};