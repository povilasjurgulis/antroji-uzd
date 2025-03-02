#include "deklaracijos.h"
// Funkcija, kuri generuoja failus:
void file_gen(int n)
{
    ofstream fout;
    string pav;
    for (int i = 1; i <= n; i++)
    {
        pav = "kursiokai" + to_string(i) + ".txt";
        fout.open(pav);
        if (!fout)
        {
            cout << "Failas " << pav << " nesukurtas!" << endl;
            exit(0);
        }
        fout << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas" << endl;
        for (int j = 1; j <= 1000; j++)
        {
            fout << "Vardas" << j << " Pavarde" << j;
            for (int k = 1; k <= 5; k++)
            {
                fout << " " << rand() % 10 + 1;
            }
            fout << " " << rand() % 10 + 1 << endl;
        }
        fout.close();
    }
}