#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1459265358979323846
#endif

float areaCirculo(void*params){
	float* radio = (float*) params;
	return M_PI * (*radio) * (*radio);
}
float areaRectangulo(void* params){
	float* dimensiones = (float*) params;
	return dimensiones[0] * dimensiones[1];
}
float areaTriangulo(void* params){
	float* dimensiones =  (float*)params;
	return(dimensiones[0] * dimensiones[1]) / 2.0f;
}
float areaCuadrado(void* params){
	float* lado = (float*) params;
	return (*lado) * (*lado);
}
typedef float(*FuncionArea)(void*);
void ejecuta(FuncionArea funciones[], void* parametros[], const char* const nombres[], int cantidad){
	for(int i = 0; i < cantidad; ++i){
		float area = funciones[i](parametros[i]);
		std::cout << "Area del " << nombres[i] << ": " << area << std::endl;
	}
}
int main(){
	float radio = 5.0f;
	float rectangulo[] = {4.0f, 6.0f};
	float triangulo[] = {3.0f, 7.0f};
	float lado = 4.0f;
	FuncionArea funciones[] = {areaCirculo, areaRectangulo, areaTriangulo, areaCuadrado}; 
	void *parametros[] = {&radio, rectangulo, triangulo, &lado};
	const char* nombres[] = {"circulo", "rectangulo", "triangulo", "cuadrado"};
	ejecuta(funciones, parametros, nombres, 4);
	
	return 0;
}
