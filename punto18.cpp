#include <iostream>

using namespace std;

int Factorial(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}

string enesimaPermutacion(int* digitos,int n) {

    string permutacion;
    --n;

    for (int i = 9; i >= 0; --i) {
        int permutacionesTotales = Factorial(i);
        int indice = n / permutacionesTotales;
        permutacion += to_string(digitos[indice]);

        for (int j = indice; j < 9; ++j) {
            digitos[j] = digitos[j + 1];
        }
        n %= permutacionesTotales;
    }

    return permutacion;
}

void problema18(){
    int digitos[10]={0,1,2,3,4,5,6,7,8,9};
    int *pDigitos = digitos;
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;
    if (n < 1)cout<<"valor incorrecto, debe ser mayor que 1"<<endl;
    else {
        string permutacion = enesimaPermutacion(pDigitos,n);
        cout << "La permutacion numero " << n << " es: " << permutacion << endl;
    }

}
