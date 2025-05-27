#include "deklaracijos.h"

// Su vektoriais: pradzia!
int main()
{
    cout << "Spauskite 1, jeigu norite pradeti darba, 2 - jeigu norite baigti darba: ";
    cin >> p.pradeti_baigti;
    ivedimas1(p.pradeti_baigti, "pradeti", "baigti", 1, 1, 2);
    if (p.pradeti_baigti == 2)
        return 0;

    // Spausti 1 - jeigu naudoti klases operatorius, 2 - jeigu ne
    p.ar_naudoti_klases_operatorius = 2; // ivedimas1(p.ar_naudoti_klases_operatorius, "naudoti klases operatorius", "nenaudoti", 1, 1, 2);

    cout << "Spauskite 1, jeigu norite paleisti studentai.h klases testus, 2 - jeigu nenorite: ";
    cin >> p.testai;
    ivedimas1(p.testai, "paleisti", "nepaleisti", 1, 1, 2);
    if (p.testai == 1)
    {
        RunTests(); // Paleidziame testus
        cout << "Testai baigti.\n"
             << endl;
    }
    // Zmogus* zmogus = new Zmogus(); // Sukuriame bazines klases objekta, tačiau matome, kad negalima sukurti bazines klases objekto, nes ji yra abstrakti
    srand(time(NULL));
    cout << "Spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: ";
    cin >> p.vid_ar_med;
    ivedimas1(p.vid_ar_med, "vidurki", "mediana", 1, 1, 2);
    cout << "Spauskite 1, jeigu norite sugeneruoti atsitiktinius failus ir juos naudoti rezultatams, 2 - jeigu norite kitu pasirinkimu: ";
    cin >> p.ar_generuoti_failus;
    ivedimas1(p.ar_generuoti_failus, "sugeneruoti", "kiti pasirinkimai", 1, 1, 2);
    if (p.ar_generuoti_failus == 1)
    {
        cout << "Iveskite, kiek studentu norite sugeneruoti: spauskite 1, jeigu 1000 studentu, 2 - jeigu 10 tukstanciu, 3 - jeigu 100 tukstanciu, 4 - jeigu 1 milijona, 5 - jeigu 10 milijonu: ";
        cin >> p.stud_kiekis;
        ivedimas1(p.stud_kiekis, "", "", 0, 1, 5);
        if (p.stud_kiekis == 1)
            p.stud_kiekis = 1000;
        else if (p.stud_kiekis == 2)
            p.stud_kiekis = 10000;
        else if (p.stud_kiekis == 3)
            p.stud_kiekis = 100000;
        else if (p.stud_kiekis == 4)
            p.stud_kiekis = 1000000;
        else if (p.stud_kiekis == 5)
            p.stud_kiekis = 10000000;
        file_generavimas(p.stud_kiekis);
        p.kaip_gauti_duomenis = 4;
    }
    else
    {
        cout << "Spauskite 1, jeigu norite viska rasyti ranka. 2 - jeigu norite, kad tik pazymiai butu atsitiktinai sugeneruoti. \n3 - jeigu norite, kad pazymiai, studentu vardai ir pavardes butu atsitiktinai sugeneruoti. ";
        cout << "Spauskite 4, jeigu norite, kad visi duomenys butu nuskaityti is failo: ";
        cin >> p.kaip_gauti_duomenis;
        ivedimas2(p.kaip_gauti_duomenis);
    }
    time_point<high_resolution_clock> start; // Sukuriame laiko pradzios kintamaji

    // If statement'ai, kurie atlieka veiksmus pagal vartotojo pasirinkima:
    data_input(vard_size, pav_size, p, st, studentai, vardai, pavardes, randomVyrVardai, randomMotVardai, randomVyrPavarde, randomMotPavarde, start);

    vardai.clear();
    pavardes.clear();
    auto end = std::chrono::high_resolution_clock::now(); // Skaiciavimo pabaiga
    std::chrono::duration<double> diff = end - start;     // Skaiciuojame skirtuma

    int rikiavimas;
    cout << "Pasirinkite, pagal ka rikiuoti:\n"
         << "  1 - pagal varda" << "  2 - pagal pavarde" << "  3 - pagal galutini bala: ";
    cin >> rikiavimas;
    ivedimas3(rikiavimas);
    auto start1 = std::chrono::high_resolution_clock::now(); // Pradedame skaiciuoti laika

    // Rikiavimas:
    Studentas::Rikiavimas(studentai, rikiavimas);

    auto end1 = high_resolution_clock::now(); // Skaiciavimo pabaiga
    duration<double> diff1 = end1 - start1;   // Skaiciuojame skirtuma
    cout << studentai.size() << " studentu rikiavimas didejimo tvarka uztruko: " << fixed << setprecision(4) << diff1.count() << " s" << endl;

    int dydis = studentai.size();
    cout << "Ar norite, kad rezultatai butu isvedami i du atskirus failus? 1 - i du atskirus failus, 2 - i ekrana, 3 - niekur neisvesti: ";
    cin >> p.kur_isvesti;
    ivedimas1(p.kur_isvesti, "isvesti i failus", "neisvesti i failus", 0, 1, 3);
    string pav = " "; // Failo pavadinimas

    // cout<<"Spauskite 1, jeigu norite, kad studentu konteineris butu isskaidytas i du naujus to paties tipo konteinerius: kietiakai ir nuskriaustukai, "<<endl;
    // cout<<"2 - jeigu norite isskaidyti panaudojant tik viena nauja konteineri nuskriaustukai: "; //<< endl;
    // // cout<<"3 - jeigu norite naudoti 3 strategija: ";
    // cin>>p.koks_konteineris; ivedimas1(p.koks_konteineris, "du naujus konteinerius", "viena nauja konteineri", 0, 1, 3);

    p.koks_konteineris = 1;                     // Istatome numatyta reiksme, kad butu naudojama pirmoji strategija
    auto start2 = high_resolution_clock::now(); // Pradedame skaiciuoti laika

    // Studentu padalinimas i dvi grupes:
    Timer t2;
    if (p.koks_konteineris == 1)
        for (auto &studentas : studentai)
        {
            if (studentas.GetGalutinis() >= 5)
                kietiakai.push_back(studentas);
            else
                nuskriaustukai.push_back(studentas);
        }
    // else if (p.koks_konteineris == 2)
    // {
    // size_t i = 0;
    // while (i < studentai.size())
    // {
    //     if (studentai[i].GetGalutinis() < 5)
    //     {
    //         // Add to nuskriaustukai
    //         nuskriaustukai.push_back(studentai[i]);
    //         // Move the last element to the current position (if it's not already the last)
    //         if (i != studentai.size() - 1)
    //             studentai[i] = studentai.back();
    //         // Remove the last element
    //         studentai.pop_back();
    //         // Don't increment i since we now have a new element at position i
    //     }
    //     else
    //     {
    //         // Only increment when we don't remove an element
    //         ++i;
    //     }
    // }
    // }
    // else if(p.koks_konteineris == 3)
    // {
    // // Rezervuojame vietą, kad būtų efektyvesnis operacijų vykdymas
    // kietiakai.reserve(studentai.size() / 2);
    // nuskriaustukai.reserve(studentai.size() / 2);

    // // Naudojame partition_copy vietoj dviejų copy_if
    // std::partition_copy(studentai.begin(), studentai.end(),
    //                    std::back_inserter(kietiakai),
    //                    std::back_inserter(nuskriaustukai),
    //                    [](const Studentas& s) { return s.GetGalutinis() >= 5.0; });
    // }

    nuskriaustukai.shrink_to_fit();
    if (p.koks_konteineris == 1 || p.koks_konteineris == 3)
        kietiakai.shrink_to_fit();
    if (p.koks_konteineris == 2)
        studentai.shrink_to_fit();
    cout << dydis << " Studentu skirstymas i dvi grupes/kategorijas uztruko: " << fixed << setprecision(4) << t2.elapsed() << " s" << endl;

    if (p.kur_isvesti == 3)
    {
        studentai.clear();
        nuskriaustukai.clear();
        if (p.koks_konteineris == 1)
            kietiakai.clear();
        return 0;
    }

    // Rezultatu isvedimas:
    if (p.kur_isvesti == 2)
        isvedimasFun(p, studentai, pav, vard_size, pav_size);
    Timer t3;
    if (p.kur_isvesti == 1)
    {
        isvedimasFun(p, nuskriaustukai, "nuskriaustukai.txt", vard_size, pav_size);
        if (p.koks_konteineris == 1 || p.koks_konteineris == 3)
            isvedimasFun(p, kietiakai, "kietiakai.txt", vard_size, pav_size);
        else if (p.koks_konteineris == 2)
            isvedimasFun(p, studentai, "kietiakai.txt", vard_size, pav_size);
    }
    if (p.kur_isvesti == 1)
        cout << dydis << " Surusiuotu studentu isvedimas i du failus uztruko: " << fixed << setprecision(4) << t3.elapsed() << " s" << endl;

    // Laiko skaiciavimo pabaiga:
    auto end2 = high_resolution_clock::now(); // Skaiciavimo pabaiga
    duration<double> diff2 = end2 - start2;   // Skaiciuojame skirtuma
    duration<double> diffFinal;
    if (p.kaip_gauti_duomenis == 4) // Jeigu duomenis nuskaitome is failo
        diffFinal = diff + diff1 + diff2;
    else // Jiegu duomenu neskaitome is failo
        diffFinal = diff1 + diff2;
    cout << "Programos vykdymo laikas: " << diffFinal.count() << " s\n"
         << endl;
    studentai.clear();
    nuskriaustukai.clear();
    if (p.koks_konteineris == 1)
        kietiakai.clear();
    return 0;
}