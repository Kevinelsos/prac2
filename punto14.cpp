#include <iostream>

using namespace std;
void llenarMatriz(int** matriz,int n);
void rotarMatriz(int** matriz, int n);
void imprimirMatriz(int** matriz,int n);

void problema14(){
    int n =5;
    int **pMatriz;
    pMatriz = new int* [n];

    for (int i = 0; i <n; i++) {
        pMatriz[i] = new int[n];
    }

    llenarMatriz(pMatriz,n);

    cout << "Matriz original:" << endl;
    imprimirMatriz(pMatriz,n);

    cout << "Matriz rotada 90 grados:" << endl;
    rotarMatriz(pMatriz,n);
    imprimirMatriz(pMatriz,n);

    cout << "Matriz rotada 180 grados:" << endl;
    rotarMatriz(pMatriz,n);
    imprimirMatriz(pMatriz,n);

    cout << "Matriz rotada 270 grados:" << endl;
    rotarMatriz(pMatriz,n);
    imprimirMatriz(pMatriz,n);

    for (int i = 0; i < n; i++) {
        delete[] pMatriz[i];
    }
    delete[] pMatriz;
    pMatriz = nullptr;

}

void llenarMatriz(int** matriz,int n) {
    int valor = 1;

    for (int fila = 0; fila < n; ++fila) {
        for (int columna = 0; columna < n; ++columna) {
            //matriz[fila][columna]= valor++;
            *(*(matriz+columna)+fila) = valor++;
        }
    }
}

void rotarMatriz(int** matriz, int n) {
    int temp[n][n];

    for (int fila = 0; fila < n; ++fila) {
        for (int columna = 0; columna < n; ++columna) {
            //temp[fila][columna] = matriz[columna][n - 1 - fila];
            temp[fila][columna] =*(*(matriz+columna)+(n-1-fila));
        }
    }
    for (int fila = 0; fila < n; ++fila) {
        for (int columna = 0; columna < n; ++columna) {
            *(*(matriz+columna)+fila) = *(*(temp+columna)+fila);
        }
    }
}

void imprimirMatriz(int** matriz,int n){
    for(int x=0;x<n;x++){
        for(int z=0; z<n;z++){
            cout << *(*(matriz+z)+x)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
