#include "Casa.h"
#include <iostream>
#include <vector>
#include <typeinfo>

int Casa::nrCase = 0;

Casa::~Casa() {

    std::cout << "Destructor pentru Casa\n";
    --nrCase;

}
Casa::Casa(Casa& c) {

    numeClient = c.numeClient;
    pret = c.pret;
    discount = c.discount;
    suprafataCurte = c.suprafataCurte;
    ++nrCase;

}
Casa& Casa::operator = (Casa& c) {

    if (this == &c) {
        return (*this);
    }
    numeClient = c.numeClient;
    pret = c.pret;
    discount = c.discount;
    suprafataCurte = c.suprafataCurte;
    suprafataEtaje = c.suprafataEtaje;

    return (*this);
}

double Casa::calculChirie() const {

    double chirie = 0;
    for(auto i : suprafataEtaje) {
        chirie += i * pret;
    }
    chirie += suprafataCurte * pret;
    if (discount != 0) {
        chirie = chirie - chirie * (discount * 0.01);
    }
    return chirie;
}

void Casa::citire(std::istream& in) {

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
        std::cout << "Discountul: ";
        in >> discount;
        if (discount < 0 || discount > 10 || typeid(discount) != typeid(int)) {
            throw 2;
        }
    } catch(int x) {
        std::cout << "Discountul trebuie sa fie intre 0 si 10 si sa fie un numar intreg\n";
    }
    try {
        std::cout << "Suprafata curte: ";
        in >> suprafataCurte;
        if (suprafataCurte < 0 || typeid(suprafataCurte) != typeid(int)) {
            throw 3;
        }
    } catch(int x) {
        std::cout << "Suprafata trebuie sa fie un numar natural\n";
    }
    try {
        std::cout << "Numarul de etaje: ";
        int n;
        in >> n;
        if (n < 0 || typeid(n) != typeid(int)) {
            throw 4;
        }
        for(int i = 0; i < n; ++i) {
            std::cout << "suprafataEtaj[" << i << "]" << " = ";
            int suprafataEtaj;
            in >> suprafataEtaj;
            if (suprafataEtaj < 0 || typeid(suprafataEtaj) != typeid(int)){
                throw 4;
            }
            suprafataEtaje.push_back(suprafataEtaj);
        }
    } catch(int x) {
        std::cout << "Numarul de etaje si suprafata pe fiecare etaj trebuie sa fie numere naturale\n";
    }
}

void Casa::afisare() {
    std::cout << "numeClient = " << numeClient << "\n";
    std::cout << "pret = " << pret << "\n";
    std::cout << "discount = " << discount << "\n";
    std::cout << "suprafataCurte = " << suprafataCurte << "\n";
    std::cout << "numarEtaje = " << suprafataEtaje.size() << "\n";
    int n = suprafataEtaje.size();
    for(int i = 0; i < n; ++i) {
        std::cout << "suprafataEtaje[" << i << "] = " << suprafataEtaje[i] << "\n";
    }
}
