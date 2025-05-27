// ─── vector_tests.cpp ───────────────────────────────────────────────────────────
#include <cassert>
#include <sstream>
#include <array>
#include <iostream>
#include <numeric>
#include "Vector.h"

// Mažas pagalbinis šablonas: patikrina dydį ir identišką turinį
template<class T, class Range>
void equalRange(const Vector<T>& v, const Range& r)
{
    assert(v.size() == r.size());
    assert(std::equal(v.begin(), v.end(), r.begin(), r.end()));
}

template<class T>
void equalRange(const Vector<T>& v, std::initializer_list<T> il)
{
    Vector<T> expect(il);
    equalRange(v, expect);
}

// Patogumui – išimčių patikrinimas (C-style assert neatpažįsta try/catch)
template<class F>
void expectThrow(F&& fn)
{
    bool threw = false;
    try { fn(); }
    catch (...) { threw = true; }
    assert(threw);
}

void RunVectorTests()
{
    // 1  ── Konstruktoriai ────────────────────────────────────────────────────
    {
        Vector<int> def;
        assert(def.empty() && def.capacity() == 0);

        Vector<int> sized(5);
        assert(sized.size() == 5 && sized.capacity() == 5);
        for (int x : sized) assert(x == 0);

        Vector<int> il{1,2,3,4};
        equalRange(il,{1,2,3,4});

        Vector<int> copy(il);
        equalRange(copy,{1,2,3,4});

        Vector<int> moved(std::move(copy));
        equalRange(moved,{1,2,3,4});
        assert(copy.empty());
    }

    // 2  ── operator= (copy & move) ──────────────────────────────────────────
    {
        Vector<std::string> a{"aa","bb"};
        Vector<std::string> b;
        b = a;                               // copy=
        equalRange(b,{std::string("aa"), std::string("bb")});

        Vector<std::string> c;
        c = std::move(b);                    // move=
        equalRange(c,{std::string("aa"), std::string("bb")});
        assert(b.empty());
    }

    // 3  ── push_back / emplace_back  ────────────────────────────────────────
    {
        Vector<std::string> v;
        v.push_back("abc");
        std::string s = "def";
        v.push_back(std::move(s));           // move
        v.emplace_back(3,'x');               // "xxx"
        equalRange(v,{std::string("abc"), std::string("def"), std::string("xxx")});
        assert(s.empty());
    }

    // 4  ── reserve / resize / shrink_to_fit ─────────────────────────────────
    {
        Vector<int> v;
        v.reserve(32);
        assert(v.capacity() >= 32 && v.size() == 0);

        v.resize(10);
        assert(v.size() == 10);
        for (int x : v) assert(x == 0);

        v.resize(3);                         // sutrumpinam
        equalRange(v,{0,0,0});

        auto oldCap = v.capacity();
        v.shrink_to_fit();
        assert(v.capacity() == v.size() && v.capacity() <= oldCap);
    }

    // 5  ── insert / erase ───────────────────────────────────────────────────
    {
        Vector<int> v{1,3,4};
        v.insert(v.begin()+1, 2);            // 1 2 3 4
        equalRange(v,{1,2,3,4});

        v.erase(v.begin()+2);                // 1 2 4
        equalRange(v,{1,2,4});

        v.erase(v.begin(), v.begin()+2);     // 4
        equalRange(v,{4});
    }

    // 6  ── assign_range / append_range ──────────────────────────────────────
    {
        Vector<int> v;
        std::array<int,3> arr = {7,8,9};
        v.assign_range(arr);
        equalRange(v,{7,8,9});

        int extra[]{10,11};
        v.append_range(extra);
        equalRange(v,{7,8,9,10,11});
    }

    // 7  ── at(), front(), back(), data() ────────────────────────────────────
    {
        Vector<int> v{5,6,7};
        assert(v.front()==5 && v.back()==7 && v.at(1)==6);
        int* raw = v.data();
        assert(raw[0]==5 && raw[2]==7);

        expectThrow([&]{ v.at(99); });
    }

    // 8  ── swap(), operator== / !=, sort()  ─────────────────────────────────
    {
        Vector<int> a{3,1,2};
        Vector<int> b{9,8,7};
        a.swap(b);
        equalRange(a,{9,8,7});
        equalRange(b,{3,1,2});

        assert(a!=b && (a==a));

        b.sort();                            // 1 2 3
        equalRange(b,{1,2,3});
    }
    
    // 9  ── iterator savybės (mutable / const) ───────────────────────────────
    {
        Vector<int> v{1,2,3};
        std::for_each(v.begin(), v.end(), [](int& x){ x*=2; });
        equalRange(v,{2,4,6});

        const Vector<int>& cv = v;
        int sum = std::accumulate(cv.cbegin(), cv.cend(), 0);
        assert(sum == 12);

        // reverse_iterator
        Vector<int> r;
        for (auto it = cv.crbegin(); it != cv.crend(); ++it)
            r.push_back(*it);
        equalRange(r,{6,4,2});
    }

    std::cout << "\nAll Vector<T> tests passed successfully.\n";
}
