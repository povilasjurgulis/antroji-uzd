#include "deklaracijos.h"
void isvedimasFun(Pasirinkimas p, vector<Studentas>& studentai, string failo_pav)
{
    int i;
    if (p.c == 1)
    {
        ofstream fout(failo_pav);
        if (!fout)
        {
            cout << "Rezultatu failas nesukurtas!" << endl;
            exit(0);
        }
        if (p.pasirinkimas == 1) // Vidurkis
        {
            fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n" << string(50, '-') << endl;
            for ((p.choice==4)? i=1 : i=0 ; i < studentai.size(); i++) // i=1, nes pirmas studentas nera studentas, bet yra antraste
            {
                fout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << setw(15) << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
        else if (p.pasirinkimas == 2) // Mediana
        {
            fout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << "\n" << string(50, '-') << endl;
            for ((p.choice==4)? i=1 : i=0; i < studentai.size(); i++)
            {
                fout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << setw(15) << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
        fout.close();
    }
    else
    {
        if (p.pasirinkimas == 1) // Vidurkis
        {
            cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n"
                 << string(50, '-') << endl;
            for ((p.choice==4)? i=1 : i=0; i < studentai.size(); i++)
            {
                cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << setw(15) << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
        else if (p.pasirinkimas == 2) // Mediana
        {
            cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << "\n"
                 << string(50, '-') << endl;
            for ((p.choice==4)? i=1 : i=0; i < studentai.size(); i++)
            {
                cout << left << setw(15) << studentai[i].pavarde << setw(15) << studentai[i].vardas << setw(15) << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
    }
}