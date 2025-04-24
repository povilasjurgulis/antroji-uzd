#include "deklaracijos.h"
void isvedimasFun(Pasirinkimas p, vector<Studentas> studentai, string failo_pav, int vard_size, int pav_size)
{

if(p.ar_naudoti_klases_operatorius == 2) // Nenaudojame klases operatoriu
{
    int simbol_ilgis = to_string(p.stud_kiekis).size();
    if (p.kur_isvesti == 1 || failo_pav == "kietiakai.txt" || failo_pav == "nuskriaustukai.txt")
    {
        ofstream fout(failo_pav);
        if (!fout)
        {
            cout << "Rezultatu failas nesukurtas!" << endl;
            exit(0);
        }
        if (p.vid_ar_med == 1) // Vidurkis
        {
            fout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n" << string(50+pav_size+vard_size, '-') << "\n";
            for (int i=0 ; i < studentai.size(); i++) 
            {
                fout << left << setw(pav_size + 5) << studentai[i].GetPavarde() << setw(vard_size + 5) << studentai[i].GetVardas() << fixed << setprecision(2) << studentai[i].GetGalutinis() << "\n";
            }
        }
        else if (p.vid_ar_med == 2 ) // Mediana
        {
            fout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(simbol_ilgis + 15) << "Galutinis (Med.)" << "\n" << string(50+pav_size+vard_size, '-') << "\n";
            for (int i=0; i < studentai.size(); i++)
            {
                fout << left << setw(pav_size + 5) << studentai[i].GetPavarde() << setw(vard_size + 5) << studentai[i].GetVardas() << fixed << setprecision(2) << studentai[i].GetGalutinis() << "\n";
            }
        }
        fout.close();
    }
    else
    {
        if (p.vid_ar_med == 1) // Vidurkis
        {
            cout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(15) << "Galutinis (Vid.)" << "\n" << string(50+pav_size+vard_size, '-') << "\n";
            for (int i=0; i < studentai.size(); i++)
            {
                cout << left << setw(pav_size + 5) << studentai[i].GetPavarde() << setw(vard_size + 5) << studentai[i].GetVardas() << setw(15) << fixed << setprecision(2) << studentai[i].GetGalutinis() << endl;
            }
        }
        else if (p.vid_ar_med == 2) // Mediana
        {
            cout << left << setw(pav_size + 5) << "Pavarde" << setw(vard_size + 5) << "Vardas" << setw(15) << "Galutinis (Med.)" << "\n" << string(50+pav_size+vard_size, '-') << "\n";
            for (int i=0; i < studentai.size(); i++)
            {
                cout << left << setw(pav_size + 5) << studentai[i].GetPavarde() << setw(vard_size + 5) << studentai[i].GetVardas() << setw(15) << fixed << setprecision(2) << studentai[i].GetGalutinis() << endl;
            }
        }
    }
}

else if(p.ar_naudoti_klases_operatorius == 1) // Naudojame klases operatorius
{
    int simbol_ilgis = to_string(p.stud_kiekis).size();
    if (p.kur_isvesti == 1 || failo_pav == "kietiakai.txt" || failo_pav == "nuskriaustukai.txt")
    {
        ofstream fout(failo_pav);
        if (!fout)
        {
            cout << "Rezultatu failas nesukurtas!" << endl;
            exit(0);
        }
        if (p.vid_ar_med == 1) // Vidurkis
        {
            fout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "\n" << string(50, '-') << endl;
            fout << studentai;
        }
        else if (p.vid_ar_med == 2 ) // Mediana
        {
            fout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << "\n" << string(50, '-') << endl;
            fout << studentai;
        }
        fout.close();
    }
    else
    {
        if (p.vid_ar_med == 1) // Vidurkis
        {
            cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << "\n" << string(50, '-') << endl;
            cout << studentai;
        }
        else if (p.vid_ar_med == 2) // Mediana
        {
            cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis (Med.)" << "\n" << string(50, '-') << endl;
            cout << studentai;
        }
    }
}

}