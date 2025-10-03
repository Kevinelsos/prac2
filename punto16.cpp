#include <iostream>

using namespace std;

void calcularCaminos(int fila,int columna,int n,int *total) {
        if(columna+1<n)calcularCaminos(fila,columna+1,n,total);
        if(fila+1<n)calcularCaminos(fila+1,columna,n,total);
        if(fila == columna && fila == n-1) *total = *total+1;
    }

    void problema16(){
        int n;
        int total=0;
        cout<<"ingrese el tamanio de la malla nxn: "<<endl;
        cin>>n;
        calcularCaminos(0,0,n+1,&total);
        cout<<"el total de caminos es: "<<total<<endl;
    }

