#include <iostream>
using namespace std;
int main()
{
   char juego_rapido[4][4]={0};
   char juego_largo[8][8]={0};
   
       int n = 1;
       int fila, columna;

    //Declaracion de matriz en 0   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            juego_rapido[i][j] = '0';
        }
    }
    
    //Mapa original
        cout << "El mapa original es:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
 
            cout <<" | " <<juego_rapido[i][j] << " | ";
        }
        cout << endl;
    }
    
    //Ingreso de las posiciones del jugador
    cout << "Ingrese  las posiciones de sus cuatros barcos: " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Posicion del barco " << n++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        if (fila >= 0 && fila < 4 && columna >= 0 && columna < 4) {
            juego_rapido[fila][columna] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante
    cout << "Este es su nuevo mapa (x = barco):" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout <<" | " <<juego_rapido[i][j] << " | ";
        }
        cout << endl;
    }

    
    
return 0;
}