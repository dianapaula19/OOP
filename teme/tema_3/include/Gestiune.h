#ifndef GESTIUNE_H
#define GESTIUNE_H
#include <set>
#include <cassert>
#include "Apartament.h"
#include "Casa.h"
#include "Locuinta.h"

template <class T>

class Gestiune {

    std::set < std::pair <T, int> > set_locuinte;
public:
    Gestiune() {
        std::cout << "Constructor " << typeid(*this).name() << "\n";
    }
    ~Gestiune() {
    std::cout << "Destructor " << typeid(*this).name() << "\n";
    }
    Gestiune& operator += (Apartament*);
    Gestiune& operator += (Casa*);
    void citireLocuinte();
    void afisareLocuinte();

};

template <class T>

Gestiune <T> & Gestiune <T> ::operator += (Apartament* a) {

    set_locuinte.insert(std::make_pair(a, 0));
    return *this;

}
template <class T>

Gestiune <T> & Gestiune <T> ::operator += (Casa* c) {

    set_locuinte.insert(std::make_pair(c, 1));
    return *this;

}

template <class T>

void Gestiune <T> :: citireLocuinte() {

    std::cout << "Numarul de locuinte pe care vreti sa le adaugati: \n";
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::cout << "0 - Apartament\n";
        std::cout << "1 - Casa\n";
        int op;
        std::cin >> op;
        switch(op) {
            case 0: {
                Apartament* a = new Apartament();
                assert(a == nullptr);
                std::cin >> (*a);
                (*this) += a;

            }
            break;
            case 1: {
                Casa* c = new Casa();
                assert(c == nullptr);
                std::cin >> (*c);
                (*this) += c;
            }
            break;
        }
    }
}
template <class T>
void Gestiune <T> :: afisareLocuinte() {

    for(auto i : set_locuinte) {
        std::cout << (*i.first);
    }

}

template <class T>

bool operator < (std::pair <T, int> p, std::pair <T, int> q) {

    if (p.first->calculChirie() < q.first->calculChirie()) {
        return true;
    } else {
        return false;
    }

}

template <>


class Gestiune <Casa*> {

    std::set < std::pair <Casa*, int> > set_case;
public:
    Gestiune() {
        std::cout << "Constructor " << typeid(*this).name() << "\n";
    }
    ~Gestiune() {
        std::cout << "Destructor " << typeid(*this).name() << "\n";
    }
    Gestiune& operator += (Casa*);
    void afiseazaTotal();
    void citireCase();
    void afisareCase();

};

Gestiune <Casa*> & Gestiune <Casa*> ::operator += (Casa* c) {

    set_case.insert(std::make_pair(c, 1));
    return *this;

}

void Gestiune <Casa*> :: afiseazaTotal() {

    double total = 0;
    for(auto i : set_case) {
        total += i.first->calculChirie();
    }
    std::cout << "Chiria obtinuta pentru toate casele este: " << total << "\n";

}

void Gestiune <Casa*> :: citireCase() {

    std::cout << "Numarul de case pe care vreti sa le adaugati: \n";
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        Casa* c = new Casa();
        std::cin >> (*c);
        (*this) += c;

    }
}
bool operator < (std::pair <Casa*, int> p, std::pair <Casa*, int> q) {

    if (p.first->calculChirie() < q.first->calculChirie()) {
        return true;
    } else {
        return false;
    }

}

void Gestiune <Casa*> :: afisareCase() {

    for(auto i : set_case) {
        std::cout << (*i.first);
    }

}

#endif // GESTIUNE_H
