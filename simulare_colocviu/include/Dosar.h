#ifndef DOSAR_H
#define DOSAR_H
#include <string>

class Dosar {
protected:
    std::string nume;
    double mediaBac;
public:
    Dosar();
    Dosar(const Dosar&);
    Dosar& operator = (const Dosar&);
    virtual void citire(std::istream&) = 0;
    virtual void afisare() = 0;
    virtual double mediaAdmitere() = 0;
    friend std::istream& operator >> (std::istream&, Dosar&);
    friend std::ostream& operator << (std::ostream&, Dosar&);
};



#endif // DOSAR_H
