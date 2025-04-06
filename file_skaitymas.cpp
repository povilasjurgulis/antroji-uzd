#include "deklaracijos.h" 
void file_skaitymas(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, vector<Studentas>& studentai, vector<string> vardai, vector<string> pavardes, time_point<high_resolution_clock> &start, int *max_vardas_size, int *max_pavarde_size)
{
string failoVardas;
        cout << "Spauskite 1, jeigu norite nuskaityti duomenis is kursiokai2nd.txt failo, 2 - jeigu is kursiokai.txt,";
        cout<<" 3 - jeigu norite ivesti failo pavadinima (is kurio nuskaityti): "; 
        cin >> p.koks_file_pavadinimas; ivedimas1(p.koks_file_pavadinimas, "", "", 0, 1, 3);
        
        if(p.koks_file_pavadinimas==2) failoVardas = "kursiokai.txt";
        else if(p.koks_file_pavadinimas==1) 
        {
            failoVardas = "kursiokai2nd.txt";
        }
        else if(p.koks_file_pavadinimas==3) 
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
            string laikVardas, laikPavarde;
            if(eilute.empty()) continue;
            istringstream iss(eilute);
            iss>>laikVardas>>laikPavarde;
            st.SetVardas(laikVardas);
            st.SetPavarde(laikPavarde);
            vector<int> laikini;
            int paz;
            while(iss>>paz)
                laikini.push_back(paz);
            int egz = 0;
            if (!laikini.empty()) {
                st.SetEgz(laikini.back());
                laikini.pop_back(); // ismetam is vektoriaus, nes tai ne ND
            }
            st.SetAllNd(laikini);

            if(p.vid_ar_med==1) //Vidurkis
            {
                st.CalcVid();
            }
            else //Mediana
            {
                st.CalcMed();
            }
            if(st.GetVardasSize() > *max_vardas_size) *max_vardas_size = st.GetVardasSize();
            if(st.GetPavardeSize() > *max_pavarde_size) *max_pavarde_size = st.GetPavardeSize();
            studentai.push_back(st);
            st.NdClear();
            p.m++;    
        }
        cout << "Failo is "<<studentai.size()<<" irasu nuskaitymo laikas: " << fixed << setprecision(4) << t1.elapsed() << " s" << endl;
        fin.close();
    }