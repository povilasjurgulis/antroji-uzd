#include "main.h"

int main(){
    vector<Studentas> studentai;
    Studentas st;
    int m, n, pasirinkimas;
    cout<<"Kiek bus studentu? "; cin>>m; 
    cout<<"Kiek bus namu darbu vienam studentui? "; cin>>n;
    cout<<"Spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: "; 
    cin>>pasirinkimas;
    
    while(pasirinkimas!=1 && pasirinkimas!=2 )
    {
        cout<<"Prasau spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: "; 
        if (!(cin >> pasirinkimas)) {
            cout << "Negalima rasyti raidziu!\n";
            cin.clear(); // clear the error state
            // discard everything remaining in the buffer up to newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //continue;
        }
        else cout<<"Neteisingas pasirinkimas. ";
        cin>>pasirinkimas;
    }
    for(int i=0; i<m; i++)
    {
    cout<<"Iveskite "<<i+1<<"-ojo studento varda: "; cin>>st.vardas;
    cout<<"Iveskite "<<i+1<<"-ojo studento pavarde: "; cin>>st.pavarde;
    cout<<"Iveskite "<<i+1<<"-ojo studento namu darbu rezultatus: ";
    for(int j=0; j<n; j++){
        cout<<j+1<<"-asis namu darbu rezultatas: ";
        int laik;
        cin>>laik;
        st.nd.push_back(laik);
    }
    cout<<"Iveskite egzamino rezultata: "; cin>>st.egz;

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
