#include <iostream>
#include <iomanip>

using namespace std;

void imprimirMatriz(int (*m)[3]) {
    for (int (*p)[3] = m; p < m + 3; ++p) {
        for (int *q = *p; q < *p + 3; ++q) {
            cout << setw(4) << *q;
        }
        cout << "\n";
    }
    cout << "---------------\n";
}

void multi(int (*p)[3][3]) {
    int *resultado = &p[2][0][0]; // Resultado comienza en matriz[2][0][0]

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j, ++resultado) {
            *resultado = 0;
            for (int k = 0; k < 3; ++k) {
                int *a = *(*(p + 0) + i) + k;      // A[i][k]
                int *b = *(*(p + 1) + k) + j;      // B[k][j]
                *resultado += (*a) * (*b);
            }
        }
    }
}

int main() {
    int matrices[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
        },
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
        }
    };

    cout << "Matriz A:\n";
    imprimirMatriz(matrices[0]);

    cout << "Matriz B:\n";
    imprimirMatriz(matrices[1]);

    multi(matrices);

    cout << "Resultado A x B:\n";
    imprimirMatriz(matrices[2]);

    return 0;
}