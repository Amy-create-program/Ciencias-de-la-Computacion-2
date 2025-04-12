#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void merge(int* p, int* q){
    int *end = q + (q - p);
    while(p < q && q < end) {
        if(*p <= *q) {
        p++;
    }   else {
            int val = *q;
            int *temp = q;
            
            while ( temp != p){
                *temp =*(temp - 1);
                temp--;
            }
            
            *p = val;
            
            p++;
            q++;
        }
    } 
}

int main(){
    int array[10]={2, 8, 32, 44, 130, 1, 11, 25, 37, 77};
    int* p = array;
    int* q = array + 5;
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1 ; j < 5; j++){
            if(array[i] > array[j]){
                swap(array[i], array[j]);
            }
        }
    }
    for(int i = 5; i < 10; i++){
        for(int j = i+1; j < 10; j++){
            if(array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
    
    merge(p, q);
    
    for(int i = 0; i < 10; i++){
        cout << array[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
        
