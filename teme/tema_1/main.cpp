// Tema 14: Polinom dinamic
#include <iostream>
#include "Polinom_dinamic.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    Polinom_dinamic objects[n];
    Polinom_dinamic::ReadObjects(n, objects);

    return 0;
}
