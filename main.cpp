#include "main.h"
// #include "vektoriaiLib.cpp" 

//Su vektoriais: pradzia!
int main(){
    
    cout<<"Spauskite 1, jeigu norite pradeti darba, 2 - jeigu norite baigti darba: "; int e; cin>>e; ivedimas7(e, "pradeti", "baigti");
    if(e==2) return 0;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    vector<Studentas> studentai;
    vector<string> vardai, pavardes;
    Studentas st;
    srand(time(NULL));
    int m=0, n=0, pasirinkimas, a=3, b=5, c=0, d=0;
    
    cout<<"Spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: "; cin>>pasirinkimas; ivedimas2(studentai, pasirinkimas);

    string randomVyrVardai[20] = {"Povilas", "Eligijus", "Nikita", "Marius", "Justinas", "Karolis", "Arnas", "Matas", "Rokas", 
    "Kristupas", "Justas", "Kajus", "Ovidijus", "Jonas", "Arminas", "Kristijonas", "Eimantas", "Dominykas", "Nerijus", "Gitanas",};
    string randomMotVardai[20] = {"Ieva",  "Justina", "Karolina", "Laura", "Monika", "Neringa", "Sandra", "Simona", "Viktorija", "Emilija", "Lina", "Raminta", 
    "Ana", "Erika", "Inga", "Julija", "Kamila", "Marina", "Nora", "Sofija"};
    string randomVyrPavarde[20] = {"Jurgulis", "Alencikas", "Adamonis", "Bagdonas", "Simutis", "Girdenis", "Janonis", "Kairys", "Kavaliauskas",
    "Kvedaras", "Lapinskas", "Matulis", "Adomauskas", "Noreika", "Petronis", "Ragauskas", "Simonaitis", "Tautkus", "Vasiliauskas", "Zubovas" };
    string randomMotPavarde[20] = {"Adamoniene",  "Bagdonaite", "Daugelaite", "Girdenyte", "Janoniene", "Kairyte", "Kavaliukiene", "Kvedaraite",  "Lapinskiene", 
    "Matuliene", "Morkunaite", "Noreikaite", "Petroniene", "Ragauskaite", "Simonaitiene", "Tautkute", "Vasiliauskiene", "Zuboviene", "Jankauskaite", "Urboniene"};

    cout<<"Spauskite 1, jeigu norite viska rasyti ranka. 2 - jeigu norite, kad tik pazymiai butu atsitiktinai sugeneruoti. \n3 - jeigu norite, kad pazymiai, studentu vardai ir pavardes butu atsitiktinai sugeneruoti. ";
    cout<<"Spauskite 4, jeigu norite, kad visi duomenys butu nuskaityti is failo: "; 
    cin>>d; ivedimas8(studentai, d);
    if(d==1 || d==2)
    while(a==3)
    {
        string vardas, pavarde;
        cout<<"Iveskite "<<m+1<<"-ojo studento varda: "; cin>>vardas;
        cout<<"Iveskite "<<m+1<<"-ojo studento pavarde: "; cin>>pavarde;
        vardai.push_back(vardas);
        pavardes.push_back(pavarde);
        cout<<"Spauskite 3, jeigu norite irasyti dar viena studenta, 4 - jeigu nenorite: "; cin>>a; ivedimas4(studentai, a);
        m++;
    }
    else if(d==3)
    {
        cout<<"Atsitiktinai sugeneruoti studentai: "<<endl;
        while(b==5)
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
            cout<<m+1<<"-ojo studento vardas ir pavarde: "<<vardai[m]<<" "<<pavardes[m]<<endl;
            cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena studenta, 6 - jeigu nenorite: "; cin>>b; ivedimas5(studentai, b);
            m++;
        }
    }
    else{ //Nuskaito is failo:
        start = std::chrono::high_resolution_clock::now(); // Pradedame skaiciuoti laika
        string failoVardas = "kursiokai.txt";
        ifstream fin(failoVardas);
        if(!fin)
        {
            cout<<"Failas nerastas!"<<endl;
            return 0;
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
            if(pasirinkimas==1) //Vidurkis
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
            m++;
        }
        fin.close();
    }
    b=5;

    if(d!=4)
    for(int i=0; i<m; i++)
    {
        st.vardas=vardai[i];
        st.pavarde=pavardes[i];
        b=5;

        if(d==2 || d==3)
        {
            cout<<i+1<<"-ojo studento namu darbu rezultatai: "<<endl;
            while(b==5)
            {
                cout<<i+1<<"-ojo studento "<<n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                laik=1+rand()%10;
                cout<<laik<<endl;
                cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>b; ivedimas5(studentai, b);
                st.nd.push_back(laik);
                n++;
            }
            st.egz = rand()%10+1;
            cout<<"Atsitiktinai sugeneruotas "<<i+1<<"-ojo studento egzamino rezultatas: "<< st.egz<<endl; 
        }   
        else if(d==1)
        {
            cout<<"Iveskite "<<i+1<<"-ojo studento namu darbu rezultatus: ";
            while(b==5)
            {
                cout<<i+1<<"-ojo studento "<<n+1<<"-asis namu darbu rezultatas: ";
                int laik;
                cin>>laik;
                ivedimas3(studentai, laik);
                st.nd.push_back(laik);
                cout<<"Spauskite 5, jeigu norite irasyti dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>b; ivedimas5(studentai, b);
                n++;
            }
            cout<<"Iveskite egzamino rezultata: "; cin>>st.egz; ivedimas3(studentai, st.egz); 
            cout<<i+1<<"-ojo studento egzamino rezultatas: "<<st.egz<<endl;
        }
        c=0;
        double vidurkis=0.0;
        for(int j=0; j<n; j++)
            vidurkis+=st.nd[j];
        vidurkis/=n;
        st.galutinis=0.4*vidurkis+0.6*st.egz;
        if(pasirinkimas==2)
        {
            //Mediana:
            sort(st.nd.begin(), st.nd.end());
            if(n%2==0)
                st.galutinis=0.4*(st.nd[n/2-1]+st.nd[n/2])/2+0.6*st.egz;
            else
                st.galutinis=0.4*st.nd[n/2]+0.6*st.egz;
        }
        studentai.push_back(st);
        st.nd.clear();
        n=0;
    }

    vardai.clear();
    pavardes.clear();
    auto end = std::chrono::high_resolution_clock::now(); // Skaiciavimo pabaiga
    std::chrono::duration<double> diff = end-start; // Skaiciuojame skirtuma
    int rikiavimas;
    cout << "Pasirinkite, pagal ka rikiuoti:\n" << "  1 - pagal varda"<< "  2 - pagal pavarde"<< "  3 - pagal galutini bala: "; cin >> rikiavimas;
    ivedimas9(studentai, rikiavimas);
    auto start1 = std::chrono::high_resolution_clock::now(); // Pradedame skaiciuoti laika
    switch(rikiavimas) {
        case 1:
            sort(studentai.begin(), studentai.end(),
                 [](const Studentas &a, const Studentas &b){ // Lambda funkcija
                     return a.vardas < b.vardas;
                 });
            break;
        case 2:
            sort(studentai.begin(), studentai.end(),
                 [](const Studentas &a, const Studentas &b){
                     return a.pavarde < b.pavarde;
                 });
            break;
        case 3:
            sort(studentai.begin(), studentai.end(),
                 [](const Studentas &a, const Studentas &b){
                     return a.galutinis < b.galutinis;
                 });
            break;
        default: // Kai nei 1, nei 2, nei 3
            cout << "Neteisingas pasirinkimas - nerikiuojame.\n";
            break;
    }
    auto end1 = std::chrono::high_resolution_clock::now(); // Skaiciavimo pabaiga
    std::chrono::duration<double> diff1 = end1-start1; // Skaiciuojame skirtuma

    cout<<"Ar norite, kad rezultatai butu isvedami i faila? 1 - taip, 2 - ne: "; cin>>c; ivedimas7(c, "isvesti i faila", "neisvesti i faila");

    auto start2 = std::chrono::high_resolution_clock::now(); // Pradedame skaiciuoti laika

    ofstream fout("rezultatai.txt");
    if(!fout)
    {
        cout<<"Rezultatu failas nesukurtas!"<<endl;
        return 0;
    }
    if(c==1)
    {
        if(pasirinkimas==1) //Vidurkis
        {
            fout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=1; i<m; i++) // i=1, nes pirmas studentas nera studentas, bet yra antraste
            {
                fout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
            }   
        }
        else if(pasirinkimas==2) //Mediana
        {
            fout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Med.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=1; i<m; i++)
            {
                fout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
            }
        }
    }
    else
    {
        if(pasirinkimas==1) //Vidurkis
        {
            cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=0; i<m; i++)
                {
                cout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
                }
        }
        else if(pasirinkimas==2) //Mediana
        {
            cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Med.)"<<"\n"<<string(50, '-')<<endl;
            for(int i=0; i<m; i++)
                {
                cout<<left<<setw(15)<<studentai[i].pavarde<<setw(15)<<studentai[i].vardas<<setw(15)<<fixed<<setprecision(2)<<studentai[i].galutinis<<endl;
                }
        }
    }
    fout.close();
    auto end2 = std::chrono::high_resolution_clock::now(); // Skaiciavimo pabaiga
    std::chrono::duration<double> diff2 = end2-start2; // Skaiciuojame skirtuma
    std::chrono::duration<double> diffFinal = diff+diff1+diff2;
    if(d==4)
    cout<<"Programos vykdymo laikas: "<<diffFinal.count()<<" s\n"<<endl;
    return 0;
}
