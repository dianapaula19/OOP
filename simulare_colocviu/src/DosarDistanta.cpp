#include "DosarDistanta.h"
#include <iostream>

DosarDistanta::DosarDistanta() {
    notaMate = 0;
}

DosarDistanta::DosarDistanta(const DosarDistanta& d) {
    notaMate = d.notaMate;
}

DosarDistanta& DosarDistanta::operator = (const DosarDistanta& d) {
    if (this == &d) return *this;
    notaMate = d.notaMate;
    return *this;
}
void DosarDistanta::citire(std::istream& in) {
    in >> nume;
    in >> mediaBac;
    in >> notaMate;

}
void DosarDistanta::afisare() {
    std::cout << nume;
    std::cout << mediaBac;
    std::cout << notaMate;

}
double DosarDistanta::mediaAdmitere() {

    double mediaA = 0;
    mediaA = notaProbaOrala * 0.6 + notaMate * 0.4;
    return mediaA;

}

