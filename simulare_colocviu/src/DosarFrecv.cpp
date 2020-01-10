#include "DosarFrecv.h"
#include <iostream>

DosarFrecv::DosarFrecv() {
    notaProba1 = 0;
    notaProba2 = 0;
    mediaProbe = 0;
}

DosarFrecv::DosarFrecv(const DosarFrecv& d) {

}

DosarFrecv& DosarFrecv::operator=(const DosarFrecv& d) {
    if (this == &d) return *this;
    return *this;
}

void DosarFrecv::citire(std::istream& in) {
    in >> nume;
    in >> mediaBac;
    in >> notaProba1;
    in >> notaProba2;

}
void DosarFrecv::afisare() {
    std::cout << nume;
    std::cout << mediaBac;
    std::cout << notaProba1;
    std::cout << notaProba2;

}
double DosarFrecv::mediaAdmitere() {

    double mediaA = 0;
    mediaA = mediaProbe * 0.8 + mediaBac * 0.2;
    return mediaA;
}
