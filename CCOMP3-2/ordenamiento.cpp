#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void merge(int* p, int* q) {
    int size = (q - p) * 2;
    int* temp = new int[size];

    int* a = p;
    int* b = q;
    int i = 0;

    while (a < q && b < p + size) {
        if (*a <= *b) {
            temp[i++] = *a++;
        } else {
            temp[i++] = *b++;
        }
    }

    while (a < q) {
        temp[i++] = *a++;
    }

    while (b < p + size) {
        temp[i++] = *b++;
    }

    for (int j = 0; j < size; j++) {
        p[j] = temp[j];
    }

    delete[] temp;
}


int main() {
    int array[10] = {2, 8, 32, 44, 130, 1, 11, 25, 37, 77};
    int* p = array;
    int* q = array + 5;

    // Ordenar primera mitad
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }

    // Ordenar segunda mitad
    for (int i = 5; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (array[i] > array[j]) {
                swap(array[i], array[j]);
            }
        }
    }

    merge(p, q);

    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
