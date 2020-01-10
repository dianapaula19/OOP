#include "Dosar.h"
Dosar ::Dosar () {
    nume = "";
    mediaBac = 0;
}

Dosar ::Dosar (const Dosar& d) {
    nume = d.nume;
    mediaBac = d.mediaBac;
}

Dosar& Dosar::operator = (const Dosar& d) {
    if (this == &d) return *this;
    nume = d.nume;
    mediaBac = d.mediaBac;
    return *this;
}
std::istream& operator >> (std::istream& in, Dosar& d) {

    d.citire(in);
    return in;

}
std::ostream& operator << (std::ostream& out, Dosar& d) {

    d.afisare();
    return out;

}
