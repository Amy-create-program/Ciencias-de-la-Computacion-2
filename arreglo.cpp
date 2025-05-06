//Escribe una funcion que reciba un arreglo dinámico,
//su tamaño y un nuevo tamaño, y cambie el tamaño del arreglo
#include <iostream>
using namespace std;
int* redimensionar(int* arreglo, int nuevoTam, int tamOriginal){
    int* array = new int[nuevoTam];
    for (int i = 0; i < nuevoTam && i < tamOriginal; i++){
        array[i] = arreglo[i];
    }
    return array;
}

int main() {
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++){
        cout << "Ingrese el elemento " << "[" << i << "]:";
        cin >> a[i];
    }
    int b;
    cout << "Ingrese el nuevo tamaño del array: ";
    cin >> b;
    int* arreglonuevo = redimensionar(a, b, n);
    cout << "Este es el nuevo array: ";
    for (int i = 0; i < b; i++){
        cout << arreglonuevo[i] << " ";
    }
    cout << " " << endl;
}