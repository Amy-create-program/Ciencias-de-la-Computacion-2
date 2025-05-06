//Escribir una función que reciba dos punteros a enteros y intercambie sus valores.

#include <iostream>
using namespace std;
void swap(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
};

int main(){
    int* c;
    int x;
    cout << "Ingrese un número: ";
    cin >> x;
    c = &x;
    int* q;
    int y;
    cout << "Ingrese otro número: ";
    cin >> y;
    q = &y;
    cout << *c << " " << *q << endl;
    swap(c, q);
    cout << *c << " " << *q;
}
    