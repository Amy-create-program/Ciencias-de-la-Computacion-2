#include <iostream>
#include <iomanip>

using namespace std;

void imprimirMatriz(int (*m)[3]) {
    for (int (*p)[3] = m; p < m + 3; p++) {
        for (int *q = *p; q < (p == m + 2 ? *p + 3 : *(p + 1)); q++) {
            cout << setw(4) << *q;
        }
        cout << "\n";
    }
    cout << "---------------\n";
}

void multi(int (*p)[3][3]) {

    for (int (*fila)[3] = p[2]; fila < p[2] + 3; fila++) { 
        for (int *col = *fila; col < (fila == p[2] + 2 ? *fila + 3 : *(fila + 1)); col++) { 
            int i = fila - p[2];
            int j = col - *fila; 
            *col = 0; 

            int *a = *(p[0] + i); 
            int *b = &p[1][0][j];

            for (int *pa = a, *pb = b; pa < (i == 2 ? a + 3 : *(p[0] + i + 1)); pa++, pb += 3) { 
                *col += (*pa) * (*pb); 
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
