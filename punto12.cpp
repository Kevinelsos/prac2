#include <iostream>
#include <limits>
using namespace std;

void imprimir(int *apuntador, int tam);

int main() {
    int tam = 0;
    
    cout << "Ingrse el tamaño de la matriz cuadrada: ";

    while (true) {
        cin >> tam;
        if (cin.fail() || tam < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Ingrese un numero entero positivo: ";
        } else {
            break;
        }
    }

    int *ap = new  int[tam*tam];
    unsigned int index = 0;
    for(unsigned int i = 1; i <= tam; i++){
        for(unsigned int j = 1; j <= tam; j++){
            cout << "Ingrse el elemento en la fila: " << i << " columna: "<< j << "\n";
            cin >> *(ap+index);
            index++;
        }
    }

    int valor_esperado=0, valor_resultado = 0;
    //recorrer por filas
    for(int i = 1; i <= tam*tam; i++){
        valor_resultado += *(ap+i-1);
        if (i !=0 && (i % tam) == 0){
            if(i == tam){
                valor_esperado = valor_resultado;
                valor_resultado = 0;
            }
            else{
                if (valor_esperado != valor_resultado){
                    imprimir(ap, tam);
                    cout << "Cuadrado no magico." << "\n";
                    return 0; 
                }
                else valor_resultado = 0;
            }
        }
    }
    // recorres por columnas
    for(int i = 0; i < tam; i++){
        for(int j=0; j < tam; j++){
            valor_resultado += *(ap + j*tam + i);
        }
        if (valor_esperado != valor_resultado){
            imprimir(ap, tam);
            cout << "Cuadrado no magico." << "\n";
            return 0; 
            }
        else valor_resultado = 0;

    }

    // diagonal principal
    for(int i = 0; i < tam; i++){
        for(int j=0; j < tam; j++){
            if(i == j) valor_resultado += *(ap + j*tam + i);
        }
    }
    if (valor_esperado != valor_resultado){
        imprimir(ap, tam);
        cout << "Cuadrado no magico." << "\n";
        return 0; 
    }
    else valor_resultado = 0;

    // diagonal secundaria
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (i + j == tam - 1) {
                valor_resultado += *(ap + j * tam + i);
            }
        }
    }

    if (valor_esperado != valor_resultado) {
        imprimir(ap, tam);
        cout << "Cuadrado no magico." << "\n";
        return 0;
    } else valor_resultado = 0;

    cout << "Cuadro magico."<<"\n";
    imprimir(ap, tam);
    cout << "Valor de columnas, filas y digonales: "<< valor_esperado;

    return 0;
}
void imprimir(int *apuntador, int tam) {
    cout << "\nMatriz ingresada:\n";
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            cout << *(apuntador + i * tam + j) << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}