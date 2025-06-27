#include <iostream>

template <class T>
struct Ascendente {
    bool operator()(T a, T b) {
        return a > b;
    }
};

template <class T>
struct Descendente {
    bool operator()(T a, T b) {
        return a < b;
    }
};

template <class T, class O>
class ordena {
    using it = T*;          
    it itord;               
public:
    void ordenar(it ini, it fin) {   
        itord = ini;  
        O criterio;

        for (it i = ini; i < fin - 1; ++i) {
            for (it j = i + 1; j < fin; ++j) {
                if (criterio(*i, *j)) {
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
            }
        }
    }
};

int main() {
    int arreglo[] = {5, 2, 9, 1, 7};
    using it = int*;

    it ini = arreglo;       
    it fin = arreglo + 5;   

    ordena<int, Ascendente<int>> ordenasc;   
    ordenasc.ordenar(ini, fin);               

    std::cout << "Ascendente: ";
    for (it p = ini; p < fin; ++p) std::cout << *p << " ";
    std::cout << std::endl;

    ordena<int, Descendente<int>> ordendesc;
    ordendesc.ordenar(ini, fin);

    std::cout << "Descendente: ";
    for (it p = ini; p < fin; ++p) std::cout << *p << " ";
    std::cout << std::endl;

    return 0;
}
