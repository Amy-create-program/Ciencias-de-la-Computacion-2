/*Crear una función que reciba un arreglo dinámico de enteros 
y su tamaño, y devuelva la suma de todos los elementos usando 
punteros.
*/
#include <iostream>
using namespace std; 

int suma(int* arreglo, int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma = suma + *(arreglo + i);
    }
    return suma;
}

int main() {
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese los elementos del arreglo: " << "[" << i << "]: ";
        cin >> a[i];
    }
    cout << "la suma es: " << suma(a, n) << endl;
    delete[] a;
    return 0;
}