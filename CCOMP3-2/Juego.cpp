#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

bool puzzleResuelto(int (*matriz)[3]) {
    int contador = 1;
    for (int (*p)[3] = matriz; p < matriz + 3; p++) {
        for (int *q = *p; q < (p == matriz + 2 ? *p + 3 : *(p + 1)); q++) {
            if (q == *(matriz + 2) + 2) return (*q == 0);
            if (*q != contador++) return false;
        }
    }
    return true;
}

void imprimirMatriz(int (*matriz)[3], int vacioY, int vacioX) {
    cout << "\n";
    int y = 0;
    for (int (*p)[3] = matriz; p < matriz + 3; p++, y++) {
        int x = 0;
        for (int *q = *p; q < (p == matriz + 2 ? *p + 3 : *(p + 1)); q++, x++) {
            if (*q == 0) {
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
    int vacioY = 2, vacioX = 2;

    while (true) {
        imprimirMatriz(matriz, vacioY, vacioX);

        if (puzzleResuelto(matriz)) {
            cout << "\n¡Felicidades! Resolviste el puzzle.\n";
            break;
        }

        int tecla = _getch();
        if (tecla == 224) tecla = _getch();

        int nuevaY = vacioY, nuevaX = vacioX;

        switch (tecla) {
            case 72: nuevaY++; break; // Flecha arriba
            case 80: nuevaY--; break; // Flecha abajo
            case 75: nuevaX++; break; // Flecha izquierda
            case 77: nuevaX--; break; // Flecha derecha
        }

        if (nuevaY >= 0 && nuevaY < 3 && nuevaX >= 0 && nuevaX < 3) {
            int *actual = *(matriz + vacioY) + vacioX;
            int *objetivo = *(matriz + nuevaY) + nuevaX;

            *actual = *objetivo;
            *objetivo = 0;
            vacioY = nuevaY;
            vacioX = nuevaX;
        }
    }

    return 0;
} 
