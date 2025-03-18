#include "list_deklaracijos.h"
void ifs(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, list<Studentas>& studentai, list<string> vardai, list<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], time_point<high_resolution_clock> &start)
{
    int *max_vardas_size = &vard_size, *max_pavarde_size = &pav_size;

    if(p.choice==1 || p.choice==2) // Ivedimas ranka:
    while(p.a==3)
    {
        string vardas, pavarde;
        cout<<"Iveskite "<<p.m+1<<"-ojo studento varda: "; cin>>vardas;
        cout<<"Iveskite "<<p.m+1<<"-ojo studento pavarde: "; cin>>pavarde;
        st.vardas = vardas;
        st.pavarde = pavarde;
        p.m++;

        if(vardas.size() > *max_vardas_size) *max_vardas_size = vardas.size();
        if(pavarde.size() > *max_pavarde_size) *max_pavarde_size = pavarde.size();  

        if(p.choice == 2) // Atsitiktinai sugeneruoti nd ir egz
        {
            p.b=5;
            cout<<p.m<<"-ojo studento namu darbu rezultatai: "<<endl;
            while(p.b==5)
            {
                cout<<p.m<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                laik=1+rand()%10;
                cout<<laik<<endl;
                cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.b; 
                ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
                st.nd.push_back(laik);
                p.n++;
            }
            st.egz = rand()%10+1;
            cout<<"Atsitiktinai sugeneruotas "<<p.m<<"-ojo studento egzamino rezultatas: "<< st.egz<<endl; 
        }   
        else if(p.choice==1) // nd ir egz ivedimas ranka
        {
            p.b=5;
            cout<<"Iveskite "<<p.m<<"-ojo studento namu darbu rezultatus: ";
            while(p.b==5)
            {
                cout<<p.m<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                cin>>laik;
                ivedimas1(laik, "", "", 0, 1, 10);
                st.nd.push_back(laik);
                cout<<"Spauskite 5, jeigu norite irasyti dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.b; 
                ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
                p.n++;
            }
            cout<<"Iveskite egzamino rezultata: "; cin>>st.egz; ivedimas1(st.egz, "", "", 0, 1, 10); 
            cout<<p.m<<"-ojo studento egzamino rezultatas: "<<st.egz<<endl;
        }

        vid_mediana(st, p);
        studentai.push_back(st);
        st.nd.clear();
        p.n=0;
        cout<<"Spauskite 3, jeigu norite irasyti dar viena studenta, 4 - jeigu nenorite: "; cin>>p.a; 
        ivedimas1(p.a, "rasyti daugiau", "nutraukti", 1, 3, 4);
    }

    else if(p.choice==3) //Atsitiktinai sugeneruoti studentai
    {
        p.b=5;
        cout<<"Atsitiktinai sugeneruoti studentai: "<<endl;
        while(p.b==5)
        {
            int i=rand()%2;
            if(i%2==0)
            {
                st.vardas = randomVyrVardai[rand()%20];
                st.pavarde = randomVyrPavarde[rand()%20];
            }
            else
            {
                st.vardas = randomMotVardai[rand()%20];
                st.pavarde = randomMotPavarde[rand()%20];
            }
            cout<<p.m+1<<"-ojo studento vardas ir pavarde: "<<st.vardas<<" "<<st.pavarde<<endl;
            p.m++;

            if(vardai.back().size() > *max_vardas_size) 
                *max_vardas_size = st.vardas.size();
            if(pavardes.back().size() > *max_pavarde_size) 
                *max_pavarde_size = st.pavarde.size();

            cout<<p.m<<"-ojo studento namu darbu rezultatai: "<<endl;
            p.b=5;
            while(p.b==5)
            {
                cout<<p.m<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                laik=1+rand()%10;
                cout<<laik<<endl;
                cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.b; 
                ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
                st.nd.push_back(laik);
                p.n++;
            }
            st.egz = rand()%10+1;
            cout<<"Atsitiktinai sugeneruotas "<<p.m<<"-ojo studento egzamino rezultatas: "<< st.egz<<endl; 

            vid_mediana(st, p);
            studentai.push_back(st);
            st.nd.clear();
            p.n=0;
            cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena studenta, 6 - jeigu nenorite: "; cin>>p.b; 
            ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
        }
    }
    else //Nuskaito is failo:
    {   
        file_skaitymas(vard_size, pav_size, p, st, studentai, vardai, pavardes, start, max_vardas_size, max_pavarde_size);
    }
}