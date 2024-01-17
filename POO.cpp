FAZA I
#include <iostream>
#include <string>
using namespace std;

// Clasa pentru obiectul "Aragaz"
class Aragaz {
public:
    // Atribute
        string marca;
    int numar_arzatoare;
    static int numar_aragazuri_vandute;
    const int an_fabricatie;

    // Pointer pentru a aloca spatiu in HEAP
    double* dimensiune;

    // Constructori
    Aragaz(std::string m, int n, double latime, double lungime) : an_fabricatie(2020) {
        marca = m;
        numar_arzatoare = n;
        dimensiune = new double[2];
        dimensiune[0] = latime;
        dimensiune[1] = lungime;
        numar_aragazuri_vandute++;
    }

    // ... mai multi constructori

    // Functie statica
    static void afiseazaNumarAragazuriVandute() {
            cout << "Numar aragazuri vandute: " << numar_aragazuri_vandute <<     endl;
    }

    // Destructor
    ~Aragaz() {
        delete[] dimensiune;
    }
};

// Initializare variabila statica
int Aragaz::numar_aragazuri_vandute = 0;

// Clasa pentru obiectul "Blender"
class Blender {
public:
        string model;
    static int numar_viteze;
    const double capacitate_maxima;

    double* putere;

    // Constructori
    Blender(std::string mod, int nv, double capacitate, double p) : capacitate_maxima(capacitate) {
        model = mod;
        numar_viteze = nv;
        putere = new double;
        *putere = p;
    }

    // ... mai multi constructori

    static void afiseazaNumarViteze() {
            cout << "Numar viteze: " << numar_viteze <<     endl;
    }

    ~Blender() {
        delete putere;
    }
};

// Initializare variabila statica
int Blender::numar_viteze = 0;

// Clasa pentru obiectul "Balansoar de bucatarie"
class BalansoarBucatarie {
public:
        string culoare;
    static bool estePliabil;
    const double inaltime_maxima;

    double* latime;

    // Constructori
    BalansoarBucatarie(std::string c, bool pliabil, double inaltime, double l) : inaltime_maxima(inaltime) {
        culoare = c;
        estePliabil = pliabil;
        latime = new double;
        *latime = l;
    }

    // ... mai multi constructori

    static void afiseazaPliabil() {
            cout << "Este pliabil: " << (estePliabil ? "Da" : "Nu") <<     endl;
    }

    ~BalansoarBucatarie() {
        delete latime;
    }
};

// Initializare variabila statica
bool BalansoarBucatarie::estePliabil = false;

int main() {
    // Crearea si initializarea obiectelor
    Aragaz aragaz1("Electrolux", 4, 60, 50);
    Aragaz aragaz2("Bosch", 5, 80, 60);
    Aragaz aragaz3("Samsung",
        6, 90, 70);

   
        Blender blender1("Philips", 3, 1.5, 500);
    Blender blender2("Braun", 5, 2.0, 800);
    Blender blender3("Ninja", 10, 2.5, 1200);

    BalansoarBucatarie balansoar1("Rosu", true, 1.2, 0.5);
    BalansoarBucatarie balansoar2("Albastru", false, 1.5, 0.7);
    BalansoarBucatarie balansoar3("Verde", true, 1.3, 0.6);

    // Apelarea functiilor statice pentru fiecare clasa
    Aragaz::afiseazaNumarAragazuriVandute();
    Blender::afiseazaNumarViteze();
    BalansoarBucatarie::afiseazaPliabil();

    return 0;
}

FAZA II
#include <iostream>
#include <string>
using namespace std;

class Aragaz {
private:
          string marca;
    int numar_arzatoare;
    double* dimensiune;

public:
    static int numar_aragazuri_vandute;
    const int an_fabricatie;

    // Constructori
    Aragaz(std::string m, int n, double latime, double lungime) : an_fabricatie(2020), marca(m), numar_arzatoare(n) {
        dimensiune = new double[2];
        dimensiune[0] = latime;
        dimensiune[1] = lungime;
        numar_aragazuri_vandute++;
    }

    // Constructor de copiere
    Aragaz(const Aragaz& alt) : an_fabricatie(alt.an_fabricatie), marca(alt.marca), numar_arzatoare(alt.numar_arzatoare) {
        dimensiune = new double[2];
        dimensiune[0] = alt.dimensiune[0];
        dimensiune[1] = alt.dimensiune[1];
    }

    // Destructor
    ~Aragaz() {
        delete[] dimensiune;
    }

    // Get-eri și Set-eri
          string getMarca() const { return marca; }
    void setMarca(const       string& val) { marca = val; }

    int getNumarArzatoare() const { return numar_arzatoare; }
    void setNumarArzatoare(int val) { numar_arzatoare = val; }

    double* getDimensiune() const { return dimensiune; }
    void setDimensiune(double latime, double lungime) {
        dimensiune[0] = latime;
        dimensiune[1] = lungime;
    }

    // Functie statica
    static void afiseazaNumarAragazuriVandute() {
              cout << "Numar aragazuri vandute: " << numar_aragazuri_vandute <<       endl;
    }
};

int Aragaz::numar_aragazuri_vandute = 0;

// Clasa Blender
class Blender {
private:
          string model;
    double* putere;

public:
    static int numar_viteze;
    const double capacitate_maxima;

    // Constructor
    Blender(std::string mod, int nv, double capacitate, double p) : capacitate_maxima(capacitate), model(mod) {
        numar_viteze = nv;
        putere = new double;
        *putere = p;
    }

    // Constructor de copiere
    Blender(const Blender& alt) : capacitate_maxima(alt.capacitate_maxima), model(alt.model) {
        putere = new double;
        *putere = *(alt.putere);
    }

    // Destructor
    ~Blender() {
        delete putere;
    }

    // Get-eri și Set-eri
          string getModel() const { return model; }
    void setModel(const       string& val) { model = val; }

    double getPutere() const { return *putere; }
    void setPutere(double val) { *putere = val; }

    static void afiseazaNumarViteze() {
              cout << "Numar viteze: " << numar_viteze <<       endl;
    }

    friend void functieGlobala1(Aragaz& aragaz, Blender& blender);
    friend void functieGlobala2(Blender& blender, BalansoarBucatarie& balansoar);
};

int Blender::numar_viteze = 0;

// Clasa BalansoarBucatarie
class BalansoarBucatarie {
private:
          string culoare;
    double* latime;

public:
    static bool estePliabil;
    const double inaltime_maxima;

    // Constructor
    BalansoarBucatarie(std::string c, bool pliabil, double inaltime, double l) : inaltime_maxima(inaltime), culoare(c) {
        estePliabil = pliabil;
        latime = new double;
        *latime = l;
    }

    // Constructor de copiere
    BalansoarBucatarie(const BalansoarBucatarie& alt) : inaltime_maxima(alt.inaltime_maxima), culoare(alt.culoare) {
        latime = new double;
        *latime = *(alt.latime);
    }

    // Destructor
    ~BalansoarBucatarie() {
        delete latime;
    }

    // Get-eri și Set-eri
          string getCuloare() const { return culoare; }
    void setCuloare(const       string& val) { culoare = val; }

    double getLatime() const { return *latime; }
    void setLatime(double val) { *latime = val; }

    static void afiseazaPliabil() {
              cout << "Este pliabil: " << (estePliabil ? "Da" : "Nu") <<       endl;
    }

    friend void functieGlobala2(Blender& blender, BalansoarBucatarie& balansoar);
};

bool BalansoarBucatarie::estePliabil = false;

// Implementarea funcțiilor globale
void functieGlobala1(Aragaz& aragaz, Blender& blender) {
    // Exemplu de procesare și acces la atribute private
    // De exemplu, putem combina informații de la aragaz și blender
          cout << "Functie Globala 1:" <<       endl;
          cout << "Aragaz marca " << aragaz.getMarca() << " are " << aragaz.getNumarArzatoare() << " arzătoare." <<       endl;
          cout << "Blender model " << blender.getModel() << " are o putere de " << blender.getPutere() << " W." <<       endl;
}

void functieGlobala2(Blender& blender, BalansoarBucatarie& balansoar) {
    // Exemplu de procesare și acces la atribute private
    // De exemplu, putem afișa detalii legate de blender și balansoar
          cout << "Functie Globala 2:" <<       endl;
          cout << "Blender model " << blender.getModel() << " are " << Blender::numar_viteze << " viteze." <<       endl;
          cout << "Balansoar de culoare " << balansoar.getCuloare() << " este " << (BalansoarBucatarie::estePliabil ? "pliabil" : "nepiabil") << "." <<       endl;
}

int main() {
    // Crearea și inițializarea obiectelor
    Aragaz aragaz1("Electrolux", 4, 60, 50);
    Aragaz aragaz2("Bosch", 5, 80, 60);
    Aragaz aragaz3("Samsung", 6, 90, 70);

    Blender blender1("Philips", 3, 1.5, 500);
    Blender blender2("Braun", 5, 2.0, 800);
    Blender blender3("Ninja", 10, 2.5, 1200);

    BalansoarBucatarie balansoar1("Rosu", true, 1.2, 0.5);
    BalansoarBucatarie balansoar2("Albastru", false, 1.5, 0.7);
    BalansoarBucatarie balansoar3("Verde", true, 1.3, 0.6);

    // Apelarea get-erilor și set-erilor
          cout << "Marca aragazului 1: " << aragaz1.getMarca() <<       endl;
    aragaz1.setMarca("LG");
          cout << "Noua marca a aragazului 1: " << aragaz1.getMarca() <<       endl;

    // Apelarea funcțiilor statice
    Aragaz::afiseazaNumarAragazuriVandute();
    Blender::afiseazaNumarViteze();
    BalansoarBucatarie::afiseazaPliabil();

    // Apelarea funcțiilor globale
    functieGlobala1(aragaz1, blender1);
    functieGlobala2(blender2, balansoar2);

    return 0;
}

FAZA III
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Aragaz {
public:
         string marca;
    int numar_arzatoare;
    // pentru simplificarea codului vom folosi un singur operator 
};

     istream& operator>>(     istream& in, Aragaz& a) {
    in >> a.marca >> a.numar_arzatoare;
    return in;
}

     ostream& operator<<(     ostream& out, const Aragaz& a) {
    out << a.marca << " " << a.numar_arzatoare;
    return out;
}

class Blender {
public:
         string model;
    int numar_viteze;
};

     istream& operator>>(     istream& in, Blender& b) {
    in >> b.model >> b.numar_viteze;
    return in;
}

     ostream& operator<<(     ostream& out, const Blender& b) {
    out << b.model << " " << b.numar_viteze;
    return out;
}

class BalansoarBucatarie {
public:
         string culoare;
    bool estePliabil;
};

     istream& operator>>(     istream& in, BalansoarBucatarie& bb) {
    in >> bb.culoare >> bb.estePliabil;
    return in;
}

     ostream& operator<<(     ostream& out, const BalansoarBucatarie& bb) {
    out << bb.culoare << " " << bb.estePliabil;
    return out;
}

int main() {
         vector<Aragaz> vectorAragazuri;
         vector<Blender> vectorBlendere;
         vector<BalansoarBucatarie> vectorBalansoare;
    int n, rows, cols;

    // Citirea și afișarea vectorului de Aragaze
         cout << "Numarul de Aragaze: ";
         cin >> n;
    vectorAragazuri.resize(n);
    for (int i = 0; i < n; ++i) {
             cin >> vectorAragazuri[i];
    }
    for (const auto& aragaz : vectorAragazuri) {
             cout << aragaz <<      endl;
    }

    // Citirea și afișarea vectorului de Blendere
         cout << "Numarul de Blendere: ";
         cin >> n;
    vectorBlendere.resize(n);
    for (int i = 0; i < n; ++i) {
             cin >> vectorBlendere[i];
    }
    for (const auto& Blender : vectorBlendere) {
             cout << Blender <<      endl;
    }

    // Citirea și afișarea vectorului de Balansoare
         cout << "Numarul de Balansoare: ";
         cin >> n;
    vectorBalansoare.resize(n);
    for (int i = 0; i < n; ++i) {
             cin >> vectorBalansoare[i];
    }
    for (const auto& BalansoarBucatarie : vectorBalansoare) {
             cout << BalansoarBucatarie <<      endl;
    }

    // Crearea și utilizarea unei matrice de Blendere
         cout << "Dimensiunea matricei de Blendere (randuri si coloane): ";
         cin >> rows >> cols;
         vector<     vector<Blender>> matriceBlendere(rows,      vector<Blender>(cols));

    // Citirea și afișarea matricei de Blendere
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
                 cin >> matriceBlendere[i][j];
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
                 cout << matriceBlendere[i][j] << " ";
        }
             cout <<      endl;
    }

    return 0;
}

FAZA IV
#include <iostream>
#include <string>
using namespace std;

// Declarații prealabile
class Blender;
class BalansoarBucatarie;

class Aragaz {
private:
        string marca;
    int numar_arzatoare;
    double* dimensiune;

public:
    static int numar_aragazuri_vandute;
    const int an_fabricatie = 2020;

    Aragaz(    string m = "", int n = 0, double latime = 0, double lungime = 0) : marca(m), numar_arzatoare(n) {
        dimensiune = new double[2] {latime, lungime};
        numar_aragazuri_vandute++;
    }

    ~Aragaz() {
        delete[] dimensiune;
    }

    Aragaz& operator=(const Aragaz& alt);
    Aragaz operator+(const Aragaz& alt) const;
    bool operator==(const Aragaz& alt) const;
    Aragaz& operator++();
    int getNumarArzatoare() const { return numar_arzatoare; }

    friend bool comparaBlenderAragaz(const Blender& blender, const Aragaz& aragaz);
};

int Aragaz::numar_aragazuri_vandute = 0;

// Implementarea operatorilor pentru Aragaz

class Blender {
private:
        string model;
    double* putere;

public:
    static int numar_viteze;
    const double capacitate_maxima;

    Blender(    string mod = "", int nv = 0, double capacitate = 0, double p = 0) : model(mod), capacitate_maxima(capacitate) {
        numar_viteze = nv;
        putere = new double(p);
    }

    ~Blender() {
        delete putere;
    }

    Blender& operator=(const Blender& alt);
    Blender operator-(double val) const;
    bool operator!=(const Blender& alt) const;
    Blender operator--(int);
    double getPutere() const { return *putere; }

    friend bool comparaBlenderAragaz(const Blender& blender, const Aragaz& aragaz);
};

int Blender::numar_viteze = 0;

// Implementarea operatorilor pentru Blender

class BalansoarBucatarie {
private:
        string culoare;
    double* latime;

public:
    static bool estePliabil;
    const double inaltime_maxima;

    BalansoarBucatarie(    string c = "", bool pliabil = false, double inaltime = 0, double l = 0) : culoare(c), inaltime_maxima(inaltime) {
        estePliabil = pliabil;
        latime = new double(l);
    }

    ~BalansoarBucatarie() {
        delete latime;
    }

    BalansoarBucatarie& operator=(const BalansoarBucatarie& alt);
    BalansoarBucatarie operator*(double factor) const;
    bool operator<(const BalansoarBucatarie& alt) const;
    bool operator!() const;
    double getLatime() const { return *latime; }
};

bool BalansoarBucatarie::estePliabil = false;

// Implementarea operatorilor pentru BalansoarBucatarie

bool comparaBlenderAragaz(const Blender& blender, const Aragaz& aragaz) {
    return blender.getPutere() > aragaz.getNumarArzatoare();
}

int main() {
    // Crearea obiectelor
    Aragaz aragaz1("Electrolux", 4, 60, 50), aragaz2("Bosch", 5, 80, 60), aragaz3;
    Blender blender1("Philips", 3, 1.5, 500), blender2("Braun", 5, 2.0, 800), blender3;
    BalansoarBucatarie balansoar1("Rosu", true, 1.2, 0.5), balansoar2("Albastru", false, 1.5, 0.7), balansoar3;

    // Testarea operatorilor de atribuire
    aragaz3 = aragaz1;
    blender3 = blender2;
    balansoar3 = balansoar1;

    // Testarea altor operatori supraincarcati
    // Aragaz
    Aragaz aragazTotal = aragaz1 + aragaz2; // Operatorul +
    bool suntEgale = (aragaz1 == aragaz2); // Operatorul ==
    ++aragaz1; // Operatorul ++ (prefixat)

    // Blender
    Blender blenderReduced = blender1 - 100; // Operatorul -
    bool suntDiferite = (blender1 != blender2); // Operatorul !=
    blender2--; // Operatorul -- (postfixat)

    // BalansoarBucatarie
    BalansoarBucatarie balansoarMarit = balansoar1 * 1.5; // Operatorul *
    bool esteMaiMic = (balansoar1 < balansoar2); // Operatorul <
    bool nuEstePliabil = !balansoar1; // Operatorul !

    // Testarea funcției prietene
    bool comparaRezultat = comparaBlenderAragaz(blender1, aragaz1);

    // Afisarea rezultatelor (optional, pentru verificare)
        cout << "Aragaz total numar arzatoare: " << aragazTotal.getNumarArzatoare() <<     endl;
        cout << "Aragaze egale: " << (suntEgale ? "Da" : "Nu") <<     endl;
        cout << "Blender redus putere: " << blenderReduced.getPutere() <<     endl;
        cout << "Blender-e diferiteite: " << (suntDiferite ? "Da" : "Nu") <<     endl;
        cout << "Balansoar marit latime: " << balansoarMarit.getLatime() <<     endl;
        cout << "Balansoar1 este mai mic decat Balansoar2: " << (esteMaiMic ? "Da" : "Nu") <<     endl;
        cout << "Balansoar1 nu este pliabil: " << (nuEstePliabil ? "Da" : "Nu") <<     endl;
        cout << "Puterea blenderului este mai mare decat numarul de arzatoare al aragazului: " << (comparaRezultat ? "Da" : "Nu") <<     endl;

    return 0;
}

FAZA V
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Aragaz {
public:
      string marca;
    int numar_arzatoare;
    // Constructor
    Aragaz(  string m, int n) : marca(m), numar_arzatoare(n) {}
};


  ostream& operator<<(  ostream& out, const Aragaz& a) {
    out << a.marca << " cu " << a.numar_arzatoare << " arzatoare";
    return out;
}

  istream& operator>>(  istream& in, Aragaz& a) {
    in >> a.marca >> a.numar_arzatoare;
    return in;
}

class Blender {
public:
      string model;
    int numar_viteze;
    // Constructor
    Blender(  string mod, int nv) : model(mod), numar_viteze(nv) {}
};

  ostream& operator<<(  ostream& out, const Blender& b) {
    out << b.model << " cu " << b.numar_viteze << " viteze";
    return out;
}

  istream& operator>>(  istream& in, Blender& b) {
    in >> b.model >> b.numar_viteze;
    return in;
}

class BalansoarBucatarie {
public:
      string culoare;
    bool estePliabil;
    // Constructori, metode, etc.
};

  ostream& operator<<(  ostream& out, const BalansoarBucatarie& bb) {
    out << "Balansoar " << bb.culoare << " pliabil: " << (bb.estePliabil ? "Da" : "Nu");
    return out;
}

  istream& operator>>(  istream& in, BalansoarBucatarie& bb) {
    in >> bb.culoare >> bb.estePliabil;
    return in;
}

class BucatarieModerna {
private:
      string numeBucatarie;
    Blender blenderPrincipal;
      vector<Aragaz> aragazuri;

public:
    BucatarieModerna(  string nume, const Blender& blender) : numeBucatarie(nume), blenderPrincipal(blender) {}

    // Getteri si setteri
      string getNumeBucatarie() const { return numeBucatarie; }
    void setNumeBucatarie(const   string& nume) { numeBucatarie = nume; }

    Blender getBlenderPrincipal() const { return blenderPrincipal; }
    void setBlenderPrincipal(const Blender& blender) { blenderPrincipal = blender; }

      vector<Aragaz> getAragazuri() const { return aragazuri; }
    void setAragazuri(const   vector<Aragaz>& aragazuriNoi) { aragazuri = aragazuriNoi; }

    // Supraincarcarea operatorilor
    friend   ostream& operator<<(  ostream& out, const BucatarieModerna& bm);
    friend   istream& operator>>(  istream& in, BucatarieModerna& bm);
    BucatarieModerna& operator+=(const Aragaz& aragaz);
};

  ostream& operator<<(  ostream& out, const BucatarieModerna& bm) {
    out << "Bucatarie Moderna: " << bm.numeBucatarie << ", Blender Principal: " << bm.blenderPrincipal;
    // Afisare aragazuri, daca exista
    for (const auto& aragaz : bm.aragazuri) {
        out << "\n" << aragaz;
    }
    return out;
}

  istream& operator>>(  istream& in, BucatarieModerna& bm) {
    in >> bm.numeBucatarie >> bm.blenderPrincipal;
    // Citire aragazuri, daca este necesar
    return in;
}

BucatarieModerna& BucatarieModerna::operator+=(const Aragaz& aragaz) {
    aragazuri.push_back(aragaz);
    return *this;
}

int main() {
    Blender blender1("Philips", 5);
    Aragaz aragaz1("Electrolux", 4);
    Aragaz aragaz2("Bosch", 6);

    BucatarieModerna bucatarie("Bucataria Vesela", blender1);
    bucatarie += aragaz1; // Adaugarea unui aragaz în bucătărie
    bucatarie += aragaz2; // Adăugare alt aragaz

      cout << bucatarie <<   endl;

    return 0;
}

FAZA VI
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Aragaz {
public:
    string marca;
    int numar_arzatoare;

    Aragaz() : marca(""), numar_arzatoare(0) {}
    Aragaz(string m, int n) : marca(m), numar_arzatoare(n) {}

    friend  ofstream& operator<<( ofstream& ofs, const Aragaz& aragaz);
    friend  ifstream& operator>>( ifstream& ifs, Aragaz& aragaz);
};

 ofstream& operator<<( ofstream& ofs, const Aragaz& aragaz) {
    ofs << aragaz.marca << " " << aragaz.numar_arzatoare << "\n";
    return ofs;
}

 ifstream& operator>>( ifstream& ifs, Aragaz& aragaz) {
    ifs >> aragaz.marca >> aragaz.numar_arzatoare;
    return ifs;
}

class Blender {
public:
     string model;
    int numar_viteze;

    Blender() : model(""), numar_viteze(0) {}
    Blender( string m, int n) : model(m), numar_viteze(n) {}

    friend  ofstream& operator<<( ofstream& ofs, const Blender& blender);
    friend  ifstream& operator>>( ifstream& ifs, Blender& blender);
};

 ofstream& operator<<( ofstream& ofs, const Blender& blender) {
    ofs << blender.model << " " << blender.numar_viteze << "\n";
    return ofs;
}

 ifstream& operator>>( ifstream& ifs, Blender& blender) {
    ifs >> blender.model >> blender.numar_viteze;
    return ifs;
}

class BalansoarBucatarie {
public:
     string culoare;
    bool estePliabil;

    BalansoarBucatarie() : culoare(""), estePliabil(false) {}
    BalansoarBucatarie( string c, bool p) : culoare(c), estePliabil(p) {}

    void scrieInFisierBin( ofstream& ofs) const {
        ofs.write((char*)&estePliabil, sizeof(estePliabil));
        size_t len = culoare.length();
        ofs.write((char*)&len, sizeof(len));
        ofs.write(culoare.c_str(), len);
    }

    void citesteDinFisierBin( ifstream& ifs) {
        ifs.read((char*)&estePliabil, sizeof(estePliabil));
        size_t len;
        ifs.read((char*)&len, sizeof(len));
        culoare.resize(len);
        ifs.read(&culoare[0], len);
    }
};

class BucatarieModerna {
private:
     string numeBucatarie;
    Blender blenderPrincipal;

public:
    BucatarieModerna( string nume, const Blender& blender) : numeBucatarie(nume), blenderPrincipal(blender) {}

    void scrieInFisierBin( ofstream& ofs) const {
        size_t len = numeBucatarie.length();
        ofs.write((char*)&len, sizeof(len));
        ofs.write(numeBucatarie.c_str(), len);
    }

    void citesteDinFisierBin( ifstream& ifs) {
        size_t len;
        ifs.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
        ifs.read(buffer,
            len);
        buffer[len] = '\0';
        numeBucatarie = buffer;
        delete[] buffer;
    }
};

int main() {
    // Exemplu de utilizare pentru fișiere text
    Aragaz aragaz1("Samsung", 4);
     ofstream fisierTextOutAragaz("aragaz.txt");
    fisierTextOutAragaz << aragaz1;
    fisierTextOutAragaz.close();


    Aragaz aragaz2;
     ifstream fisierTextInAragaz("aragaz.txt");
    fisierTextInAragaz >> aragaz2;
    fisierTextInAragaz.close();
     cout << "Aragaz citit din fisier text: " << aragaz2.marca << ", " << aragaz2.numar_arzatoare << " arzatoare" <<  endl;

    // Exemplu de utilizare pentru fișiere binare
    BalansoarBucatarie balansoar1("Rosu", true);
     ofstream fisierBinOutBalansoar("balansoar.bin",  ios::binary);
    balansoar1.scrieInFisierBin(fisierBinOutBalansoar);
    fisierBinOutBalansoar.close();

    BalansoarBucatarie balansoar2;
     ifstream fisierBinInBalansoar("balansoar.bin",  ios::binary);
    balansoar2.citesteDinFisierBin(fisierBinInBalansoar);
    fisierBinInBalansoar.close();
     cout << "Balansoar citit din fisier binar: " << balansoar2.culoare << ", pliabil: " << (balansoar2.estePliabil ? "Da" : "Nu") <<  endl;

    return 0;
}

FAZA VII
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Aragaz {
public:
    string marca;
    int numar_arzatoare;

    Aragaz(string m = "", int n = 0) : marca(m), numar_arzatoare(n) {}
};

class Blender {
public:
    string model;
    int numar_viteze;
    double capacitate_maxima;
    double putere;

    Blender(string mod = "", int nv = 0, double capacitate = 0, double p = 0)
        : model(mod), numar_viteze(nv), capacitate_maxima(capacitate), putere(p) {}
};

class AragazDigital : public Aragaz {
public:
    bool areEcranTouch;

    AragazDigital(string m = "", int n = 0, bool ecran = false) : Aragaz(m, n), areEcranTouch(ecran) {}
};

ofstream& operator<<(ofstream& ofs, const AragazDigital& aragaz) {
    ofs << aragaz.marca << " " << aragaz.numar_arzatoare << " " << aragaz.areEcranTouch << "\n";
    return ofs;
}

ifstream& operator>>(ifstream& ifs, AragazDigital& aragaz) {
    ifs >> aragaz.marca >> aragaz.numar_arzatoare >> aragaz.areEcranTouch;
    return ifs;
}

class BlenderInteligent : public Blender {
public:
    string tipControl;

    BlenderInteligentstring mod = "", int nv = 0, double capacitate = 0, double p = 0, string control = "")
        : Blender(mod, nv, capacitate, p), tipControl(control) {}

    void scrieInFisierBin(ofstream& ofs) const {
        ofs.write((char*)&numar_viteze, sizeof(numar_viteze));
        size_t len = tipControl.length();
        ofs.write((char*)&len, sizeof(len));
        ofs.write(tipControl.c_str(), len);
    }

    void citesteDinFisierBin(ifstream& ifs) {
        ifs.read((char*)&numar_viteze, sizeof(numar_viteze));
        size_t len;
        ifs.read((char*)&len, sizeof(len));
        tipControl.resize(len);
        ifs.read(&tipControl[0], len);
    }
};

int main() {
    // Exemplu de utilizare pentru fișiere text cu AragazDigital
    AragazDigital aragazDigital1("Samsung", 4, true);
    ofstream fisierTextOutAragaz("aragaz_digital.txt");
    fisierTextOutAragaz << aragazDigital1;
    fisierTextOutAragaz.close();

    AragazDigital aragazDigital2;
    ifstream fisierTextInAragaz("aragaz_digital.txt");
    fisierTextInAragaz >> aragazDigital2;
    fisierTextInAragaz.close();

    cout << "Aragaz Digital citit din fisier text: " << aragazDigital2.marca << ", "
        << aragazDigital2.numar_arzatoare << " arzatoare, Ecran touch: "
        << (aragazDigital2.areEcranTouch ? "Da" : "Nu") << endl;

    // Exemplu de utilizare pentru fișiere binare cu BlenderInteligent
    BlenderInteligent blenderInteligent1("Philips", 5, 2.0, 800, "Touch");
    ofstream fisierBinOutBlender("blender_inteligent.bin", ios::binary);
    blenderInteligent1.scrieInFisierBin(fisierBinOutBlender);
    fisierBinOutBlender.close();

    BlenderInteligent blenderInteligent2;
    ifstream fisierBinInBlender("blender_inteligent.bin",ios::binary);
    blenderInteligent2.citesteDinFisierBin(fisierBinInBlender);
    fisierBinInBlender.close();

    cout << "Blender Inteligent citit din fisier binar: " << blenderInteligent2.tipControl
        << ", " << blenderInteligent2.numar_viteze << " viteze" << endl;

    return 0;
}

FAZA VIII
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Clase abstracte
class AparatDeBucatarie {
public:
    virtual void afisare() const = 0;
    virtual ~AparatDeBucatarie() {}
};

class MobilierDeBucatarie {
public:
    virtual void afisare() const = 0;
    virtual ~MobilierDeBucatarie() {}
};

// Clase concrete
class Blender : public AparatDeBucatarie {
public:
    void afisare() const override {
       cout << "Blender afisat.\n";
    }
};

class Aragaz : public AparatDeBucatarie {
public:
    void afisare() const override {
        cout << "Aragaz afisat.\n";
    }
};

class BalansoarBucatarie : public MobilierDeBucatarie {
public:
    void afisare() const override {
        cout << "Balansoar de Bucatarie afisat.\n";
    }
};

// Clasa care include relații de tip "has-a" cu tipuri abstracte
class Bucatarie {
private:
   vector<unique_ptr<AparatDeBucatarie>> aparate;
   vector<unique_ptr<MobilierDeBucatarie>> mobiliere;

public:
    void adaugaAparat(unique_ptr<AparatDeBucatarie> aparat) {
        aparate.push_back(move(aparat));
    }

    void adaugaMobilierunique_ptr<MobilierDeBucatarie> mobilier) {
        mobiliere.push_back(move(mobilier));
    }

    void afisare() const {
        cout << "Bucataria contine:\n";
        for (const auto& aparat : aparate) {
            aparat->afisare();
        }
        for (const auto& mobilier : mobiliere) {
            mobilier->afisare();
        }
    }
};

int main() {
    Bucatarie bucatariaMea;

    // Crearea și adăugarea aparatelor de bucătărie
    bucatariaMea.adaugaAparat(make_unique<Blender>());
    bucatariaMea.adaugaAparat(make_unique<Aragaz>());

    // Crearea și adăugarea mobilierului de bucătărie
    bucatariaMea.adaugaMobilier(make_unique<BalansoarBucatarie>());

    // Afisarea tuturor elementelor din bucătarie
    bucatariaMea.afisare();

    return 0;
}
