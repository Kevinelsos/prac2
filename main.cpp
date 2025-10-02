#include "problemas.h"
#include <iostream>
#include <limits>

using namespace std;
int main()
{
    while (true) {
        int opcion;
        cout << "ingrese el numeral del problema (solo pares): " << endl;
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
        case 1:
            problema1();
            break;
        case 6:
            problema6();
            break;
        case 8:
            problema8();
            break;
        case 10:
            problema10();
            break;
        case 12:
            problema12();
            break;
        case 14:
            problema14();
            break;
        case 16:
            problema16();
            break;
        case 17:
            problema17();
            break;
        case 18:
            problema18();
            break;
        default:
            cout << "Ingrese un problema valido."<<endl;
            break;
        }
    }
    return 0;
}
