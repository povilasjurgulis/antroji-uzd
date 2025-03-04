#include "deklaracijos.h"
// Funkcija, kuri generuoja failus:
void file_generavimas(int irasai)
{
    ofstream fout;
    string pav;
    int nd_kiekis = 10; 
        if(irasai==10000) nd_kiekis=15;
        else if(irasai==100000) nd_kiekis=20;
        else if(irasai==1000000) nd_kiekis=7;
        else if(irasai==10000000) nd_kiekis=5;
        pav = "kursiokai2nd.txt";
        Timer t; // Laiko matavimo pradzia
        fout.open(pav);
        if (!fout)
        {
            cout << "Failas " << pav << " nesukurtas!" << endl;
            exit(0);
        }
        else
        {
        fout << left << setw(15) << "Vardas" <<setw(15)<<"Pavarde\t";
        for(int j=1; j<=nd_kiekis; j++)
        {
            fout << "ND" << j << "      ";
        }
        fout<<" Egzaminas" << endl;
        for (int j = 1; j <= irasai; j++)
        {
            fout << left << setw(15) << "VardasNr" << j << setw(15) << " PavardeNr" << j << "\t";
            for (int k = 1; k <= nd_kiekis; k++)
            {
                fout << rand() % 10 + 1 << "      ";
            }
            fout << " " << rand() % 10 + 1 << endl;
        }
        }
        fout.close(); cout << "Failas uzdarytas" << endl;
        cout << "Failo is "<< irasai <<" irasu sukurimo ir uzdarymo laikas: "<< t.elapsed() << " s" << endl;
}