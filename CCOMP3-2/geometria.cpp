#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float areaCirculo(void* params) {
    return M_PI * (*(float*)params) * (*(float*)params);
}

float areaRectangulo(void* params) {
    return ((float*)params)[0] * ((float*)params)[1];
}

float areaTriangulo(void* params) {
    return (((float*)params)[0] * ((float*)params)[1]) / 2.0f;
}

float areaCuadrado(void* params) {
    return (*(float*)params) * (*(float*)params);
}

typedef float (*FuncionArea)(void*);

void ejecuta(FuncionArea funciones[], void* parametros[], const char* const nombres[], int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        float area = funciones[i](parametros[i]);
        std::cout << "Área del " << nombres[i] << ": " << area << std::endl;
    }
}

int main() {
    float radio = 5.0f;
    float rectangulo[] = {4.0f, 6.0f};
    float triangulo[] = {3.0f, 7.0f};
    float lado = 4.0f;

    FuncionArea funciones[] = {areaCirculo, areaRectangulo, areaTriangulo, areaCuadrado};
    void* parametros[] = {&radio, rectangulo, triangulo, &lado};
    const char* nombres[] = {"círculo", "rectángulo", "triángulo", "cuadrado"};

    ejecuta(funciones, parametros, nombres, 4);

    return 0;
}