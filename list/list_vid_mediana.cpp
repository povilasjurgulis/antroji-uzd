#include "list_deklaracijos.h"
void vid_mediana(Studentas &st, Pasirinkimas p)
{
    p.c=0;
    if(p.pasirinkimas==1)
    {
        double vidurkis=0.0;
        
        for (double grade : st.nd) {
            vidurkis += grade;
            }
        vidurkis/=p.n;
        st.galutinis=0.4*vidurkis+0.6*st.egz;
    }
    else if(p.pasirinkimas==2)
    {
        //Mediana:
        double mediana = 0.0;
        auto n = st.nd.size();

        st.nd.sort();
        if(p.n%2==0)
            {
                auto it = st.nd.begin();
                advance(it, p.n/2-1);
                mediana = *it;
                advance(it, 1);
                mediana += *it;
                mediana /= 2;
                st.galutinis=0.4*mediana+0.6*st.egz;
            }
        else
            {
                auto it = st.nd.begin();
                advance(it, p.n/2);
                mediana = *it;
                st.galutinis=0.4*mediana+0.6*st.egz;
            }
    }
}