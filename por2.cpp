//Escribir una función que reciba un arreglo dinámico de enteros y su tamaño, y duplique el valor de cada elemento usando punteros. No se cambia el tamaño del arreglo, solo se modifica su contenido.
#include <iostream>
using namespace std;
void cambio(int* array, int tam){
    for (int i = 0; i < tam; i++){
        array[i] = array[i]*2;
    }
}

int main(){
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;
    int* arreglo = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Ingrese los valores: " << endl;
        cin >> arreglo[i];
    }
    cambio(arreglo, n);
    
    for(int i = 0; i < n; i++){
        cout << arreglo[i] << " ";
    }
}

        