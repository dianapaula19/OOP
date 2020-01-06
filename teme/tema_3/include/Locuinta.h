#ifndef LOCUINTA_H
#define LOCUINTA_H
#include <string>

class Locuinta {

protected:
    std::string numeClient;
    double pret;
    int suprafata;
    int discount;
public:
    Locuinta() : numeClient(""), pret(0), suprafata(0), discount(0) {}
    Locuinta(Locuinta&);
    virtual ~Locuinta() = 0;
    virtual double calculChirie() const = 0;
    virtual void citire(std::istream&) = 0;
    virtual void afisare() = 0;
    Locuinta& operator = (Locuinta&);
    friend std::istream& operator >> (std::istream&, Locuinta&);
    friend std::ostream& operator << (std::ostream&, Locuinta&);

};

#endif // LOCUINTA_H
