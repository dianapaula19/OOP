#ifndef APARTAMENT_H
#define APARTAMENT_H

#include <Locuinta.h>


class Apartament : public Locuinta {

    int etaj;
public:
    Apartament() : etaj(0) {}
    Apartament(Apartament&);
    ~Apartament();
    Apartament& operator = (Apartament&);
    double calculChirie() const;
    void citire(std::istream&);
    void afisare();

};

#endif // APARTAMENT_H
