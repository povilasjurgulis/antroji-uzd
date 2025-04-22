#include "studentai.h"

Studentas::Studentas(string vardas, string pavarde, int egz, vector <int> nd)
{
    this->vardas = vardas;
    this->pavarde = pavarde;
    this->egz = egz;
    this->nd = nd;
}

Studentas::~Studentas()
{
    this->vardas.clear();
    this->pavarde.clear();
    this->nd.clear();
    this->egz = 0;
    this->galutinis = 0.0;
}

string Studentas::GetVardas() const 
{ 
    return this->vardas; 
}

string Studentas::GetPavarde() const 
{ 
    return this->pavarde; 
}

int Studentas::GetEgz() const 
{ 
    return this->egz; 
}

vector<int> Studentas::GetNd() const 
{ 
    return this->nd; 
}

double Studentas::GetGalutinis() const 
{ 
    return this->galutinis; 
}

void Studentas::SetVardas(string vardas) 
{ 
    this->vardas = vardas; 
}

void Studentas::SetPavarde(string pavarde) 
{ 
    this->pavarde = pavarde; 
}

void Studentas::SetEgz(int egz)
{
    if(egz < 0 || egz > 10)
    {
        std::cout << "Egzamino balas turi buti tarp 0 ir 10" << endl;
        return;
    }
    this->egz = egz;
}

void Studentas::SetNd(int &nd)
{
    if(nd < 0 || nd > 10)
    {
        std::cout << "Namu darbu balai turi buti tarp 0 ir 10" << endl;
        return;
    }
    this->nd.push_back(nd);
}

void Studentas::SetGalutinis(double galutinis)
{
    this->galutinis = galutinis;
}

void Studentas::NdClear()
{
    this->nd.clear();
}

int Studentas::GetVardasSize()
{
    return this->vardas.size();
}

int Studentas::GetPavardeSize()
{
    return this->pavarde.size();
}

void Studentas::SetAllNd(vector<int> nd)
{
    this->nd = nd;
}

void Studentas::CalcVid()
{
    double vidurkis=0.0;
        
    for(int j=0; j<nd.size(); j++)
        vidurkis+=nd[j];
    vidurkis/=nd.size();

    galutinis=0.4*vidurkis+0.6*egz;
}

void Studentas::CalcMed()
{
        //Mediana:
        sort(nd.begin(), nd.end());
        if(nd.size()%2==0)
            galutinis=0.4*(nd[nd.size()/2-1]+nd[nd.size()/2])/2+0.6*egz;
        else
            galutinis=0.4*nd[nd.size()/2]+0.6*egz;
}

void Studentas::Rikiavimas(vector<Studentas>& studentai, int rikiavimas)
{
        switch(rikiavimas) {
            case 1:
                sort(studentai.begin(), studentai.end(),
                     [](const Studentas &a, const Studentas &b){ // Lambda funkcija
                         return a.GetVardas() < b.GetVardas();
                     });
                break;
            case 2:
                sort(studentai.begin(), studentai.end(),
                     [](const Studentas &a, const Studentas &b){
                         return a.GetPavarde() < b.GetPavarde();
                     });
                break;
            case 3:
                sort(studentai.begin(), studentai.end(),
                     [](const Studentas &a, const Studentas &b){
                         return a.GetGalutinis() < b.GetGalutinis();
                     });
                break;
            default: // Kai nei 1, nei 2, nei 3
                cout << "Neteisingas pasirinkimas - nerikiuojame.\n";
                break;
        }
}

Studentas::Studentas(const Studentas &naujas) //Copy konstruktorius
{
    this->vardas = naujas.vardas;
    this->pavarde = naujas.pavarde;
    this->egz = naujas.egz;
    this->nd = naujas.nd;
    this->galutinis = naujas.galutinis;
}

Studentas& Studentas::operator=(const Studentas& naujas) //Copy priskyrimo operatorius
{
    if(this != &naujas) // Patikriname ar ne priskiriame patys sau
    {
        this->vardas = naujas.vardas;
        this->pavarde = naujas.pavarde;
        this->egz = naujas.egz;
        this->nd = naujas.nd;
        this->galutinis = naujas.galutinis;
    }
    return *this; // Graziname save
}

Studentas::Studentas(Studentas&& naujas) noexcept //Move konstruktorius
{
    this->vardas = move(naujas.vardas);
    this->pavarde = move(naujas.pavarde);
    this->egz = naujas.egz;
    this->nd = move(naujas.nd);
    this->galutinis = naujas.galutinis;
    naujas.egz = 0; // Istriname egzamino bala
    naujas.galutinis = 0; // Istriname galutini bala
    naujas.nd.clear(); // Istriname namu darbu rezultatus
    naujas.vardas.clear(); // Istriname varda
    naujas.pavarde.clear(); // Istriname pavarde
}

Studentas& Studentas::operator=(Studentas&& naujas) noexcept //Move priskyrimo operatorius
{
    if(this != &naujas) // Patikriname ar ne priskiriame patys sau
    {
        this->vardas = move(naujas.vardas);
        this->pavarde = move(naujas.pavarde);
        this->egz = naujas.egz;
        this->nd = move(naujas.nd);
        this->galutinis = naujas.galutinis;
        naujas.egz = 0; // Istriname egzamino bala
        naujas.galutinis = 0; // Istriname galutini bala
        naujas.nd.clear(); // Istriname namu darbu rezultatus
        naujas.vardas.clear(); // Istriname varda
        naujas.pavarde.clear(); // Istriname pavarde
    }
    return *this; // Graziname save
}

istream& operator>>(istream& is, Studentas& studentas) // Ivedimo operatorius
{
    int kiek_kartu_loopinta = 0; // Kiek kartu loopinta

    std::cout << "Iveskite varda: ";
    is >> studentas.vardas;
    std::cout << "Iveskite pavarde: ";
    is >> studentas.pavarde;
    std::cout << "Iveskite egzamino rezultata (1-10): ";
    int temp_egz;
    while (true) {
    if (!(is >> temp_egz)) {
        // Jei įvesta ne skaičius
        std::cout << "Klaida! Iveskite skaiciu: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }
    
    // Tikriname ar po skaičiaus nėra kitų simbolių
    if (is.peek() != '\n' && is.peek() != EOF) {
        std::cout << "Iveskite tik skaiciu be papildomu simboliu: ";
        is.clear();
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }
    
    // Tikriname ar skaičius yra tinkamame intervale
    if (temp_egz < 1 || temp_egz > 10) {
        std::cout << "Egzamino rezultatas turi buti nuo 1 iki 10. Bandykite dar karta: ";
        continue;
    }
    
    // Jei viskas gerai, priskiriame reikšmę ir išeiname iš ciklo
    studentas.egz = temp_egz;
    break;
    }
    

    int laik;
    while (true) {
        if(kiek_kartu_loopinta == 0)
        {
        std::cout << "Iveskite namu darbu rezultata (1-10): ";
        is >> laik;
        //Tikriname:
            if (laik < 1 || laik > 10) {
            std::cerr << "Namu darbu rezultatas turi buti nuo 1 iki 10 (iskaitant 10)." << std::endl;
            continue; // Prasome ivesti teisinga rezultata
            if (cin.fail() || cin.peek() != '\n' || laik < 1 || laik > 10) 
            {
                cin.clear();  
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                while (true) 
                {
                    cout << "Iveskite skaiciu (nuo "<<1<<" iki "<<10<<" (iskaitant "<<10<<"), be kablelio): ";
                    if (!(cin >> laik)) 
                    {
                        cout << "(Negalima rasyti raidziu ar kableliu!)\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if (cin.peek() != '\n') 
                    {
                        cout << "(Prasome ivesti sveika skaiciu BE kablelio!)\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if (laik < 1 || laik > 10) 
                    {
                        cout << "(Skaicius turi buti bent "<<1<<", bet mazesnis (arba lygus) uz "<<10<<"!)\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                    break;
                }    
            }
        }
        }
        // Pridedame namu darbu rezultata i vektoriu
        studentas.nd.push_back(laik);

        std::cout << "Iveskite namu darbu rezultata (1-10) arba spauskite -1, jei norite baigti rasyti ND: ";
        is >> laik;
        if (laik == -1) break; // Baigti ivedima

        //Tikriname:
        if (laik < 1 || laik > 10) {
            std::cerr << "Namu darbu rezultatas turi buti nuo 1 iki 10 (iskaitant 10)." << std::endl;
            continue; // Prasome ivesti teisinga rezultata
            if (cin.fail() || cin.peek() != '\n' || laik < 1 || laik > 10) 
            {
                cin.clear();  
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                while (true) 
                {
                    cout << "Iveskite skaiciu (nuo "<<1<<" iki "<<10<<" (iskaitant "<<10<<"), be kablelio): ";
                    if (!(cin >> laik)) 
                    {
                        cout << "(Negalima rasyti raidziu ar kableliu!)\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if (cin.peek() != '\n') 
                    {
                        cout << "(Prasome ivesti sveika skaiciu BE kablelio!)\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    if (laik < 1 || laik > 10) 
                    {
                        cout << "(Skaicius turi buti bent "<<1<<", bet mazesnis (arba lygus) uz "<<10<<"!)\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                    break;
                }    
            }
        }
        studentas.nd.push_back(laik);
        kiek_kartu_loopinta++; // Padidiname loopinimo skaiciu
    }
    return is;
}

ifstream& operator>>(ifstream& is, Studentas& studentas) // Ivedimo operatorius is failo
{
    string eilute;
    if (getline(is, eilute)) // Skaitome viena eilute - viena studenta
    {
        if(eilute.empty()) return is;
        
        istringstream iss(eilute);
        string laikVardas, laikPavarde;
        iss >> laikVardas >> laikPavarde;
        
        studentas.vardas = laikVardas;
        studentas.pavarde = laikPavarde;
        
        vector<int> laikini;
        int paz;
        while(iss >> paz)
            laikini.push_back(paz);
            
        if (!laikini.empty()) {
            studentas.egz = laikini.back();
            laikini.pop_back(); // ismetam is vektoriaus, nes tai ne ND
        }
        
        studentas.nd = laikini;
    }
    return is;
}

ostream& operator<<(ostream& os, const Studentas& studentas) // Isvedimo operatorius
{
    os << left << setw(20) << studentas.pavarde << setw(20) << studentas.vardas << setw(20) << fixed << setprecision(2) << studentas.galutinis << endl;
        return os;
}

ofstream& operator<<(ofstream& os, const vector<Studentas>& studentai) // Isvedimo operatorius i faila
{
    for (const auto& studentas : studentai) {
        os << studentas << endl;
    }
    return os;
}

ostream& operator<<(ostream& os, const vector<Studentas>& studentai) // Visu studentu isvedimo operatorius i ekrana
{
    for (const auto& studentas : studentai) {
        os << studentas << endl;
    }
    return os;
}