#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include "Magazin.h"
int main()
{
    Magazin m;
    m.ActualizareStoc();
    m.AfisareStoc();
    m.ZiDeLucru();
    m.AfisareStoc();
    std::cout << "Totalul zilei este: " << m.getTotal() << "\n";
    std::cout << "Numarul de produse vandute este: " << m.getProduseVandute() << "\n";
    return 0;
}
