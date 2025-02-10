#include "main.h"

int main(){
    vector<Studentas> studentai;
    Studentas st;
    int m, n;
    cout<<"Kiek bus studentu?"; cin>>m; 
    cout<<"Kiek bus namu darbu vienam studentui?"; cin>>n;
    
    for(int i=0; i<m; i++)
    {
    cout<<"Iveskite studento varda: "; cin>>st.vardas;
    cout<<"Iveskite studento pavarde: "; cin>>st.pavarde;
    cout<<"Iveskite namu darbu rezultatus: ";
    for(int j=0; j<n; j++){
        cout<<j+1<<"-ojo namu darbo rezultatas: ";
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
    studentai.push_back(st);
    st.nd.clear();
    cout<<left<<setw(15)<<"Pavarde"<<setw(15)<<"Vardas"<<setw(15)<<"Galutinis (Vid.)"<<"\n"<<string(50, '-')<<endl;
    cout<<left<<setw(15)<<st.pavarde<<setw(15)<<st.vardas<<setw(15)<<fixed<<setprecision(2)<<st.galutinis<<endl;
}
    return 0;
}
