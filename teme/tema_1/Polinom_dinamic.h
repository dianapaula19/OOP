#ifndef POLINOM_DINAMIC_H_INCLUDED
#define POLINOM_DINAMIC_H_INCLUDED
using namespace std;
struct node{

    double coeficient, exponent;
    node* next;

};
class Polinom_dinamic{

private:
    node* head, *tail;
public:
    node* GetNode();
    Polinom_dinamic();
    ~Polinom_dinamic();
    Polinom_dinamic(const Polinom_dinamic&);
    void AddElement(double, double);
    double Calcul(int);
    void List();
    static Polinom_dinamic* ReadObjects(int);
    node* GetNodeHead();
    node* GetNodeTail();
    Polinom_dinamic& operator + (Polinom_dinamic&);
    Polinom_dinamic& operator - (Polinom_dinamic&);
    Polinom_dinamic& operator * (Polinom_dinamic&);
    friend ostream& operator << (ostream& out, Polinom_dinamic& p);
    friend istream& operator >> (istream& in, Polinom_dinamic& p);

};
#endif // POLINOM_DINAMIC_H_INCLUDED
