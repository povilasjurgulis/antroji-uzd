#include "deklaracijos.h"
// Funkcija, kuri generuoja failus:
void file_generavimas(int &irasai)
{
    srand(time(NULL));
    ofstream fout;
    string pav;
    int nd_kiekis = 10; 
        if(irasai==10000) nd_kiekis=15;
        else if(irasai==100000) nd_kiekis=20;
        else if(irasai==1000000) nd_kiekis=7;
        else if(irasai==10000000) nd_kiekis=5;
        int simbol_ilgis = to_string(p.stud_kiekis).size();
        
        cout <<"Spauskite 1, jeigu norite, kad generuojamo failo pavadinimas butu kursiokai2nd.txt, 2 - jeigu norite patys ivesti pavadinima: "; 
        cin >> p.choice1; ivedimas1(p.choice1, "failo pavadinimas kursiokai2nd.txt", "pats ivesk pavadinima", 1, 1, 2);
        if(p.choice1==2)
        {
            cout << "Iveskite failo pavadinima: "; cin >> pav;
        }
        else if(p.choice1==1) pav = "kursiokai2nd.txt";

        Timer t; // Laiko matavimo pradzia
        fout.open(pav);
        if (!fout)
        {
            cout << "Failas " << pav << " nesukurtas!" << endl;
            exit(0);
        }
        else
        {
        fout << left << setw(simbol_ilgis + 15) << "Vardas" <<setw(simbol_ilgis + 15)<<"Pavarde";
        for(int j=1; j<=nd_kiekis; j++)
        {
            fout << left << setw(simbol_ilgis + 5) <<"ND" + to_string(j);
        }
        fout<<" Egzaminas" << endl;
        for (int j = 1; j <= irasai; j++)
        {
            fout << left << setw(simbol_ilgis + 15) << "VardasNr" + to_string(j) << setw(simbol_ilgis + 15) << "PavardeNr" + to_string(j);
            for (int k = 1; k <= nd_kiekis; k++)
            {
                fout << left << setw(simbol_ilgis + 5) << rand() % 10 + 1;
            }
            fout << " " << rand() % 10 + 1 << endl;
        }
        }
        fout.close(); cout << "Failas sukurtas ir uzdarytas" << endl;
        cout << "Failo is "<< irasai <<" irasu sukurimo ir uzdarymo laikas: "<< t.elapsed() << " s" << endl;
}