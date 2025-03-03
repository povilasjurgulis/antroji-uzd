#include "deklaracijos.h"
void ifs(Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, string randomVyrVardai[], string randomMotVardai[], string randomVyrPavarde[], string randomMotPavarde[], std::chrono::time_point<std::chrono::high_resolution_clock> &start)
{
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
        }
    }
    else{ //Nuskaito is failo:
        start = high_resolution_clock::now(); // Pradedame skaiciuoti laika
        string failoVardas;
        if(p.choice1==2) failoVardas = "kursiokai.txt";
        else if(p.choice1==1) 
        {
            failoVardas = "kursiokai2nd.txt";
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
            cerr << "Įvyko klaida " << endl; // e.what()
            exit(1); // Iseiti su klaidos kodu 1
        }
        string eilute;
        if(getline(fin, eilute)) // nuskaitome pirma eilute
            if(eilute.find("Vardas") == std::string::npos && eilute.find("Pavarde") == std::string::npos) 
                istringstream iss(eilute);
        fin.clear(); // sugraziname „head“ i failo pradzia
        fin.seekg(0, std::ios::beg); // ir nuskaitome duomenis is naujo
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
            studentai.push_back(st);
            st.nd.clear();
            p.m++;
        }
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