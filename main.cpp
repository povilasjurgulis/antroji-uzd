#include "main.h"

int main(){
    vector<Studentas> studentai;
    Studentas st;
    int m, n, pasirinkimas;
    cout<<"Kiek bus studentu? "; cin>>m;  ivedimas1(studentai, m); 
    cout<<"Kiek bus namu darbu vienam studentui? "; cin>>n; ivedimas1(studentai, n);
    cout<<"Spauskite 1, jeigu norite, kad galutiniam balui butu naudojamas vidurkis, 2 - jeigu mediana: "; 
    cin>>pasirinkimas;
    ivedimas2(studentai, pasirinkimas);
    
    for(int i=0; i<m; i++)
    {
    cout<<"Iveskite "<<i+1<<"-ojo studento varda: "; cin>>st.vardas;
    cout<<"Iveskite "<<i+1<<"-ojo studento pavarde: "; cin>>st.pavarde;
    cout<<"Iveskite "<<i+1<<"-ojo studento namu darbu rezultatus: ";
    for(int j=0; j<n; j++){
        cout<<j+1<<"-asis namu darbu rezultatas: ";
        int laik;
        cin>>laik;
        ivedimas3(studentai, laik);
        st.nd.push_back(laik);
    }
    cout<<"Iveskite egzamino rezultata: "; cin>>st.egz; ivedimas3(studentai, st.egz);

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
