// Tema 14: Polinom dinamic
#include <iostream>
#include "Polinom_dinamic.h"
using namespace std;
int main()
{
    Polinom_dinamic p1, p2;
    cin >> p1;
    cout << p1;
    cout << p1.GetNode()->coeficient <<" "<< p1.GetNode()->exponent << endl;
    cin >> p2;
    cout << p2;
    return 0;
}
