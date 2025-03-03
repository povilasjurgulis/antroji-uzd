#include "deklaracijos.h"

//Su vektoriais: pradzia!
int main(){
    cout<<"Spauskite 1, jeigu norite pradeti darba, 2 - jeigu norite baigti darba: "; cin>>p.e; ivedimas1(p.e, "pradeti", "baigti", 1, 1, 2);
    if(p.e == 2) return 0;
    time_point<high_resolution_clock> start; // Sukuriame laiko pradzios kintamaji

    srand(time(NULL));
    cout<<"Spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: "; cin>>p.pasirinkimas; ivedimas1(p.pasirinkimas, "vidurki", "mediana", 1, 1, 2);
    cout<<"Spauskite 1, jeigu norite sugeneruoti atsitiktinius failus ir juos naudoti rezultatams, 2 - jeigu norite kitu pasirinkimu: "; cin>>p.choice1; ivedimas1(p.choice1, "sugeneruoti", "kiti pasirinkimai", 1, 1, 2);
    if(p.choice1==1)
    {
        cout<<"Iveskite, kiek failu norite sugeneruoti (1 maziausiai, o 5 daugiausiai. Jei 5, tai penktame faile bus 10 milijonu irasu, o jei 1, tai faile bus 1 tukstantis irasu): "; 
        cin>>p.file_kiekis; ivedimas1(p.file_kiekis, "", "", 0, 1, 10);
        file_generavimas(p.file_kiekis);
        p.choice=4;
    }
    else{
    cout<<"Spauskite 1, jeigu norite viska rasyti ranka. 2 - jeigu norite, kad tik pazymiai butu atsitiktinai sugeneruoti. \n3 - jeigu norite, kad pazymiai, studentu vardai ir pavardes butu atsitiktinai sugeneruoti. ";
    cout<<"Spauskite 4, jeigu norite, kad visi duomenys butu nuskaityti is failo: "; 
    cin>>p.choice; ivedimas2(p.choice);
    }
    //If statement'ai, kurie atlieka veiksmus pagal vartotojo pasirinkima:
    ifs(p, st, studentai, vardai, pavardes, randomVyrVardai, randomMotVardai, randomVyrPavarde, randomMotPavarde, start);

    vardai.clear();
    pavardes.clear();
    auto end = std::chrono::high_resolution_clock::now(); // Skaiciavimo pabaiga
    std::chrono::duration<double> diff = end-start; // Skaiciuojame skirtuma

    int rikiavimas;
    cout << "Pasirinkite, pagal ka rikiuoti:\n" << "  1 - pagal varda"<< "  2 - pagal pavarde"<< "  3 - pagal galutini bala: "; cin >> rikiavimas;
    ivedimas3(rikiavimas);
    auto start1 = std::chrono::high_resolution_clock::now(); // Pradedame skaiciuoti laika

    //Rikiavimas:
    rikiavimasFun(studentai, rikiavimas);

    auto end1 = high_resolution_clock::now(); // Skaiciavimo pabaiga
    duration<double> diff1 = end1-start1; // Skaiciuojame skirtuma

    cout<<"Ar norite, kad rezultatai butu isvedami i faila? 1 - taip, 2 - ne: "; cin>>p.c; ivedimas1(p.c, "isvesti i faila", "neisvesti i faila", 1, 1, 2);
    auto start2 = high_resolution_clock::now(); // Pradedame skaiciuoti laika

    //Rezultatu isvedimas:
    isvedimasFun(p, studentai);

    //Laiko skaiciavimo pabaiga:
    auto end2 = high_resolution_clock::now(); // Skaiciavimo pabaiga
    duration<double> diff2 = end2-start2; // Skaiciuojame skirtuma
    duration<double> diffFinal = diff+diff1+diff2;
    if(p.choice==4)
    cout<<"Programos vykdymo laikas: "<<diffFinal.count()<<" s\n"<<endl;
    return 0;
}
