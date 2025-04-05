#include <iostream>
using namespace std;

int main(){
    int A[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    
    for(int(*p)[3] = A; p < A+4; p++){      //afuera
        for(int* q = *p; q < *(p+1); q++){  //adentro
            cout << *q << " ";
        }
    }
}
        
