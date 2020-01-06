#include "Locuinta.h"
#include <iostream>

Locuinta::~Locuinta() {
    std::cout << "Destructor pentru Locuinta\n";
}
Locuinta::Locuinta(Locuinta& l) {

    numeClient = l.numeClient;
    pret = l.pret;
    suprafata = l.suprafata;
    discount = l.discount;

}
Locuinta& Locuinta::operator = (Locuinta& l) {

    if (this == &l) {
        return (*this);
    }
    numeClient = l.numeClient;
    pret = l.pret;
    suprafata = l.suprafata;
    discount = l.discount;
    return (*this);
}

std::istream& operator >> (std::istream& in, Locuinta& l) {

    l.citire(in);
    return in;

}
std::ostream& operator << (std::ostream& out, Locuinta& l) {

    l.afisare();
    return out;

}
