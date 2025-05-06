#include <iostream>

class Cadena {
private:
    char* texto;
    int tam;

public:
    // Constructor: copiar la cadena manualmente
    Cadena(const char* fuente) {
        tam = 0;
        const char* ptr = fuente;
        while (*ptr != '\0') {
            ++tam;
            ++ptr;
        }

        texto = new char[tam + 1];

        for (int i = 0; i < tam; ++i) {
            *(texto + i) = *(fuente + i);
        }
        *(texto + tam) = '\0';
    }

    // Obtener longitud
    int longitud() const {
        return tam;
    }

    // Imprimir carácter por carácter
    void imprimir() const {
        const char* ptr = texto;
        while (*ptr != '\0') {
            std::cout << *ptr;
            ++ptr;
        }
        std::cout << std::endl;
    }

    // Invertir la cadena
    void invertir() {
        for (int i = 0; i < tam / 2; ++i) {
            char temp = *(texto + i);
            *(texto + i) = *(texto + tam - 1 - i);
            *(texto + tam - 1 - i) = temp;
        }
    }

    // Destructor
    ~Cadena() {
        delete[] texto;
    }
};
