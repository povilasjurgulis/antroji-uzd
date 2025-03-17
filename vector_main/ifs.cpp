#include "deklaracijos.h"
void ifs(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], time_point<high_resolution_clock> &start)
{
    // int vard_size = 0, pav_size = 0;
    int *max_vardas_size = &vard_size, *max_pavarde_size = &pav_size;
if(p.choice==1 || p.choice==2)
    while(p.a==3)
    {
        string vardas, pavarde;
        cout<<"Iveskite "<<p.m+1<<"-ojo studento varda: "; cin>>vardas;
        cout<<"Iveskite "<<p.m+1<<"-ojo studento pavarde: "; cin>>pavarde;
        vardai.push_back(vardas);
        pavardes.push_back(pavarde);
        cout<<"Spauskite 3, jeigu norite irasyti dar viena studenta, 4 - jeigu nenorite: "; cin>>p.a; 
        ivedimas1(p.a, "rasyti daugiau", "nutraukti", 1, 3, 4);
        p.m++;
        if(vardas.size() > *max_vardas_size) *max_vardas_size = vardas.size();
        if(pavarde.size() > *max_pavarde_size) *max_pavarde_size = pavarde.size();
    }
    else if(p.choice==3)
    {
        cout<<"Atsitiktinai sugeneruoti studentai: "<<endl;
        while(p.b==5)
        {
            int i=rand()%2;
            if(i%2==0)
            {
                vardai.push_back(randomVyrVardai[rand()%20]);
                pavardes.push_back(randomVyrPavarde[rand()%20]);
            }
            else
            {
                vardai.push_back(randomMotVardai[rand()%20]);
                pavardes.push_back(randomMotPavarde[rand()%20]);
            }
            cout<<p.m+1<<"-ojo studento vardas ir pavarde: "<<vardai[p.m]<<" "<<pavardes[p.m]<<endl;
            cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena studenta, 6 - jeigu nenorite: "; cin>>p.b; 
            ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
            p.m++;
            if(vardai.size() > *max_vardas_size) *max_vardas_size = vardai.size();
            if(pavardes.size() > *max_pavarde_size) *max_pavarde_size = pavardes.size();
        }
    }


    else{ //Nuskaito is failo:
        string failoVardas;
        cout << "Spauskite 1, jeigu norite nuskaityti duomenis is kursiokai2nd.txt failo, 2 - jeigu is kursiokai.txt,";
        cout<<" 3 - jeigu norite ivesti failo pavadinima (is kurio nuskaityti): "; cin >> p.choice1; ivedimas1(p.choice1, "", "", 0, 1, 3);
        
        if(p.choice1==2) failoVardas = "kursiokai.txt";
        else if(p.choice1==1) 
        {
            failoVardas = "kursiokai2nd.txt";
        }
        else if(p.choice1==3) 
        {
            cout << "Iveskite failo pavadinima, is kurio norite nuskaityti duomenis: "; 
            cin >> failoVardas;
        }

        
        ifstream fin(failoVardas);
        try {
            ifstream fin(failoVardas);
            if(!fin) {
                throw runtime_error("Nepavyko atidaryti failo: " + failoVardas);
            }
            // Tolimesnis failo apdorojimas…
        }
        catch(const runtime_error& e) {
            cerr << "Ivyko klaida: " << e.what() <<endl; // e.what()
            exit(1); // Iseiti su klaidos kodu 1
        }
        
        start = high_resolution_clock::now(); // Pradedame skaiciuoti laika

        string eilute;
        Timer t1; // Laiko matavimo pradzia
        getline(fin, eilute); // Pirmoji eilute yra antraste
        while(getline(fin, eilute))
        {
            if(eilute.empty()) continue;
            istringstream iss(eilute);
            iss>>st.vardas>>st.pavarde;
            vector<int> laikini;
            int paz;
            while(iss>>paz)
                laikini.push_back(paz);
            int egz = 0;
            if (!laikini.empty()) {
                st.egz = laikini.back();
                laikini.pop_back(); // ismetam is vektoriaus, nes tai ne ND
            }
            st.nd = laikini;

            double suma = 0.0;
            if(p.pasirinkimas==1) //Vidurkis
            {
                for(auto x : st.nd) suma += x;
                double vidurkis = (st.nd.empty() ? 0 : suma / st.nd.size());
                st.galutinis = 0.4 * vidurkis + 0.6 * st.egz;
            }
            else //Mediana
            {
                sort(st.nd.begin(), st.nd.end());
                if(st.nd.size() % 2 == 0)
                    if (st.nd.size() >= 2)
                        st.galutinis = 0.4 * (st.nd[st.nd.size() / 2 - 1] + st.nd[st.nd.size() / 2]) / 2 + 0.6 * st.egz;
                    else if (st.nd.size() == 1) 
                        st.galutinis = 0.4 * st.nd[0] + 0.6 * st.egz;
                    else 
                    st.galutinis = 0.6 * st.egz;
                else
                    if (!st.nd.empty()) 
                        st.galutinis = 0.4 * st.nd[st.nd.size() / 2] + 0.6 * st.egz;
                    else 
                        st.galutinis = 0.6 * st.egz;  
            }
            if(st.vardas.size() > *max_vardas_size) *max_vardas_size = st.vardas.size();
            if(st.pavarde.size() > *max_pavarde_size) *max_pavarde_size = st.pavarde.size();
            studentai.push_back(st);
            st.nd.clear();
            p.m++;    
        }
        cout << "Failo is "<<studentai.size()<<" irasu nuskaitymo laikas: " << t1.elapsed() << " s" << endl;
        fin.close();
    }
p.b=5;


if(p.choice!=4)
    for(int i=0; i<p.m; i++)
    {
        st.vardas=vardai[i];
        st.pavarde=pavardes[i];
        p.b=5;

        if(p.choice==2 || p.choice==3)
        {
            cout<<i+1<<"-ojo studento namu darbu rezultatai: "<<endl;
            while(p.b==5)
            {
                cout<<i+1<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                laik=1+rand()%10;
                cout<<laik<<endl;
                cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.b; 
                ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
                st.nd.push_back(laik);
                p.n++;
            }
            st.egz = rand()%10+1;
            cout<<"Atsitiktinai sugeneruotas "<<i+1<<"-ojo studento egzamino rezultatas: "<< st.egz<<endl; 
        }   
        else if(p.choice==1)
        {
            cout<<"Iveskite "<<i+1<<"-ojo studento namu darbu rezultatus: ";
            while(p.b==5)
            {
                cout<<i+1<<"-ojo studento "<<p.n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                cin>>laik;
                ivedimas1(laik, "", "", 0, 1, 10);
                st.nd.push_back(laik);
                cout<<"Spauskite 5, jeigu norite irasyti dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>p.b; 
                ivedimas1(p.b, "rasyti daugiau", "nutraukti", 1, 5, 6);
                p.n++;
            }
            cout<<"Iveskite egzamino rezultata: "; cin>>st.egz; ivedimas1(st.egz, "", "", 0, 1, 10); 
            cout<<i+1<<"-ojo studento egzamino rezultatas: "<<st.egz<<endl;
        }
        p.c=0;
        double vidurkis=0.0;
        for(int j=0; j<p.n; j++)
            vidurkis+=st.nd[j];
        vidurkis/=p.n;
        st.galutinis=0.4*vidurkis+0.6*st.egz;
        if(p.pasirinkimas==2)
        {
            //Mediana:
            sort(st.nd.begin(), st.nd.end());
            if(p.n%2==0)
                st.galutinis=0.4*(st.nd[p.n/2-1]+st.nd[p.n/2])/2+0.6*st.egz;
            else
                st.galutinis=0.4*st.nd[p.n/2]+0.6*st.egz;
        }
        studentai.push_back(st);
        st.nd.clear();
        p.n=0;
    }
}