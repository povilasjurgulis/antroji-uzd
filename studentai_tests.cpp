#include <cassert>
#include <sstream>
#include <algorithm>
#include "studentai.h"


//void RunTests();
static void checkStudent(const Studentas& s,
                         const std::string& v,
                         const std::string& p,
                         int egz,
                         const std::vector<int>& nd)
{
    assert(s.GetVardas()  == v);
    assert(s.GetPavarde() == p);
    assert(s.GetEgz()     == egz);
    assert(s.GetNd()      == nd);
}
void RunTests()
{
    // 1. Default constructor --------------------------------------------------
    {
        Studentas s;
        assert(s.GetVardas().empty());
        assert(s.GetPavarde().empty());
        assert(s.GetEgz() == 0);
        assert(s.GetNd().empty());
    }

    // 2. Parametrised constructor --------------------------------------------
    std::vector<int> nd1{10, 9, 8};
    Studentas s1("Jonas", "Jonaitis", 9, nd1);
    checkStudent(s1, "Jonas", "Jonaitis", 9, nd1);

    // 3. Copy constructor -----------------------------------------------------
    Studentas s2(s1);
    checkStudent(s2, "Jonas", "Jonaitis", 9, nd1);

    // 4. Copy‑assignment operator -------------------------------------------
    Studentas s3;
    s3 = s1;
    checkStudent(s3, "Jonas", "Jonaitis", 9, nd1);

    // 5. Move constructor -----------------------------------------------------
    Studentas temp1("Petras", "Petraitis", 8, {7, 8});
    Studentas s4(std::move(temp1));
    checkStudent(s4, "Petras", "Petraitis", 8, std::vector<int>{7, 8});
    assert(temp1.GetVardas().empty());
    assert(temp1.GetPavarde().empty());
    assert(temp1.GetNd().empty());
    assert(temp1.GetEgz() == 0);

    // 6. Move‑assignment operator -------------------------------------------
    Studentas temp2("Ona", "Onaite", 10, {10, 10, 9});
    Studentas s5;
    s5 = std::move(temp2);
    checkStudent(s5, "Ona", "Onaite", 10, std::vector<int>{10, 10, 9});
    assert(temp2.GetVardas().empty());
    assert(temp2.GetPavarde().empty());
    assert(temp2.GetNd().empty());
    assert(temp2.GetEgz() == 0);

    // 7. operator>> from generic istream (console‑style) ---------------------
    {
        Studentas s6;
        // Simulate user input: vardas, pavarde, egz, ND (one value) and -1 sentinel
        std::istringstream iss("Jonas\nJonaitis\n7\n8\n-1\n");
        iss >> s6;
        checkStudent(s6, "Jonas", "Jonaitis", 7, std::vector<int>{8});
    }

    // 8. operator>> from file (ifstream) -------------------------------------
    {
        const char* fname = "temp_student_test.txt";
        {
            std::ofstream ofs(fname);
            // vardas pavarde ND ND ND EGZ  (egzaminas – paskutinis skaičius)
            ofs << "Tomas Tomaitis 9 8 7 6\n";
        }

        Studentas s7;
        std::ifstream ifs(fname);
        ifs >> s7;
        checkStudent(s7, "Tomas", "Tomaitis", 6, std::vector<int>{9, 8, 7});
        ifs.close();
        std::remove(fname);
    }

    // 9. Output operator (single Studentas) ----------------------------------
    {
        Studentas outTest("Vardenis", "Pavardenis", 9, {9, 9, 10});
        outTest.CalcVid(); // ensure galutinis has a value
        std::ostringstream oss;
        oss << outTest;
        std::string str = oss.str();
        assert(str.find("Pavardenis") != std::string::npos);
        assert(str.find("Vardenis")   != std::string::npos);
    }

    // 10. Output operator (vector<Studentas>) ---------------------------------
    std::vector<Studentas> vs;
    vs.push_back(s1);
        vs.back().CalcVid();
        vs.push_back(s2);
        vs.back().CalcVid();
    {
        std::ostringstream oss;
        oss << vs;
        std::string result = oss.str();
        assert(result.find("Jonaitis") != std::string::npos);
        // Ensure we have at least two newline‑terminated records
        size_t newlineCount = std::count(result.begin(), result.end(), '\n');
        assert(newlineCount >= vs.size());
    }

    // 11. Output operator to *file* (ofstream overload) ----------------------
    {
        const char* fname = "temp_vec_out.txt";
        {
            std::ofstream ofs(fname);
            ofs << vs;           // Calls ofstream& operator<< overload
        }
        // Re‑open and verify file contains what we expect
        std::ifstream ifs(fname);
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string content = buffer.str();
        assert(content.find("Jonaitis") != std::string::npos);
        size_t newlineCount = std::count(content.begin(), content.end(), '\n');
        assert(newlineCount >= vs.size());
        ifs.close();
        std::remove(fname);
    }

    std::cout << endl << "All Studentas tests passed successfully.\n";
}
