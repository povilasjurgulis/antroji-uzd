#include "list_deklaracijos.h"
void isvedimasFun(Pasirinkimas p, list<Studentas> studentai, string failo_pav)
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
            fout << left << setw(simbol_ilgis + 15) << "Pavarde" << setw(simbol_ilgis + 15) << "Vardas" << setw(simbol_ilgis + 15) << "Galutinis (Vid.)" << "\n" << string(50, '-') << endl;
            for (auto &studentas : studentai)
            {
                fout << left << setw(simbol_ilgis + 15) << studentas.pavarde << setw(simbol_ilgis + 15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
            }
        }
        else if (p.pasirinkimas == 2) // Mediana
        {
            fout << left << setw(15) << setw(simbol_ilgis + 15) << "Pavarde" << setw(simbol_ilgis + 15) << "Vardas" << setw(simbol_ilgis + 15) << "Galutinis (Med.)" << "\n" << string(50, '-') << endl;
            for (auto &studentas : studentai)
            {
                fout << left << setw(simbol_ilgis + 15) << studentas.pavarde << setw(simbol_ilgis + 15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
            }
        }
        fout.close();
    }
    else
    {
        if (p.pasirinkimas == 1) // Vidurkis
        {
            cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n" << string(50, '-') << endl;
            for (auto &studentas : studentai)
            {
                cout << left << setw(simbol_ilgis + 15) << studentas.pavarde << setw(simbol_ilgis + 15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
            }
        }
        else if (p.pasirinkimas == 2) // Mediana
        {
            cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15) << "Galutinis (Med.)" << "\n" << string(50, '-') << endl;
            for (auto &studentas : studentai)
            {
                cout << left << setw(simbol_ilgis + 15) << studentas.pavarde << setw(simbol_ilgis + 15) << studentas.vardas << fixed << setprecision(2) << studentas.galutinis << endl;
            }
        }
    }
}