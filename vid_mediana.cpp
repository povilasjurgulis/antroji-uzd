#include "deklaracijos.h"
void vid_mediana(Studentas &st, Pasirinkimas p)
{
    p.c=0;
    double vidurkis=0.0;
        
    for(int j=0; j<p.n; j++)
        vidurkis+=st.nd[j];
    vidurkis/=p.n;

    st.galutinis=0.4*vidurkis+0.6*st.egz;
    if(p.vid_ar_med==2)
    {
        //Mediana:
        sort(st.nd.begin(), st.nd.end());
        if(p.n%2==0)
            st.galutinis=0.4*(st.nd[p.n/2-1]+st.nd[p.n/2])/2+0.6*st.egz;
        else
            st.galutinis=0.4*st.nd[p.n/2]+0.6*st.egz;
    }
}