#include "Apartament.h"
#include <iostream>
#include <typeinfo>

Apartament::~Apartament() {

    std::cout << "Destructor pentru Apartament\n";

}

Apartament::Apartament(Apartament& a) {

    numeClient = a.numeClient;
    pret = a.pret;
    suprafata = a.suprafata;
    discount = a.discount;
    etaj = a.etaj;

}
Apartament& Apartament::operator = (Apartament& a) {

    if (this == &a) {
        return (*this);
    }
    numeClient = a.numeClient;
    pret = a.pret;
    suprafata = a.suprafata;
    discount = a.discount;
    etaj = a.etaj;
    return (*this);
}
double Apartament::calculChirie() const {

    double chirie = 0;
    chirie = suprafata * pret;
    if (discount != 0) {
        chirie = chirie - chirie * (discount * 0.01);
    }
    return chirie;

}

void Apartament::citire(std::istream& in) {

        std::cout << "Numele Clientului este: ";
        std::getline(in >> std::ws, numeClient);
        try {
            std::cout << "Pretul per metru patrat: ";
            in >> pret;
            if (pret < 0) {
                throw 1;
            }
        } catch(int x) {
            std::cout << "Pretul trebuie sa fie un numar pozitiv\n";
        }
        try {
        std::cout << "Suprafata totala: ";
        in >> suprafata;
        if (typeid(suprafata) != typeid(int) || suprafata < 0) {
            throw 2;
        }
        } catch(int x) {
            std::cout << "Suprafata trebuie sa fie un numar intreg si pozitiv\n";
        }
        try {
        std::cout << "Discountul: ";
        in >> discount;
        if (discount < 0 || discount > 10 || typeid(discount) != typeid(int)) {
            throw 3;
        }
        } catch(int x) {
            std::cout << "Discountul trebuie sa fie intre 0 si 10 si sa fie un numar intreg\n";
        }
        try {
        std::cout << "Etajul: ";
        in >> etaj;
        if (etaj < 0 || typeid(etaj) != typeid(int)) {
            throw 4;

        }
        } catch(int x) {
            std::cout << "Etajul trebuie sa fie un numar intreg si pozitiv";
        }

}

void Apartament::afisare() {

    std::cout << "numeClient = " << numeClient << "\n";
    std::cout << "pret = " << pret << "\n";
    std::cout << "suprafata = " << suprafata << "\n";
    std::cout << "discount = " << discount << "\n";
    std::cout << "etaj = " << etaj << "\n";

}
