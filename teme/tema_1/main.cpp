// Tema 14: Polinom dinamic
#include <iostream>
#include "Polinom_dinamic.h"
using namespace std;
int main()
{
    Polinom_dinamic* objects;
    int n;
    cout << "Number of objects: " << endl;
    cin >> n;
    objects = Polinom_dinamic::ReadObjects(n);
    return 0;
}
