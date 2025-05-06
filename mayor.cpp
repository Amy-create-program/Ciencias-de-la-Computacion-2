/*Crear una función que reciba un arreglo dinámico de enteros 
y su tamaño, y devuelva el número más grande usando punteros.
*/

#include <iostream>
using namespace std;
int mayor(int* array, int tam){
    int mayor = *array;
    for (int i = 0; i < tam; i++){
        if(array[i] > mayor){
            mayor = array[i];
        }
    }
    return mayor;
}

int main(){
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Ingrese los valores" << "[" << i << "]: ";
        cin >> a[i];
    }
    cout << "El mayor número es: " << mayor(a, n) << endl;
    delete[] a;
}