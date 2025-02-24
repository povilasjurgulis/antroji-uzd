#include "main.h"
#include "vektoriaiLib.cpp"

//Su vektoriais: pradzia!
int main(){
    cout<<"Spauskite 1, jeigu norite pradeti darba, 2 - jeigu norite baigti darba: "; int e; cin>>e; ivedimas7(e);
    if(e==2) return 0;

    vector<Studentas> studentai;
    vector<string> vardai, pavardes;
    Studentas st; //Gal istrinti reikes
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
        string failoVardas = "kursiokai.txt";
        //cout<<"Iveskite failo pavadinima: "; cin>>failoVardas;
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
            int paz;;
            while(iss>>paz)
                laikini.push_back(paz);
            int egz = 0;
            if (!laikini.empty()) {
                st.egz = laikini.back();
                laikini.pop_back(); // ismetam is vektoriaus, nes tai ne ND
            }
            st.nd = laikini;
            double suma = 0.0;
            if(pasirinkimas==1)
            {
                for(auto x : st.nd) suma += x;
                double vidurkis = (st.nd.empty() ? 0 : suma / st.nd.size());
                st.galutinis = 0.4 * vidurkis + 0.6 * st.egz;
            }
            else
            {
                sort(st.nd.begin(), st.nd.end());
                if(st.nd.size() % 2 == 0)
                    st.galutinis = 0.4 * (st.nd[st.nd.size() / 2 - 1] + st.nd[st.nd.size() / 2]) / 2 + 0.6 * st.egz;
                else
                    st.galutinis = 0.4 * st.nd[st.nd.size() / 2] + 0.6 * st.egz;
            }
            studentai.push_back(st);
            m++;
        }
        fin.close();
    }
    b=5;

    for(int i=0; i<m; i++)
    {
        if(d==4) break; 
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

    int rikiavimas;
    cout << "Pasirinkite, pagal ka rikiuoti:\n"
         << "  1 - pagal varda\n"
         << "  2 - pagal pavarde\n"
         << "  3 - pagal galutini bala\n";
    cin >> rikiavimas;
    switch(rikiavimas) {
        case 1:
            sort(studentai.begin(), studentai.end(),
                 [](const Studentas &a, const Studentas &b){
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
        default:
            cout << "Neteisingas pasirinkimas - nerikiuojame.\n";
            break;
    }

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
    return 0;
}
