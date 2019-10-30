#include <iostream>
#include <math.h>
#include "Polinom_dinamic.h"
using namespace std;

Polinom_dinamic::Polinom_dinamic(){

    head = NULL;
    tail = NULL;

}
Polinom_dinamic::Polinom_dinamic(const Polinom_dinamic& p){

    head = NULL;
    tail = NULL;
    if(p.head == NULL){
        return;
    }
    node* q = p.head;
    while(q != NULL){
        this->AddElement(q->coeficient, q->exponent);
        q = q->next;
    }

}
Polinom_dinamic::~Polinom_dinamic(){

    cout << "So long, object!\nYou will be missed" << endl;
    if(head != NULL){
    node* p = head;
    while( head != NULL ){
        cout << "Elementul";
        cout <<"( "<<head->coeficient << ", " << head->exponent << " ) a fost sters" << endl;
        head = head->next;
        delete p;
        p = head;
    }
    }

}
node* Polinom_dinamic::GetNodeHead(){
    return head;
}
node* Polinom_dinamic::GetNodeTail(){
    return tail;
}
double Polinom_dinamic::Calcul(int x){

    double value;
    node* p = head;
    while(p != NULL){

        value += pow(x, p->exponent) * p->coeficient;
        p = p->next;

    }
    return value;

}
void Polinom_dinamic::AddElement(double coef, double exp){

    if(coef == 0){
        return;
    }
    node* q = new node;
    q->coeficient = coef;
    q->exponent = exp;
    q->next = NULL;
    if(head == NULL){
        head = q;
        tail = q;
        q = NULL;
    }else{
        if(head->exponent < exp){
            q->next = head;
            head = q;

        }else if(tail->exponent > exp){
            tail->next = q;
            tail = q;
        }else{
            node* c = head;
            node* p;
            while(c->next != NULL && c->exponent > exp){
            p = c;
            c = c->next;
            }
            p->next = q;
            q->next = c;
            }
    }
}
Polinom_dinamic* Polinom_dinamic::ReadObjects(int n){

    Polinom_dinamic* objects = new Polinom_dinamic [n];
    for(int i = 0; i < n; i++){
        cout << "New Object" << endl;
        cin >> objects[i];
        cout << objects[i];
    }
    return objects;

}
Polinom_dinamic& Polinom_dinamic::operator + (const Polinom_dinamic& p1){

    Polinom_dinamic* result = new Polinom_dinamic;
    node* p = p1.head;
    node* q = head;
    while(p != NULL && q != NULL){
        if(p->exponent > q->exponent){
            result->AddElement(p->coeficient, p->exponent);
            p = p->next;
        }else if(q->exponent > p->exponent){
            result->AddElement(q->coeficient, q->exponent);
            q = q->next;
        }else{
            double sum = p->coeficient + q->coeficient;
            if(sum != 0){
                result->AddElement(sum, p->exponent);
            }
            p = p->next;
            q = q->next;
        }
    }
    while(p != NULL){
        result->AddElement(p->coeficient, p->exponent);
        p = p->next;
    }
    while(q != NULL){
        result->AddElement(q->coeficient, q->exponent);
        q = q->next;
    }
    return *result;

}
Polinom_dinamic& Polinom_dinamic::operator - (const Polinom_dinamic& p1){

    Polinom_dinamic *result = new Polinom_dinamic;
    node* p = p1.head;
    node* q =  head;
    while(p != NULL && q != NULL){
        if(p->exponent > q->exponent){
            result->AddElement(-p->coeficient, p->exponent);
            p = p->next;
        }else if(q->exponent > p->exponent){
            result->AddElement(q->coeficient, q->exponent);
            q = q->next;
        }else{
            double diff = q->coeficient - p->coeficient;
            if(diff != 0){
                result->AddElement(diff, p->exponent);
            }
            p = p->next;
            q = q->next;
        }
    }
    while(p != NULL){
        result->AddElement(-p->coeficient, p->exponent);
        p = p->next;
    }
    while(q != NULL){
        result->AddElement(q->coeficient, q->exponent);
        q = q->next;
    }

    return *result;

}
Polinom_dinamic& Polinom_dinamic::operator * (const Polinom_dinamic& p1){

    Polinom_dinamic* result = new Polinom_dinamic;
    node* p = p1.head;
    while(p != NULL){
        node* aux = head;
        while(aux != NULL){
            double product_coef = p->coeficient * aux->coeficient;
            double product_exp = p->exponent * aux->exponent;
            if(p->exponent == 0){
                product_exp = aux->exponent;
            }else if(aux->exponent == 0){
                product_exp = p->exponent;
            }
                result->AddElement(product_coef, product_exp);
            aux = aux->next;
        }
        p = p->next;
    }
    node *d;
    p = result->head;
    while(p != NULL && p->next != NULL){
        if(p->exponent == p->next->exponent){
            p->coeficient = p->coeficient + p->next->coeficient;
            d = p->next;
            p->next = p->next->next;
            delete d;
        }
        p = p->next;
    }
    return *result;

}
Polinom_dinamic& Polinom_dinamic::operator = (const Polinom_dinamic& p1){

    Polinom_dinamic temp(p1);
    swap(temp.head, head);
    swap(temp.tail, tail);
    return *this;

}
ostream & operator << (ostream& out, Polinom_dinamic& p){

    node* q = p.head;
    if(q != NULL){
    if(q->coeficient >= 0){
        cout << q->coeficient << "*X^" << q->exponent;
    }else if(q->coeficient < 0){
        cout << "(" << q->coeficient << ")*X^" << q->exponent;
    }
    while(q->next != NULL){
        q = q->next;
        if(q->coeficient > 0){
        cout << " + " << q->coeficient << "*X^" << q->exponent;
        }else if(q->coeficient < 0){
        cout << " + ("<< q->coeficient << ")*X^" << q->exponent;
        }
    }
    }
    cout << endl;

    return out;

}
istream & operator >> (istream& in, Polinom_dinamic& p){

    cout << "Numarul de elemente din lista este: " << endl;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "New element:" << endl;
        double coef, exp;
        cout << "coef: ";
        cin >> coef;
        cout << "exp: ";
        cin >> exp;
        p.AddElement(coef, exp);
    }
    return in;
}


