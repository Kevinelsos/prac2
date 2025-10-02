#include <iostream>
#include <limits>
using namespace std;

int problema1()
{
    int dividendos[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int resto = 0;
    int valor = 0;

    cout << "Ingrese el valor al cambio (solo numeros enteros positivos): " << endl;

    while (true) {
        cin >> valor;
        if (cin.fail() || valor < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        } else {
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        resto = valor / dividendos[i];
        valor = valor - (resto * dividendos[i]);
        cout << dividendos[i] << " : " << resto << endl;
    }

    cout << "Faltante: " << valor << endl;


}

