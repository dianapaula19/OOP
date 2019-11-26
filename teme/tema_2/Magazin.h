#include <vector>
#ifndef MAGAZIN_H_INCLUDED
#define MAGAZIN_H_INCLUDED
class Produs {

protected:
    int aCantitate;
    int aCod;
    double aPretPerUnit;
    double aCost;
    std::string aUnit;
public:
    Produs();
    Produs(int, int, double, std::string);
    Produs(const Produs&);
    ~Produs();
    int getCantitate() {
        return aCantitate;
    }
    int getCod() {
        return aCod;
    }
    double getPretPerUnit() {
        return aPretPerUnit;
    }
    double getCost() {
        return aCost;
    }
    void setCantitate(int a){
        aCantitate = a;
    }
    void setPretPerUnit(double a) {
        aPretPerUnit = a;
    }
    void setCost(double a) {
        aCost = a;
    }
    virtual void Read() {
    };
    virtual void Print() const {
    };
    virtual void ReadClient() {
        // aici citesc numai ce vrea clientul, restul atributelor raman initializate cu 0 sau cu ""
    };
    Produs& operator = (const Produs&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);

};

class Varza : public Produs {
public:
    Varza() : Produs() {
        aUnit = "buc";
        aCod = 1;
    };
    Varza(int cCantitate, double cPretPerUnit) : Produs(cCantitate, 1, cPretPerUnit, "buc"){
    };
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
    }
    void Print() const {
        std::cout << "varza\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
    }
    bool operator == (const Varza&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);

};
class Faina : public Produs {

private:
    std::string aCalitate;
public:
    Faina() : Produs() {
        aCalitate = "";
        aCod = 2;
        aUnit = "kg";
    };
    Faina(std::string cCalitate, int cCantitate, double cPretPerUnit) : Produs(cCantitate, 2, cPretPerUnit, "kg"){
        aCalitate = cCalitate;
    };
    std::string getCalitate() {
        return aCalitate;
    }
    void setCalitate(std::string a) {
        aCalitate = a;
    }
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
        std::cout << "Calitatea: ";
        std::cin >> aCalitate;
    }
    void Print() const {
        std::cout << "faina\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
        std::cout <<"Calitatea este: " << aCalitate << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
        std::cout << "Mentionati calitatea?\n";
        std::string raspuns;
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::cin >> aCalitate;
        }
    };
    Faina& operator = (const Faina&);
    bool operator == (const Faina&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);

};
class Bere : public Produs {

private:
    std::string aBrand;
    std::string aTip;
public:
    Bere() : Produs() {
        aBrand = "";
        aTip = "";
        aCod = 3;
        aUnit = "buc";
    }
    Bere(std::string cBrand, std::string cTip, int cCantitate, double cPretPerUnit) : Produs(cCantitate, 3, cPretPerUnit, "buc") {
        aBrand = cBrand;
        aTip = cTip;
    }
    std::string getBrand() {
        return aBrand;
    }
    std::string getTip() {
        return aTip;
    }
    void setBrand(std::string a) {
        aBrand = a;
    }
    void setTip(std::string a) {
        aTip = a;
    }
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
        std::cout << "Brandul: ";
        std::cin >> aBrand;
        std::cout << "Tipul: ";
        std::cin >> aTip;
    }
    void Print() const {
        std::cout << "bere\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
        std::cout << "Brandul este: " << aBrand << "\n";
        std::cout << "Tipul este: " << aTip << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
        std::cout << "Mentionati brandul?\n";
        std::string raspuns;
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::cin >> aBrand;
        }
        std::cout << "Mentionati tipul?\n";
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::cin >> aTip;
        }
    }
    Bere& operator = (const Bere&);
    bool operator == (const Bere&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);
};
class VinVarsat : public Produs {

private:
    std::string aTip;
public:
    VinVarsat() : Produs() {
        aTip = "";
        aCod = 4;
        aUnit = "l";
    };
    VinVarsat(std::string cTip, int cCantitate, double cPretPerUnit) : Produs(cCantitate, 4, cPretPerUnit, "l") {
        aTip = cTip;
    }
    std::string getTip() {
        return aTip;
    }
    void setTip(std::string a) {
        aTip = a;
    }
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
        std::cout << "Tipul: ";
        std::getline(std::cin >> std::ws, aTip);
    }
    void Print() const {
        std::cout << "vin varsat\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
        std::cout << "Tipul este: " << aTip << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
        std::cout << "Mentionati tipul?\n";
        std::string raspuns;
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::getline(std::cin >> std::ws, aTip);
        }
    }
    VinVarsat& operator = (const VinVarsat&);
    bool operator == (const VinVarsat&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);

};
class VinDeSoi : public Produs {

private:
    std::string aSoi;
    int aAn;
    std::string aTara;
public:
    VinDeSoi() : Produs() {
        aSoi = "";
        aAn = 0;
        aTara = "";
        aCod = 5;
        aUnit = "buc";
    };
    VinDeSoi(std::string cSoi, int cAn, std::string cTara, int cCantitate, double cPretPerUnit) : Produs(cCantitate, 5, cPretPerUnit, "buc") {
        aSoi = cSoi;
        aAn = cAn;
        aTara = cTara;
    }
    std::string getSoi() {
        return aSoi;
    }
    int getAn() {
        return aAn;
    }
    std::string getTara() {
        return aTara;
    }
    void setSoi(std::string a) {
        aSoi = a;
    }
    void setAn(int a) {
        aAn = a;
    }
    void setTara(std::string a) {
        aTara = a;
    }
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
        std::cout << "Soiul: ";
        std::getline(std::cin >> std::ws, aSoi);
        std::cout << "Anul: ";
        std::cin >> aAn;
        std::cout << "Tara: ";
        std::cin >> aTara;
    }
    void Print() const {
        std::cout << "vin de soi\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
        std::cout << "Soiul este: " << aSoi << "\n";
        std::cout << "Anul este: " << aAn << "\n";
        std::cout << "Tara de origine este: " << aTara << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
        std::cout << "Mentionati soiul?\n";
        std::string raspuns;
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::getline(std::cin >> std::ws, aSoi);
        }
        std::cout << "Mentionati anul?\n";
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::cin >> aAn;
        }
        std::cout << "Mentionati tara?\n";
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::cin >> aTara;
        }
    }
    VinDeSoi& operator = (const VinDeSoi&);
    bool operator == (const VinDeSoi&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);
};
class Cartofi : public Produs{

private:
    std::string aTip;
public:
    Cartofi() : Produs(){
        aTip = "";
        aCod = 6;
        aUnit = "kg";
    };
    Cartofi(std::string cTip, int cCantitate, double cPretPerUnit) : Produs(cCantitate, 6, cPretPerUnit, "kg") {
        aTip = cTip;
    }
    std::string getTip() {
        return aTip;
    }
    void setTip(std::string a) {
        aTip = a;
    }
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
        std::cout << "Tipul: ";
        std::cin >> aTip;
    }
    void Print() const {
        std::cout << "cartofi\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
        std::cout << "Tipul este: " << aTip << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
        std::cout << "Mentionati tipul?\n";
        std::string raspuns;
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::cin >> aTip;
        }
    }
    Cartofi& operator = (const Cartofi&);
    bool operator == (const Cartofi&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);

};

class Jucarie : public Produs {

private:
    std::string aDenumire;
public:
    Jucarie() : Produs(){
        aDenumire = "";
        aCod = 7;
    };
    Jucarie(std::string cDenumire, int cCantitate, double cPretPerUnit) : Produs(cCantitate, 7, cPretPerUnit, "buc") {
        aDenumire = cDenumire;
    }
    std::string getDenumire() {
        return aDenumire;
    }
    void setDenumire(std::string a) {
        aDenumire = a;
    }
    void Read() {
        std::cout << "Pretul per unitate: ";
        std::cin >> aPretPerUnit;
        std::cout << "Cantitatea: ";
        std::cin >> aCantitate;
        aCost = aPretPerUnit * aCantitate;
        std::cout << "Denumirea: ";
        std::getline(std::cin >> std::ws, aDenumire);
    }
    void Print() const {
        std::cout << "jucarie\n";
        std::cout << "Pretul per unitate este: " << aPretPerUnit << "\n";
        std::cout << "Cantitatea este: " << aCantitate << "\n";
        std::cout << "Costul este: " << aCost << "\n";
        std::cout << "Denumirea este: " << aDenumire << "\n";
    }
    void ReadClient() {
        std::cout << "Cantitatea dorita: ";
        std::cin >> aCantitate;
        std::cout << "Mentionati denumirea?\n";
        std::string raspuns;
        std::cin >> raspuns;
        if(raspuns == "da") {
            std::getline(std::cin >> std::ws, aDenumire);
        }
    }
    Jucarie& operator = (const Jucarie&);
    bool operator == (const Jucarie&);
    friend std::istream& operator >> (std::istream&, Produs&);
    friend std::ostream& operator << (std::ostream&, const Produs&);

};
class Magazin {
private:
    std::vector <Produs*> stoc;
    int aStoc;
    int aProduseVandute;
    double aTotal;
public:
    int getProduseVandute() {
        return aProduseVandute;
    }
    double getTotal() {
        return aTotal;
    }
    void ActualizareStoc();
    void AfisareStoc();
    void ReadListaClient();
    void ZiDeLucru();
    static void AfisareOptiuni();
    static int GoodVinDeSoi(VinDeSoi&, VinDeSoi&);
    void CautProdus(Produs&, int, int);
    Magazin();
    ~Magazin();

};
#endif // MAGAZIN_H_INCLUDED
