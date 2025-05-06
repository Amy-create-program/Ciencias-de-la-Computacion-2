//Crear una función que reciba un arreglo dinámico de enteros y su tamaño, y devuelva cuántos números pares contiene el arreglo. Todo usando punteros
#include <iostream>
using namespace std;
int par(int* array, int tam){
    int count = 0;
    for (int i = 0; i < tam; i++){
        if(array[i]%2==0){
           count++;
        }
    }
    return count;
}

int main(){
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Ingrese los numeros para el array" << "[" << i << "]: ";
        cin >> a[i];
    }
    int total = par(a, n);
    cout << "El total de números pares es: " << total << endl;

}
        