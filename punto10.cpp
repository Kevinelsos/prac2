#include <iostream>

using namespace std;
int valorR(char roman);

void problema10() {
    int tam = 100;

    char *romano = new char[tam + 1];

    cout << "Ingrese el numero romano: ";
    cin.getline(romano, tam + 1);

    int i=0, repe = 1, aro = 0;
    while(*(romano+i) != '\0'){
        int actual = valorR(*(romano+i));
        int siguiente = valorR(*(romano+i+1));

        if(actual == -1){
            cout << "Numero invalido."<<endl;
            delete [] romano;
            return;
        }

        if(i> 0 && actual == valorR(*(romano+i-1))){
            repe++;
        }
        else repe =1;

        if((actual == 1 || actual == 10 || actual == 100 || actual == 1000) && repe > 3){
            cout << "Numero invalido."<<endl;
            delete [] romano;
            return;
        }

        if((actual == 5 || actual == 50 || actual == 500) && repe > 1){
            cout << "Numero invalido."<<endl;
            delete [] romano;
            return;
        }

        if(siguiente > actual){
            if((actual == 1 && (siguiente == 5 || siguiente == 10)) ||
                (actual == 10 && (siguiente == 50 || siguiente == 100)) ||
                (actual == 100 && (siguiente == 500 || siguiente == 1000))){
                aro += (siguiente - actual);
                i+=2;
                continue;
            }
            else {
                cout << "Numero invalido."<<endl;
                delete [] romano;
                return;
            }
        }
        aro +=actual;
        i++;
    }
    cout <<"El numero romano corresponde al numero: "<< aro <<endl;
    delete [] romano;
    return;

}

int valorR(char roman){
    switch (roman){
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default:  return -1;
    }
}
