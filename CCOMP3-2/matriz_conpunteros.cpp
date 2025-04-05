#include <iostream>
using namespace std;

int main(){
    int A[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    int (*p)[3] = A; //para arrays con dimensiones (matriz)
    cout << p << endl;
    cout << *A + 6 << endl; //adentro
    cout << A + 8 << endl; //afuera
    cout << *(A + 3) << endl; //afuera
    cout << *(A + 3) + 2 << endl; //afuera y adentro
    cout << *(*(A + 3) +2) << endl; //para sacar el número de adentro
    return 0;
}
        
