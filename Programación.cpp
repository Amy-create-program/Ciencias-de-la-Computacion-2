#include <iostream>
using namespace std;


int suma(int a, int b){
	return a + b;
}
int resta(int a, int b){
	return a - b;
}

int main() {
	int A[10] = {7, 6, 1, 5, 8, 9, 4, 2, 3, 10};
	int B[10] = {0, 0, 0, 1, 1, 0, 0, 1, 1, 0};
	int(*F[2])(int, int) = {suma,resta};
	int res = 0;
	for(int i = 0; i < 10; i++){
		res = (*(F+*(B+i)))(res, *(A+i));
		cout << res << " ";
	}
	return 0;
}

