#include "studentai.h"
#include <cassert>
#include <cmath>
#include <sstream>
#include <iostream>
#include <algorithm>

// Pagalbine funkcija double palyginimui
static bool double_equal(double a, double b, double eps = 1e-6) {
    return std::fabs(a - b) < eps;
}

// Minimalus assert makro, kaupiantis statistika
static int passes = 0;
static int fails  = 0;
#define ASSERT_TRUE(cond, msg)                                                     \
    do {                                                                           \
        if (!(cond)) {                                                             \
            std::cerr << "[FAIL] " << msg << std::endl;                           \
            ++fails;                                                               \
        } else {                                                                  \
            ++passes;                                                              \
        }                                                                          \
    } while (0)

static void Summary() {
    std::cout << "[ OK ]    " << passes << " / " << passes + fails << " tests passed";
    if (fails == 0) std::cout << " ALL PASSED!";
    std::cout << std::endl;
}

void RunTests() {
    passes = fails = 0; // reset

    // Default ctor
    Studentas s0;
    ASSERT_TRUE(s0.GetVardas() == "" && s0.GetPavarde() == "", "Default ctor: strings tusti");
    ASSERT_TRUE(s0.GetEgz() == 0 && double_equal(s0.GetGalutinis(), 0.0), "Default ctor: skaiciai 0");

    // Parametrinis ctor
    Studentas s1("Jonas", "Jonaitis", 9, {10, 9, 8});
    ASSERT_TRUE(s1.GetVardas() == "Jonas" && s1.GetPavarde() == "Jonaitis", "Param ctor: vardas / pavarde");

    // Copy ctor
    Studentas s2(s1);
    ASSERT_TRUE(s2.GetEgz() == 9 && s2.GetNd() == s1.GetNd(), "Copy ctor: duomenys identiski");

    // Move ctor
    Studentas tmp("Petras", "Petraitis", 8, {7, 7, 7});
    size_t nd_count = tmp.GetNd().size();
    Studentas moved(std::move(tmp));
    ASSERT_TRUE(moved.GetEgz() == 8 && moved.GetNd().size() == nd_count, "Move ctor: perkelti duomenys");

    // Copy assignment
    Studentas assign;
    assign = s1;
    ASSERT_TRUE(assign.GetVardas() == "Jonas" && assign.GetEgz() == 9, "Copy assignment veikia");

    // Move assignment
    Studentas tmp2("Ona", "Onute", 6, {6, 6});
    assign = std::move(tmp2);
    ASSERT_TRUE(assign.GetVardas() == "Ona" && assign.GetEgz() == 6, "Move assignment veikia");

    // Setteriai
    assign.SetVardas("Maryte");
    assign.SetPavarde("Marytaite");
    int ndv = 10;
    assign.SetNd(ndv);
    assign.SetEgz(10);
    ASSERT_TRUE(assign.GetVardas() == "Maryte" && assign.GetNd().back() == 10, "Setteriai veikia");

    // CalcVid
    Studentas vid("A", "B", 10, {10, 10, 10});
    vid.CalcVid();
    ASSERT_TRUE(double_equal(vid.GetGalutinis(), 10.0), "CalcVid teisingas (vidurkis)");

    // CalcMed (nelyginis)
    Studentas med("C", "D", 10, {9, 9, 9});
    med.CalcMed();
    ASSERT_TRUE(double_equal(med.GetGalutinis(), 0.4 * 9 + 0.6 * 10), "CalcMed teisingas (nelyginis)");

    // CalcMed (lyginis)
    Studentas med2("E", "F", 10, {8, 9, 10, 10});
    med2.CalcMed();
    double expected = 0.4 * ((9 + 10) / 2.0) + 0.6 * 10;
    ASSERT_TRUE(double_equal(med2.GetGalutinis(), expected), "CalcMed teisingas (lyginis)");

    // NdClear
    med2.NdClear();
    ASSERT_TRUE(med2.GetNd().empty(), "NdClear isvalo vektoriu");

    // Rikiavimas pagal varda
    std::vector<Studentas> vec = {s1, moved, assign};
    Studentas::Rikiavimas(vec, 1);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end(), [](const Studentas &a, const Studentas &b){ return a.GetVardas() < b.GetVardas(); }), "Rikiavimas pagal varda");

    // Rikiavimas pagal pavardw
    Studentas::Rikiavimas(vec, 2);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end(), [](const Studentas &a, const Studentas &b){ return a.GetPavarde() < b.GetPavarde(); }), "Rikiavimas pagal pavarde");

    // Rikiavimas pagal galutini
    Studentas::Rikiavimas(vec, 3);
    ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end(), 
    [](const Studentas &a, const Studentas &b){ return a.GetGalutinis() < b.GetGalutinis(); }), "Rikiavimas pagal galutini bala");

    // operator<<
    std::stringstream ss;
    ss << s1;
    ASSERT_TRUE(ss.str().find("Jonas") != std::string::npos, "operator<< isveda varda");

    // Suvestine
    Summary();
}