#include <iostream>
using namespace std;
void problema6()
{
    int tam = 100;

    char *aptextomi = new char[tam + 1];
    char *aptextoma = new char[tam + 1];

    cout << "Ingrese una cadena: ";
    cin.getline(aptextomi, tam + 1);

    int i = 0;
    for (; *(aptextomi + i) != '\0'; i++) {
        if (*(aptextomi + i) >= 'a' && *(aptextomi + i) <= 'z') {
            *(aptextoma + i) = *(aptextomi + i) - 32;
        } else {
            *(aptextoma + i) = *(aptextomi + i);
        }
    }
    *(aptextoma + i) = '\0';

    cout << "En mayuscula: " << aptextoma << '\n';
    cout << "Original: " << aptextomi << '\n';

    // Liberar memoria
    delete[] aptextomi;
    delete[] aptextoma;
}
