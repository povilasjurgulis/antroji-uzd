#include "deklaracijos.h"
// Funkcija, kuri generuoja failus:
void file_generavimas(int n)
{
    ofstream fout;
    string pav;
    int irasai = 1000;
    for (int i = 1; i <= n; i++)
    {
        pav = "kursiokai" + to_string(i) + ".txt";
        fout.open(pav);
        if (!fout)
        {
            cout << "Failas " << pav << " nesukurtas!" << endl;
            exit(0);
        }
        else
        {
        fout << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas" << endl;
        for (int j = 1; j <= irasai; j++)
        {
            fout << "VardasNr" << j << " PavardeNr" << j;
            for (int k = 1; k <= 5; k++)
            {
                fout << " " << rand() % 10 + 1;
            }
            fout << " " << rand() % 10 + 1 << endl;
        }
        }
        irasai *= 10;
        fout.close();
    }
}