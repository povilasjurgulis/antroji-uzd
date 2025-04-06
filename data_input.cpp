#include "deklaracijos.h"
void data_input(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], time_point<high_resolution_clock> &start)
{
    int *max_vardas_size = &vard_size, *max_pavarde_size = &pav_size;

if(p.kaip_gauti_duomenis==1 || p.kaip_gauti_duomenis==2) // Ivedimas ranka:
    while(p.irasyti_dar_studentu==3)
    {
        string vardas, pavarde;
        cout<<"Iveskite "<<p.m+1<<"-ojo studento varda: "; cin>>vardas;
        cout<<"Iveskite "<<p.m+1<<"-ojo studento pavarde: "; cin>>pavarde;
        st.SetVardas(vardas);
        st.SetPavarde(pavarde);
        
        p.m++;
        if(vardas.size() > *max_vardas_size) *max_vardas_size = vardas.size();
        if(pavarde.size() > *max_pavarde_size) *max_pavarde_size = pavarde.size();

        if(p.kaip_gauti_duomenis == 2) // Atsitiktinai sugeneruoti nd ir egz
        {
            p.rasyti_daugiau=5;
            cout<<p.m<<"-ojo studento namu darbu rezultatai: "<<endl;
            while(p.rasyti_daugiau==5)
            {
                cout<<p.m<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik, *rlaik;
                rlaik=&laik;
                laik=1+rand()%10;
                cout<<laik<<endl;
                cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.rasyti_daugiau; 
                ivedimas1(p.rasyti_daugiau, "rasyti daugiau", "nutraukti", 1, 5, 6);
                st.SetNd(rlaik);
                p.n++;
            }
            st.SetEgz(rand()%10+1);
            cout<<"Atsitiktinai sugeneruotas "<<p.m<<"-ojo studento egzamino rezultatas: "<< st.GetEgz()<<endl; 
        }   
        else if(p.kaip_gauti_duomenis==1) // Nd ir egz ivedimas ranka
        {
            p.rasyti_daugiau=5;
            cout<<"Iveskite "<<p.m<<"-ojo studento namu darbu rezultatus: ";
            while(p.rasyti_daugiau==5)
            {
                cout<<p.m<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik, *rlaik;
                rlaik=&laik;
                cin>>laik;
                ivedimas1(laik, "", "", 0, 1, 10);
                st.SetNd(rlaik);
                cout<<"Spauskite 5, jeigu norite irasyti dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.rasyti_daugiau; 
                ivedimas1(p.rasyti_daugiau, "rasyti daugiau", "nutraukti", 1, 5, 6);
                p.n++;
            }
            int laik_egz;
            cout<<"Iveskite egzamino rezultata: "; cin>>laik_egz; ivedimas1(laik_egz, "", "", 0, 1, 10); 
            st.SetEgz(laik_egz);
            cout<<p.m<<"-ojo studento egzamino rezultatas: "<<laik_egz<<endl;
        }

        if(p.vid_ar_med==1) //Vidurkis
            {
                st.calc_vid();
            }
            else //Mediana
            {
                st.calc_med();
            }
        studentai.push_back(st);
        st.NdClear();
        p.n=0;
        cout<<"Spauskite 3, jeigu norite irasyti dar viena studenta, 4 - jeigu nenorite: "; cin>>p.irasyti_dar_studentu; 
        ivedimas1(p.irasyti_dar_studentu, "rasyti daugiau", "nutraukti", 1, 3, 4);
    }

    else if(p.kaip_gauti_duomenis==3) //Atsitiktinai sugeneruoti studentai
    {
        p.rasyti_daugiau=5;
        cout<<"Atsitiktinai sugeneruoti studentai: "<<endl;
        while(p.rasyti_daugiau==5)
        {
            int i=rand()%2;
            if(i%2==0)
            {
                st.SetVardas(randomVyrVardai[rand()%20]);
                st.SetPavarde(randomVyrPavarde[rand()%20]);
            }
            else
            {
                st.SetVardas(randomMotVardai[rand()%20]);
                st.SetPavarde(randomMotPavarde[rand()%20]);
            }
            cout<<p.m+1<<"-ojo studento vardas ir pavarde: "<<st.GetVardas()<<" "<<st.GetPavarde()<<endl;
            p.m++;

            if(st.GetVardasSize() > *max_vardas_size) 
                *max_vardas_size = st.GetVardasSize();
            if(st.GetPavardeSize() > *max_pavarde_size) 
                *max_pavarde_size = st.GetPavardeSize();

            p.rasyti_daugiau=5;
            cout<<p.m<<"-ojo studento namu darbu rezultatai: "<<endl;
            while(p.rasyti_daugiau==5)
            {
                cout<<i+1<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik, *rlaik;
                rlaik=&laik;
                laik=1+rand()%10;
                cout<<laik<<endl;
                cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.rasyti_daugiau; 
                ivedimas1(p.rasyti_daugiau, "rasyti daugiau", "nutraukti", 1, 5, 6);
                st.SetNd(rlaik);
                p.n++;
            }
            st.SetEgz(rand()%10+1);
            cout<<"Atsitiktinai sugeneruotas "<<p.m<<"-ojo studento egzamino rezultatas: "<< st.GetEgz()<<endl; 

            if(p.vid_ar_med==1) //Vidurkis
            {
                st.calc_vid();
            }
            else //Mediana
            {
                st.calc_med();
            }
            
            studentai.push_back(st);
            st.NdClear();
            p.n=0;
            cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena studenta, 6 - jeigu nenorite: "; cin>>p.rasyti_daugiau; 
            ivedimas1(p.rasyti_daugiau, "rasyti daugiau", "nutraukti", 1, 5, 6);
        }
    }

    else //Nuskaito is failo:
    { 
        file_skaitymas(vard_size, pav_size, p, st, studentai, vardai, pavardes, start, max_vardas_size, max_pavarde_size);
    }
}