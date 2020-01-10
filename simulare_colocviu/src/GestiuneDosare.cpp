#include "GestiuneDosare.h"
#include <utility>
#include <iostream>
GestiuneDosare::GestiuneDosare() {
    locuriDistanta = 0;
    locuriFrecventa = 0;
    nrDosare = 0;
}

GestiuneDosare::GestiuneDosare(const GestiuneDosare& g) {

}

GestiuneDosare& GestiuneDosare::operator=(const GestiuneDosare& g) {
    if (this == &g) return *this;

    return *this;
}

GestiuneDosare& GestiuneDosare::operator += (DosarDistanta* dd) {

    dosare.insert(std::make_pair(dd, 0));
    return (*this);

}

GestiuneDosare& GestiuneDosare::operator += (DosarFrecv *df) {

    dosare.insert(std::make_pair(df, 1));
    return (*this);

}
std::istream& operator >> (std::istream& in, GestiuneDosare& g) {

    in >> g.locuriDistanta;
    in >> g.locuriFrecventa;
    in >> g.nrDosare;

    for(int i = 0; i < g.nrDosare; ++i) {
        int op;
        std::cout << "optiune = ";
        in >> op;
        switch(op) {
            case 0 : {
                //distanta
                DosarDistanta* dd = new DosarDistanta;
                in >> (*dd);
                g += dd;

            }
            break;
            case 1: {
                DosarFrecv* df = new DosarFrecv;
                in >> (*df);
                g += df;
                //frecventa
            }
            break;

        }
    }

    return in;
}
std::ostream& operator << (std::ostream& out, GestiuneDosare& g) {

    out << "DISTANTA\n";

    for(auto i : g.dosare) {
        if (i.second == 0) {
            out << (*i.first);
        }

    }


    out << "FRECVENTA\n";
    for(auto i : g.dosare) {
        if (i.second == 1) {
            out << (*i.first);
        }

    }
    return out;

}
void GestiuneDosare::afisareAdmisi() {

    int dist = locuriDistanta;
    int frecv = locuriFrecventa;
    std::cout << "DISTANTA\n";

    for(auto i : dosare) {

        if (i.second == 0) {
            if (dist > 0 && (*i.first).mediaAdmitere() >= 5) {
                std::cout << (*i.first);
                --dist;
            }
        }


    }
    std::cout << "FRECVENTA\n";

    for(auto i : dosare) {
        if (i.second == 1) {
            if (frecv > 0 && (*i.first).mediaAdmitere() >= 5) {
                std::cout << (*i.first);
                --frecv;
            }
        }
    }


}
