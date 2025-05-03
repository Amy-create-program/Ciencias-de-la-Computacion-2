#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

bool puzzleResuelto(int (*matriz)[3]) {
    int contador = 1;
    for (int (*p)[3] = matriz; p < matriz + 3; ++p) {
        for (int *q = *p; q < *p + 3; ++q) {
            if (q == *(matriz + 2) + 2) return (*q == 0);
            if (*q != contador++) return false;
        }
    }
    return true;
}

void imprimirMatriz(int (*matriz)[3], int *vacio) {
    cout << "\n";
    for (int (*p)[3] = matriz; p < matriz + 3; ++p) {
        for (int *q = *p; q < *p + 3; ++q) {
            if (q == vacio) {
                cout << "    ";
            } else {
                cout << " " << setw(2) << *q << " ";
            }
            cout << "|";
        }
        cout << "\n-----------------\n";
    }
    cout << "\nUsa las flechas para mover los números\n";
}

int main() {
    int matriz[3][3] = {{4, 2, 6}, {1, 3, 7}, {8, 5, 0}};
    int *vacio = *(matriz + 2) + 2;

    while (true) {
        imprimirMatriz(matriz, vacio);

        if (puzzleResuelto(matriz)) {
            cout << "\n¡Felicidades! Resolviste el puzzle.\n";
            break;
        }

        int tecla = _getch();
        if (tecla == 224) tecla = _getch();

        int dy = 0, dx = 0;
        switch (tecla) {
            case 72: dy = 1; break;  // Flecha arriba
            case 80: dy = -1; break; // Flecha abajo
            case 75: dx = 1; break;  // Flecha izquierda
            case 77: dx = -1; break; // Flecha derecha
        }

        // Calcula la posición actual del puntero vacío
        int y = (vacio - **matriz) / 3;
        int x = (vacio - **matriz) % 3;

        int nuevaY = y + dy;
        int nuevaX = x + dx;

        if (nuevaY >= 0 && nuevaY < 3 && nuevaX >= 0 && nuevaX < 3) {
            int *objetivo = *(matriz + nuevaY) + nuevaX;
            *vacio = *objetivo;
            *objetivo = 0;
            vacio = objetivo;
        }
    }

    return 0;
}