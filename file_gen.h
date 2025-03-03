#include "deklaracijos.h"
// Funkcija, kuri generuoja failus:
void file_generavimas(int n)
{
    ofstream fout;
    string pav;
    int irasai = 1000, nd_kiekis = 10;
    for (int i = 1; i <= n; i++)
    {   
        if(irasai==10000) nd_kiekis=15;
        else if(irasai==100000) nd_kiekis=20;
        else if(irasai==1000000) nd_kiekis=7;
        else if(irasai==10000000) nd_kiekis=5;
        pav = "kursiokai" + to_string(i) + ".txt";
        fout.open(pav);
        if (!fout)
        {
            cout << "Failas " << pav << " nesukurtas!" << endl;
            exit(0);
        }
        else
        {
        fout << "Vardas Pavarde ";
        for(int j=1; j<=nd_kiekis; j++)
        {
            fout << "ND" << j << " ";
        }
        fout<<" Egzaminas" << endl;
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