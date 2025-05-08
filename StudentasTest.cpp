// StudentasTest_doctest.cpp
// Vienetiniai testai Studentas klasei naudojant doctest (header‑only)
// ---------------------------------------------------------------
// • Kompiliuoti (be CMake):
//     g++ -std=c++17 -Idoctest \
//         StudentasTest.cpp studentai.cpp zmogus.cpp \
//         -o studentas_tests
// • Arba CMake:
//     add_library(doctest INTERFACE)
//     target_include_directories(doctest INTERFACE ${CMAKE_SOURCE_DIR}/doctest)
//     add_executable(studentas_tests StudentasTest.cpp)
//     target_link_libraries(studentas_tests PRIVATE doctest)
// ---------------------------------------------------------------

#define DOCTEST_CONFIG_IMPLEMENT  // nesugeneruoja int main()
#include "doctest.h"
#include "studentai.h"

using std::vector;

// Pagalbinė funkcija – laukiamas galutinis balas pagal VIDURKĮ
static double ExpectedGalutinisVid(const vector<int>& nd, int egz)
{
    if (nd.empty()) return 0.6 * egz;
    double sum = 0.0;
    for (int n : nd) sum += n;
    double vid = sum / nd.size();
    return 0.4 * vid + 0.6 * egz;
}

// Pagalbinė funkcija – MEDIANA (lyginiam kiekiui – vidurkis dviejų vidurinių)
static double Median(vector<int> nd)
{
    if (nd.empty()) return 0.0;
    std::sort(nd.begin(), nd.end());
    size_t n = nd.size();
    if (n % 2) return nd[n / 2];
    return (nd[n / 2 - 1] + nd[n / 2]) / 2.0;
}

static double ExpectedGalutinisMed(const vector<int>& nd, int egz)
{
    return 0.4 * Median(nd) + 0.6 * egz;
}

//------------------------------------------------------------------
// 1. Konstruktoriai
//------------------------------------------------------------------

TEST_CASE("Default constructor initializes with zeros" "[constructor][default]") {
    Studentas s;
    CHECK_EQ(s.GetEgz(), 0);
    CHECK(s.GetNd().empty());
    CHECK_EQ(s.GetGalutinis(), doctest::Approx(0.0));
}

TEST_CASE("Parameterized constructor stores values" "[constructor][param]") {
    vector<int> paz = {5, 8, 7};
    Studentas stud{"Vardenis", "Pavardenis", 5, paz};

    CHECK_EQ(stud.GetEgz(), 5);
    CHECK(stud.GetNd() == paz);
    // Kol neapskaičiuotas, galutinis balas turi būti 0
    CHECK_EQ(stud.GetGalutinis(), doctest::Approx(0.0));
}

TEST_CASE("Copy constructor copies everything" "[constructor][copy]") {
    Studentas orig{"A", "B", 10, {9, 9, 10}};
    Studentas copy{orig};
    CHECK(copy.GetNd() == orig.GetNd());
    CHECK_EQ(copy.GetEgz(), orig.GetEgz());
}

TEST_CASE("Move constructor leaves source empty" "[constructor][move]") {
    Studentas tmp{"C", "D", 6, {7, 7}};
    Studentas moved{std::move(tmp)};
    CHECK(moved.GetNd().size() == 2);
    CHECK(tmp.GetNd().empty()); // šaltinis turi būti tuščias
}

//------------------------------------------------------------------
// 2. Skaičiavimai
//------------------------------------------------------------------

TEST_CASE("CalcVid computes correct final grade" "[calc][vid]") {
    vector<int> nd = {8, 9, 10};
    Studentas s{"Jonas", "Jonaitis", 6, nd};
    s.CalcVid();

    double expected = ExpectedGalutinisVid(nd, 6);
    CHECK_EQ(s.GetGalutinis(), doctest::Approx(expected));
}

TEST_CASE("CalcMed computes correct final grade" "[calc][med]") {
    vector<int> nd = {8, 10, 10, 6}; // mediana = (8+10)/2 = 9
    Studentas s{"Jonas", "Jonaitis", 7, nd};
    s.CalcMed();

    double expected = ExpectedGalutinisMed(nd, 7);
    CHECK_EQ(s.GetGalutinis(), doctest::Approx(expected));
}

//------------------------------------------------------------------
// 3. Valdymo metodai SetEgz / SetNd / NdClear
//------------------------------------------------------------------

TEST_CASE("SetEgz rejects out-of-range values" "[set]") {
    Studentas s;
    CHECK_THROWS_AS(s.SetEgz(11), std::out_of_range);
    CHECK_THROWS_AS(s.SetEgz(-1), std::out_of_range);
}

TEST_CASE("SetNd replaces vector and NdClear empties it" "[set][vector]") {
    Studentas s;
    vector<int> paz = {4, 6};
    s.SetNd(paz);
    CHECK(s.GetNd() == paz);

    s.NdClear();
    CHECK(s.GetNd().empty());
}

int RunDocTests(int argc = 0, char** argv = nullptr) {
    doctest::Context ctx;
    ctx.applyCommandLine(argc, argv);     // leis perduoti --test -s ir pan., jei kada prireiktų
    ctx.setOption("abort-after", 5);      // stop after 5 failures (nebūtina)
    int res = ctx.run();                     // 0 – visi testai praėjo

    return res;
}