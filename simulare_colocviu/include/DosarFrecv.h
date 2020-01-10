#ifndef DOSARFRECV_H
#define DOSARFRECV_H

#include <Dosar.h>


class DosarFrecv : public Dosar {
private:
    double notaProba1;
    double notaProba2;
    double mediaProbe = (notaProba1 + notaProba2) / 2;
public:
    DosarFrecv();
    DosarFrecv(const DosarFrecv&);
    DosarFrecv& operator = (const DosarFrecv&);
    void citire(std::istream&);
    void afisare();
    double mediaAdmitere();

};

#endif // DOSARFRECV_H
