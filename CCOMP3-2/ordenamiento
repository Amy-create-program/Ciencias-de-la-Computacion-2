#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int array[10]={2, 8, 32, 44, 130, 1, 11, 25, 37, 77};
    int* p;
    int* q;
    for(int i = 5; i < 10; i++) {
        q = &array[i];
        for(int j = i - 5 ; j < 10; j++){
        p = &array[j];
            if (*p > *q){
                swap(*p, *q);
            }
            else{
                p = &array[0];
            }
        }
    }
    
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
        
