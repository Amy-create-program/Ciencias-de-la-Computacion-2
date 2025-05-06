//Crear una función que reciba un arreglo dinámico de enteros, su tamaño y un número a buscar, y devuelva cuántas veces aparece ese número en el arreglo, usando punteros.
#include <iostream>
using namespace std;

int a(int* array, int tam, int valor_a_buscar){
    int buscar = 0;
    for(int i = 0; i < tam; i++){
        if(array[i] == valor_a_buscar){
            buscar++;
        }
    }
    return buscar;
}

int main(){
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;
    int* arreglo = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Ingrese los valores para el array" << "[" << i << "]";
        cin >> arreglo[i];
    }
    int q;
    cout << "Ingrese el valor que deseas buscar: ";
    cin >> q;
    cout << "Este es el valor del número que buscaste se repite: " << a(arreglo, n, q) << endl;
}
        