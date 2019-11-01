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
    Polinom_dinamic();
    Polinom_dinamic(const Polinom_dinamic&);
    Polinom_dinamic(bool);
    ~Polinom_dinamic();
    node* GetNodeHead();
    node* GetNodeTail();
    double Calcul(int);
    void AddElement(double, double);
    static void ReadObjects(int, Polinom_dinamic*);
    Polinom_dinamic& operator --();
    Polinom_dinamic& operator --(int);
    Polinom_dinamic& operator + (const Polinom_dinamic&);
    Polinom_dinamic& operator - (const Polinom_dinamic&);
    Polinom_dinamic& operator * (const Polinom_dinamic&);
    Polinom_dinamic& operator = (const Polinom_dinamic&);
    bool operator != (const Polinom_dinamic&);
    friend ostream& operator << (ostream& out, Polinom_dinamic& p);
    friend istream& operator >> (istream& in, Polinom_dinamic& p);

};
class Management{
    private:
        Polinom_dinamic* objects;
        int nr_of_objects;

};
#endif // POLINOM_DINAMIC_H_INCLUDED
