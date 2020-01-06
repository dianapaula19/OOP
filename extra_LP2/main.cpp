#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Farmacie_abstracta {
protected:
    string denumire;
public:
    Farmacie_abstracta();
    Farmacie_abstracta(string);
    virtual int calcul_venit() const = 0;
    virtual void Afisare() {
        cout << denumire << "\n";
    }
    virtual void Citire() {
        cin >> denumire;
    }
    friend istream& operator >> (istream&, Farmacie_abstracta&);
    friend ostream& operator << (ostream&, Farmacie_abstracta&);
};
class Farmacie_offline : public Farmacie_abstracta {
protected:
    int nr_luni;
    vector <double> cifra_afaceri_luna;
public:
    Farmacie_offline() : Farmacie_abstracta() {
        nr_luni = 0;

    }
    Farmacie_offline(int nr_luni_, vector <double> cifra_afaceri_luna_, string denumire_) : Farmacie_abstracta(denumire_) {
        nr_luni = nr_luni_;
        cifra_afaceri_luna.swap(cifra_afaceri_luna_);

    }
    Farmacie_offline(Farmacie_offline& f) {
        denumire = f.denumire;
        nr_luni = f.nr_luni;
        cifra_afaceri_luna.swap(f.cifra_afaceri_luna);

    }
    void Afisare() {
        cout << denumire << "\n";
        cout << nr_luni << "\n";
        for(int i = 0; i < nr_luni; ++i) {
            int luna = i % 12;
            switch(luna) {
            case 0: {
                cout << "ianuarie" << cifra_afaceri_luna[i] << "\n";
            }
            case 1: {
                cout << "februarie" << cifra_afaceri_luna[i] << "\n";
            }
            case 2: {
                cout << "martie" << cifra_afaceri_luna[i] << "\n";
            }
            case 3: {
                cout << "aprilie" << cifra_afaceri_luna[i] << "\n";
            }
            case 4: {
                cout << "mai" << cifra_afaceri_luna[i] << "\n";
            }
            case 5: {
                cout << "iunie" << cifra_afaceri_luna[i] << "\n";
            }
            case 6: {
                cout << "iulie" << cifra_afaceri_luna[i] << "\n";
            }
            case 7: {
                cout << "august" << cifra_afaceri_luna[i] << "\n";
            }
            case 8: {
                cout << "septembrie" << cifra_afaceri_luna[i] << "\n";
            }
            case 9: {
                cout << "octombrie" << cifra_afaceri_luna[i] << "\n";
            }
            case 10: {
                cout << "noiembrie" << cifra_afaceri_luna[i] << "\n";
            }
            case 11: {
                cout << "decembrie" << cifra_afaceri_luna[i] << "\n";
            }

            }
        }
    }
    void Citire() {
        cin >> denumire;
        cin >> nr_luni;
        for(int i = 0; i < nr_luni; ++i) {
            int cifra;
            cin >> cifra;
            cifra_afaceri_luna.push_back(cifra);
        }
    }
    int calcul_venit() const {
        int venit_offline = 0;
        for(int i = 0; i < nr_luni; ++i) {
            venit_offline += cifra_afaceri_luna[i];
        }
        return venit_offline;
    }
    Farmacie_offline& operator = (Farmacie_offline&);
    friend istream& operator >> (istream&, Farmacie_abstracta&);
    friend ostream& operator << (ostream&, Farmacie_abstracta&);
};

class Farmacie_online : public Farmacie_abstracta {

protected:
   string adresa_web;
   int nr_vizitatori;
   const float medie = 123;
   public:
       Farmacie_online() : Farmacie_abstracta() {
        nr_vizitatori = 0;
        adresa_web = "";
       }
       Farmacie_online(string adresa_web_, int nr_vizitatori_, string denumire) {
        adresa_web = adresa_web_;
        nr_vizitatori = nr_vizitatori_;
       }
       Farmacie_online(Farmacie_online& f) {
            adresa_web = f.adresa_web;
            nr_vizitatori = f.nr_vizitatori;
            f.denumire = f.denumire;

       }
       void Afisare() {
           cout << denumire << "\n";
           cout << adresa_web << "\n";
           cout << nr_vizitatori << "\n";
       }
       void Citire() {
           cin >> denumire;
           cin >> adresa_web;
           cin >> nr_vizitatori;

       }
       int calcul_venit() const {
            int venit_online = 0;
            venit_online = nr_vizitatori * medie;
            return venit_online;
       }
       Farmacie_online& operator = (const Farmacie_online&);
       friend istream& operator >> (istream&, Farmacie_abstracta&);
       friend ostream& operator << (ostream&, const Farmacie_abstracta&);

};
class Farmacie_dubla_specializare : public Farmacie_offline, public Farmacie_online {

    int nr_angajati;
public:
    Farmacie_dubla_specializare() : Farmacie_offline(), Farmacie_online() {
        nr_angajati = 0;
    }
    Farmacie_dubla_specializare(int nr_angajati_) : Farmacie_offline(), Farmacie_online() {
        nr_angajati = nr_angajati_;
    }
    Farmacie_dubla_specializare& operator = (Farmacie_dubla_specializare&);
    Farmacie_dubla_specializare(Farmacie_dubla_specializare& f) {
        nr_angajati = f.nr_angajati;
        adresa_web = f.adresa_web;
        nr_vizitatori = f.nr_vizitatori;
        nr_luni = f.nr_luni;
        cifra_afaceri_luna.swap(f.cifra_afaceri_luna);
    }

};
Farmacie_abstracta::Farmacie_abstracta() {

    denumire = "";

}
Farmacie_abstracta::Farmacie_abstracta(string denumire_) {

    denumire = denumire_;

}
Farmacie_offline& Farmacie_offline::operator = (Farmacie_offline& f) {

    if(this == &f) {
        return *this;
    }
    denumire = f.denumire;
    nr_luni = f.nr_luni;
    cifra_afaceri_luna.swap(f.cifra_afaceri_luna);

    return *this;

}
Farmacie_online& Farmacie_online::operator = (const Farmacie_online& f) {

    if(this == &f) {
        return *this;
    }
    denumire = f.denumire;
    adresa_web = f.adresa_web;
    nr_vizitatori = f.nr_vizitatori;

    return *this;

}
Farmacie_dubla_specializare& Farmacie_dubla_specializare::operator = (Farmacie_dubla_specializare& f) {

    if(this == &f) {
        return *this;
    }
    nr_luni = f.nr_luni;
    cifra_afaceri_luna.swap(f.cifra_afaceri_luna);
    adresa_web = f.adresa_web;
    nr_vizitatori = f.nr_vizitatori;
    nr_angajati = f.nr_angajati;

    return *this;

}
istream& operator >> (istream& file, Farmacie_abstracta& f) {

    f.Citire();
    return file;
}
ostream& operator << (ostream& out, Farmacie_abstracta& f) {

    f.Afisare();
    return out;

}
int main()
{
    vector <Farmacie_abstracta*> farmacii;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int op;
        cout << "1 - offline\n";
        cout << "2 - online\n";
        cin >> op;
        switch(op) {
        case 1: {
            farmacii.push_back(new Farmacie_offline());
            cin >> (*farmacii[i]);
            break;
        }
        case 2: {
            farmacii.push_back(new Farmacie_online());
            cin >> (*farmacii[i]);
            break;
        }
        }
    }
    return 0;
}
