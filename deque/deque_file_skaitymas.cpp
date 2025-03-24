#include "deque_deklaracijos.h" 
void file_skaitymas(int &vard_size, int &pav_size, Pasirinkimas p, Studentas st, deque<Studentas>& studentai, deque<string> vardai, deque<string> pavardes, time_point<high_resolution_clock> &start, int *max_vardas_size, int *max_pavarde_size)
{
string failoVardas;
        //cout << "Spauskite 1, jeigu norite nuskaityti duomenis is kursiokai2nd.txt failo, 2 - jeigu is kursiokai.txt,";
        //cout<<" 3 - jeigu norite ivesti failo pavadinima (is kurio nuskaityti): "; 
        cin >> p.choice1; ivedimas1(p.choice1, "", "", 0, 1, 3);
        
        if(p.choice1==2) failoVardas = "kursiokai.txt";
        else if(p.choice1==1) 
        {
            failoVardas = "kursiokai2nd.txt";
        }
        else if(p.choice1==3) 
        {
            //cout << "Iveskite failo pavadinima, is kurio norite nuskaityti duomenis: "; 
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
            deque<int> laikini;
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
        cout << "Failo is "<<studentai.size()<<" irasu nuskaitymo laikas: " << fixed <<setprecision(4) << t1.elapsed() << " s" << endl;
        fin.close();
    }