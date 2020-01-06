#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <typeinfo>
#include "Gestiune.h"

int main()
{
    Gestiune <Casa*> gestiune_c;
    gestiune_c.citireCase();
    gestiune_c.afiseazaTotal();
    gestiune_c.afisareCase();
    Gestiune <Locuinta*> gestiune_l;
    gestiune_l.citireLocuinte();
    gestiune_l.afisareLocuinte();

    return 0;
}
