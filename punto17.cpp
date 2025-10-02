#include <iostream>

using namespace std;
int sumaDiv(int i);

void problema17() {
    int frontera = 0, n_amigable = 0;
    cout << "Ingrese el numero: ";
    cin >> frontera;

    for (int i = 2; i <frontera ; i++){
        int suma_i = sumaDiv(i);
        if(suma_i !=i && suma_i<frontera){
            int suma_j = sumaDiv(suma_i);
            if(suma_j == i && i < suma_i){
                n_amigable += i + suma_i;
            }
        }
    }
    cout << "El resultado de la suma de los numeros amigables, menores que: "<<frontera<<" es: "<<n_amigable<<endl;
}

int sumaDiv(int i){
    int sumadivisores = 0;
    for(int j = 1;j<i;j++){
        if((i%j)==0){
            sumadivisores+=j;
        }
    }
    return sumadivisores;
}
