#include <iostream>
using namespace std;

int main(){

    int *a;
    int b = 5;
    a = &b;
    cout << a << endl; //dirección de memoria
    cout << &a << endl; //dirección de memoria
    cout << *a << endl; //5
    int &c = b;
    cout << c << endl; //5
    cout << &c << endl; //dirección de memoria
    c = 7;
    cout << b << endl; //7

return 0;
}
