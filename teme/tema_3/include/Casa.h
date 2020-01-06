#ifndef CASA_H
#define CASA_H

#include <Locuinta.h>
#include <vector>


class Casa : public Locuinta {

    int suprafataCurte;
    std::vector <int> suprafataEtaje;
    static int nrCase;
public:
    Casa() : suprafataCurte(0) {
        ++nrCase;
    }
    Casa(Casa&);
    ~Casa();
    Casa& operator = (Casa&);
    double calculChirie() const;
    void citire(std::istream&);
    void afisare();

};

#endif // CASA_H
