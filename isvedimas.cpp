#include "deklaracijos.h"
void isvedimasFun(Pasirinkimas p, vector<Studentas> studentai)
{
    ofstream fout("rezultatai.txt");
if(!fout)
    {
        cout<<"Rezultatu failas nesukurtas!"<<endl;
        std::exit(0);
    }
    if(p.c==1)
    {
        if(p.pasirinkimas==1) //Vidurkis
        {
            fout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=1; i<p.m; i++) // i=1, nes pirmas studentas nera studentas, bet yra antraste
            {
                fout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
            }   
        }
        else if(p.pasirinkimas==2) //Mediana
        {
            fout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Med.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=1; i<p.m; i++)
            {
                fout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
            }
        }
    }
    else
    {
        if(p.pasirinkimas==1) //Vidurkis
        {
            cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=0; i<p.m; i++)
                {
                cout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
                }
        }
        else if(p.pasirinkimas==2) //Mediana
        {
            cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Med.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=0; i<p.m; i++)
                {
                cout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
                }
        }
    }
    fout.close();
}