#include "deque_deklaracijos.h"
void isvedimasFun(Pasirinkimas p, deque<Studentas> studentai, string failo_pav, int vard_size, int pav_size)
{
    int simbol_ilgis = to_string(p.stud_kiekis).size();
    if (p.c == 1 || failo_pav == "kietiakai.txt" || failo_pav == "nuskriaustukai.txt")
    {
        ofstream fout(failo_pav);
        if (!fout)
        {
            cout << "Rezultatu failas nesukurtas!" << endl;
            exit(0);
        }
        if (p.pasirinkimas == 1) // Vidurkis
        {
            fout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n" << string(50+pav_size+vard_size, '-') << endl;
            for (int i=0 ; i < studentai.size(); i++) 
            {
                fout << left << setw(pav_size + 5) << studentai[i].pavarde << setw(vard_size + 5) << studentai[i].vardas << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
        else if (p.pasirinkimas == 2 ) // Mediana
        {
            fout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(simbol_ilgis + 15) << "Galutinis (Med.)" << "\n" << string(50+pav_size+vard_size, '-') << endl;
            for (int i=0; i < studentai.size(); i++)
            {
                fout << left << setw(pav_size + 5) << studentai[i].pavarde << setw(vard_size + 5) << studentai[i].vardas << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
        fout.close();
    }
    else
    {
        if (p.pasirinkimas == 1) // Vidurkis
        {
            cout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n" << string(50+pav_size+vard_size, '-') << endl;
            for (int i=0; i < studentai.size(); i++)
            {
                cout << left << setw(pav_size + 5) << studentai[i].pavarde << setw(vard_size + 5) << studentai[i].vardas << setw(15) << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
        else if (p.pasirinkimas == 2) // Mediana
        {
            cout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(15) << "Galutinis (Med.)" << "\n" << string(50+pav_size+vard_size, '-') << endl;
            for (int i=0; i < studentai.size(); i++)
            {
                cout << left << setw(pav_size + 5) << studentai[i].pavarde << setw(vard_size + 5) << studentai[i].vardas << setw(15) << fixed << setprecision(2) << studentai[i].galutinis << endl;
            }
        }
    }
}