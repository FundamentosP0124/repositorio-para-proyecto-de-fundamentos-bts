#include <iostream>

using namespace std;

int main() {

    int juego_rapido[4][4]={};
    int juego_largo[8][8]={};

    int valor_de_inicio_matriz = 10;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            juego_rapido[i][j] = valor_de_inicio_matriz;
            valor_de_inicio_matriz++;
        }
    }

    cout << "La matriz 4x4 es:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
 
            cout <<" |" <<juego_rapido[i][j] << "| ";
        }
        cout << endl;
    }

cout<<endl;

    valor_de_inicio_matriz = 10;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            juego_largo[i][j] = valor_de_inicio_matriz;
            valor_de_inicio_matriz++;
        }
    }

    cout << "La matriz 8x8 es:" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
 
            cout <<" |" <<juego_largo[i][j] << "| ";
        }
        cout << endl;
    }

    return 0;
}