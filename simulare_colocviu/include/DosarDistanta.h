#ifndef DOSARDISTANTA_H
#define DOSARDISTANTA_H
#include "Dosar.h"

class DosarDistanta : public Dosar {
private:
    double notaMate;
    double notaProbaOrala;
public:
    DosarDistanta();
    DosarDistanta(const DosarDistanta&);
    DosarDistanta& operator =(const DosarDistanta&);
    void citire(std::istream&);
    void afisare();
    double mediaAdmitere();
};

#endif // DOSARDISTANTA_H
