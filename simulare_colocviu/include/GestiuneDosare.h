#ifndef GESTIUNEDOSARE_H
#define GESTIUNEDOSARE_H
#include <set>
#include "Dosar.h"
#include "DosarDistanta.h"
#include "DosarFrecv.h"

class GestiuneDosare {
private:
    std::set <std::pair <Dosar*, int> > dosare;
    int locuriDistanta;
    int locuriFrecventa;
    int nrDosare;
public:
    GestiuneDosare();
    GestiuneDosare(const GestiuneDosare&);
    GestiuneDosare& operator = (const GestiuneDosare&);
    GestiuneDosare& operator += (DosarDistanta*);
    GestiuneDosare& operator += (DosarFrecv*);
    void afisareAdmisi();
    friend std::istream& operator >> (std::istream&, GestiuneDosare&);
    friend std::ostream& operator << (std::ostream&, GestiuneDosare&);
};

#endif // GESTIUNEDOSARE_H
