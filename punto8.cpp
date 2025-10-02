#include <iostream>
#include <limits>
using namespace std;

int main() {
    int tam = 100;

    char *original = new char[tam + 1];
    char *letras = new char[tam + 1];
    char *numeros = new char[tam +1];

    cout << "Ingrese una cadena: ";
    cin.getline(original, tam + 1);

    int i = 0, j = 0, k = 0;
    for (; *(original + i) != '\0'; i++) {
        if (*(original + i) >= '0' && *(original + i) <= '9') {
            *(numeros + j) = *(original + i);
            j++;
        } else {
            *(letras + k) = *(original + i);
            k++;
        }
    }
    *(letras + k) = '\0'; 
    *(numeros + j) = '\0'; 

    cout << "Original: " << original << "\n";
    cout << "Texto: " << letras;
    cout << " Numeros: " << numeros << '\n';

    // Liberar memoria
    delete[] original;
    delete[] letras;
    delete[] numeros;

    return 0;
}
