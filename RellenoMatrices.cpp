#include <iostream>
using namespace std;
int main()
{
   char juego_rapido_J1[4][4]={0};
    char juego_rapido_J2[4][4]={0};

   char juego_largo_J1[8][8]={0};
   char juego_largo_J2[8][8]={0};
   
   
       int n1 = 1, n2 = 1;
       int fila, columna, opcion;

    cout << " DIFICULTAD " << endl;
    cout << "1. Facil (4x4)" << endl;
    cout << "2. Dificil (8x8)" << endl;
    cin >> opcion;

    if (opcion == 1){
    //Declaracion de las matrices en 0   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            juego_rapido_J1[i][j] = '0';
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            juego_rapido_J2[i][j] = '0';
        }
    }
    
    
    //Mapa original
        cout << "JUGADOR 1. El mapa original es:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
 
            cout <<" | " <<juego_rapido_J1[i][j] << " | ";
        }
        cout << endl;
    }
    
    //Ingreso de las posiciones del jugador
    cout << "JUGADOR 1. Ingrese  las posiciones de sus cuatro barcos: " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Posicion del barco " << n1++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        if (fila >= 0 && fila < 4 && columna >= 0 && columna < 4) {
            juego_rapido_J1[fila][columna] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante
    cout << "Este es su nuevo mapa (x = barco):" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout <<" | " <<juego_rapido_J1[i][j] << " | ";
        }
        cout << endl;
    }

    //Mapa original J2
        cout << "JUGADOR 2. El mapa original es:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
 
            cout <<" | " <<juego_rapido_J2[i][j] << " | ";
        }
        cout << endl;
    }
    //Ingreso de las posiciones del jugador
    cout << "JUGADOR 2. Ingrese  las posiciones de sus cuatros barcos: " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Posicion del barco " << n2++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        if (fila >= 0 && fila < 4 && columna >= 0 && columna < 4) {
            juego_rapido_J2[fila][columna] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante
    cout << "JUGADOR 2. Este es su nuevo mapa (x = barco):" << endl;
    for (int i = 0; i< 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout <<" | " <<juego_rapido_J2[i][j] << " | ";
        }
        cout << endl;
    }

    } else if (opcion == 2){
    
    //Declaracion de las matrices en 0
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            juego_largo_J1[i][j] = '0';
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            juego_largo_J2[i][j] = '0';
        }
    }

    //Mapa original
        cout << "JUGADOR 1. El mapa original es:" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            cout <<" | " <<juego_largo_J1[i][j] << " | ";
        }
        cout << endl;
    }
    
    //Ingreso de las posiciones del jugador 1
    cout << "Ingrese  las posiciones de sus cuatros barcos: " << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "Posicion del barco " << n1++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        if (fila >= 0 && fila < 8 && columna >= 0 && columna < 8) {
            juego_largo_J1[fila][columna] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante jugador 1
    cout << "JUGADOR 1. Este es su nuevo mapa (x = barco):" << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout <<" | " <<juego_largo_J1[i][j] << " | ";
        }
        cout << endl;
    }
    //Mapa original jugador 2
        cout << "JUGADOR 2. El mapa original es:" << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
            cout <<" | " <<juego_largo_J2[i][j] << " | ";
        }
        cout << endl;
    }
    
    //Ingreso de las posiciones del jugador 1
    cout << "Ingrese  las posiciones de sus cuatros barcos: " << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "Posicion del barco " << n2++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        if (fila >= 0 && fila < 8 && columna >= 0 && columna < 8) {
            juego_largo_J2[fila][columna] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante jugador 1
    cout << "JUGADOR 1. Este es su nuevo mapa (x = barco):" << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout <<" | " <<juego_largo_J2[i][j] << " | ";
        }
        cout << endl;
    }
    }
    
return 0;
}