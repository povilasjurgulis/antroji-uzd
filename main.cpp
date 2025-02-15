#include "main.h"

int main(){
    vector<Studentas> studentai;
    Studentas st;
    srand(time(NULL));
    int m=0, n=0, pasirinkimas, a=3, b=5, c=0;
    
    string randomVyrVardai[20] = {"Povilas", "Eligijus", "Nikita", "Marius", "Justinas", "Karolis", "Arnas", "Matas", "Rokas", 
    "Kristupas", "Justas", "Kajus", "Ovidijus", "Jonas", "Arminas", "Kristijonas", "Eimantas", "Dominykas", "Nerijus", "Gitanas",};
    string randomMotVardai[20] = { "Ieva",  "Justina", "Karolina", "Laura", "Monika", "Neringa", "Sandra", "Simona", "Viktorija", "Emilija", "Lina", "Raminta", 
    "Ana", "Erika", "Inga", "Julija", "Kamila", "Marina", "Nora", "Sofija"};
    string randomVyrPavarde[20] = {"Jurgulis", "Alencikas", "Adamonis", "Bagdonas", "Simutis" "Girdenis", "Janonis", "Kairys", "Kavaliauskas",
    "Kvedaras", "Lapinskas", "Matulis", "Adomauskas", "Noreika", "Petronis", "Ragauskas", "Simonaitis", "Tautkus", "Vasiliauskas", "Zubovas" };
    string randomMotPavarde[20] = {"Adamoniene",  "Bagdonaite", "Daugelaite", "Girdenyte", "Janoniene", "Kairyte", "Kavaliukiene", "Kvedaraite",  "Lapinskiene", 
    "Matuliene", "Morkunaite", "Noreikaite", "Petroniene", "Ragauskaite", "Simonaitiene", "Tautkute", "Vasiliauskiene", "Zuboviene", "Jankauskaite", "Urboniene"};

    cout<<"Spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: "; 
    cin>>pasirinkimas;
    ivedimas2(studentai, pasirinkimas);

    while(a==3)
    {
        cout<<"Iveskite "<<m+1<<"-ojo studento varda: "; cin>>st.vardas;
        cout<<"Iveskite "<<m+1<<"-ojo studento pavarde: "; cin>>st.pavarde;
        cout<<"Spauskite 3, jeigu norite irasyti dar viena studenta, 4 - jeigu nenorite: "; cin>>a; ivedimas4(studentai, a);
        m++;
    }
    
    for(int i=0; i<m; i++)
    {
    cout<<"Ar norite, kad butu atsitiktinai sugeneruoti "<<i+1<<"-ojo studento namu darbu rezultatai? Spauskite 1 jei tap, 2 - jeigu ne "; cin>>c; ivedimas6(studentai, c);
    if(c==1)
    {
        cout<<i+1<<"-ojo studento namu darbu rezultatai: ";
    while(b==5)
    {
        cout<<n+1<<"-asis namu darbu rezultatas: ";
        int laik;
        laik=1+rand()%10;
        //ivedimas3(studentai, laik);
        cout<<laik<<endl;
        cout<<"Spauskite 5, jeigu norite, kad irasytume dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>b; ivedimas5(studentai, b);
        st.nd.push_back(laik);
        n++;
    }
    }   
    else 
    {
    cout<<"Iveskite "<<i+1<<"-ojo studento namu darbu rezultatus: ";
    while(b==5)
    {
        cout<<n+1<<"-asis namu darbu rezultatas: ";
        int laik;
        cin>>laik;
        ivedimas3(studentai, laik);
        cout<<laik<<endl;
        st.nd.push_back(laik);
        cout<<"Spauskite 5, jeigu norite irasyti dar viena nd rezultata, 6 - jeigu nenorite: "; cin>>b; ivedimas5(studentai, b);
        n++;
    }
    }
        b=5;
        c=0;
        cout<<"Ar norite, kad butu atsitiktinai sugeneruotas egzamino rezultatas? Spauskite 1 jei tap, 2 - jeigu ne "; cin>>c; ivedimas6(studentai, c);
    if(c==1)
    {
        st.egz = rand()%10+1;
        cout<<"Atsitiktinai sugeneruotas egzamino rezultatas: "<< st.egz<<endl; 
    }
    else
    {
        cout<<"Iveskite egzamino rezultata: "; cin>>st.egz; ivedimas3(studentai, st.egz); 
    }
    c=0;
    double vidurkis=0.0;
    for(int i=0; i<n; i++)
        vidurkis+=st.nd[i];
    vidurkis/=n;
    st.galutinis=0.4*vidurkis+0.6*st.egz;
    if(pasirinkimas==2)
    {
        //Mediana:
        sort(st.nd.begin(), st.nd.end());
        for(int i=0; i<m; i++)
        {
            if(n%2==0)
                st.galutinis=0.4*(st.nd[n/2-1]+st.nd[n/2])/2+0.6*st.egz;
            else
                st.galutinis=0.4*st.nd[n/2]+0.6*st.egz;
        }
    }
    studentai.push_back(st);
    st.nd.clear();
    n=0;
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