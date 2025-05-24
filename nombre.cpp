#include <iostream>
using namespace std;



int main() {
	
	char a[5] = "hola";
	char b[4] = { 'h','o','l','a'};
	int c[3] = {1, 2, 3};
	char d[3][5]={ "Hugo","Paco","Luis"};
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	
	for(char* p =a; *p ; p++)
		cout << *p;
	cout << endl;
	for(char* p = b; *p; p++)
		cout << *p;
	cout << endl;
	for(char (*p)[5] = d; p < d+3; p++){
		cout << *p << endl;
	}
	for(char *p = (char*)d; p < *d+15; p++){
		cout << *p << endl;
	}
	
}
	

