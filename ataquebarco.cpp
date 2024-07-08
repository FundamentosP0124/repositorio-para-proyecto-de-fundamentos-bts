#include <iostream>
using namespace std;
int main()
{
   char juego_rapido_J1[4][4]={0};
   char juego_rapido_J2[4][4]={0};

   char juego_largo_J1[8][8]={0};
   char juego_largo_J2[8][8]={0};
   
   
       int n1 = 1, n2 = 1;
       int fila_inicial, columna_inicial, fila_ataque, columna_ataque, opcion;

    cout << " DIFICULTAD " << endl;
    cout << "1. Facil (4x4)" << endl;
    cout << "2. Dificil (8x8)" << endl;
    cin >> opcion;

    if (opcion == 1){
    //Declaracion de las matrices en 0   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            juego_rapido_J1[i][j] = '.';
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            juego_rapido_J2[i][j] = '.';
        }
    }
    
    
    //Mapa original
    cout << "JUGADOR 1, "  << ". El mapa original es:" << endl;
    cout << "      0      1      2      3 " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i << "  ";
        for (int j = 0; j < 4; j++) {
            cout << " | " << juego_rapido_J1[i][j] << " | ";
        }
        cout << endl;
    }

    
    //Ingreso de las posiciones del jugador 1
    cout << "JUGADOR 1. Ingrese  las posiciones de sus cuatro barcos: " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Posicion del barco " << n1++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila_inicial;
        cout << "Columna: ";
        cin >> columna_inicial;
        if (fila_inicial >= 0 && fila_inicial < 4 && columna_inicial >= 0 && columna_inicial < 4) {
            juego_rapido_J1[fila_inicial][columna_inicial] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante J1
    cout << "Este es su nuevo mapa (x = barco):" << endl;

    cout << "      0      1      2      3 " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 4; ++j) {
            cout <<" | " <<juego_rapido_J1[i][j] << " | ";
        }
        cout << endl;
    }



    //Mapa original J2
        cout << "JUGADOR 2. El mapa original es:" << endl;
    
    cout << "      0      1      2      3 " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i << "  ";
        for (int j = 0; j < 4; j++) {
 
            cout <<" | " <<juego_rapido_J2[i][j] << " | ";
        }
        cout << endl;
    }
    
    
    //Ingreso de las posiciones del jugador 2
    cout << "JUGADOR 2. Ingrese  las posiciones de sus cuatros barcos: " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Posicion del barco " << n2++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila_inicial;
        cout << "Columna: ";
        cin >> columna_inicial;
        if (fila_inicial >= 0 && fila_inicial < 4 && columna_inicial >= 0 && columna_inicial < 4) {
            juego_rapido_J2[fila_inicial][columna_inicial] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante J2
    cout << "JUGADOR 2. Este es su nuevo mapa (x = barco):" << endl;
   
    cout << "      0      1      2      3 " << endl;
    for (int i = 0; i< 4; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 4; ++j) {
            cout <<" | " <<juego_rapido_J2[i][j] << " | ";
        }
        cout << endl;
    }

    cout << "------ATAQUES-----" << endl;
    cout << "JUGADOR 1. Ingrese las coordenadas que quiere atacar: " << endl;
    cout << "Fila: ";
    cin >> fila_ataque;
    cout << "Columna: ";
    cin >> columna_ataque;

    if (fila_ataque >= 0 && fila_ataque < 4 && columna_ataque >= 0 && columna_ataque < 4) {
        if (juego_rapido_J2[fila_ataque][columna_ataque] == 'x') {
            cout << "¡Felicidades, hundiste el barco de!" << endl;
            juego_rapido_J2[fila_ataque][columna_ataque] = '0'; // Cambiar el valor para reflejar que fue adivinado
        } else {
            cout << "Esa posición ya fue atacada o es incorrecta." << endl;
        }
    } else {
        cout << "Posición fuera de los límites de la matriz." << endl;
    }

    cout << "JUGADOR 2. Ingrese las coordenadas que quiere atacar: " << endl;
    cout << "Fila: ";
    cin >> fila_ataque;
    cout << "Columna: ";
    cin >> columna_ataque;

    if (fila_ataque >= 0 && fila_ataque < 4 && columna_ataque >= 0 && columna_ataque < 4) {
        if (juego_rapido_J1[fila_ataque][columna_ataque] == 'x') {
            cout << "¡Felicidades, hundiste el barco de !" << endl;
            juego_rapido_J1[fila_ataque][columna_ataque] = '0'; // Cambiar el valor para reflejar que fue adivinado
        } else {
            cout << "Esa posición ya fue atacada o es incorrecta." << endl;
        }
    } else {
        cout << "Posición fuera de los límites de la matriz." << endl;
    }

    cout << "MATRICES RESULTANTES"<< endl;
    
    cout << "J1.Matriz después del ataque:" << endl;
    cout << "      0      1      2      3 " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 4; ++j) {
            cout << " | " << juego_rapido_J1[i][j] << " | ";
        }
        cout << endl;
    }

    cout << "J2. Matriz después del ataque:" << endl;
    cout << "      0      1      2      3 " << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 4; ++j) {
            cout << " | " << juego_rapido_J2[i][j] << " | ";
        }
        cout << endl;
    }



    } else if (opcion == 2){
    
    //Declaracion de las matrices en 0
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            juego_largo_J1[i][j] = '.';
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            juego_largo_J2[i][j] = '.';
        }
    }

    //Mapa original
        cout << "JUGADOR 1. El mapa original es:" << endl;
    
    cout << "      0      1      2      3      4      5      6      7" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << "  ";
        for (int j = 0; j < 8; j++) {
            cout <<" | " <<juego_largo_J1[i][j] << " | ";
        }
        cout << endl;
    }
    
    //Ingreso de las posiciones del jugador 1
    cout << "Ingrese  las posiciones de sus ocho barcos: " << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "Posicion del barco " << n1++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila_inicial;
        cout << "Columna: ";
        cin >> columna_inicial;
        if (fila_inicial >= 0 && fila_inicial < 8 && columna_inicial >= 0 && columna_inicial < 8) {
            juego_largo_J1[fila_inicial][columna_inicial] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante jugador 1
    cout << "JUGADOR 1. Este es su nuevo mapa (x = barco):" << endl;
    
    cout << "      0      1      2      3      4      5      6      7" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 8; ++j) {
            cout <<" | " <<juego_largo_J1[i][j] << " | ";
        }
        cout << endl;
    }

  
    //Mapa original jugador 2
        cout << "JUGADOR 2. El mapa original es:" << endl;
    
    cout << "      0      1      2      3      4      5      6      7" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i << "  ";
        for (int j = 0; j < 8; j++) {
            
            cout <<" | " <<juego_largo_J2[i][j] << " | ";
        }
        cout << endl;
    }
    
    //Ingreso de las posiciones del jugador 2
    cout << "Ingrese  las posiciones de sus cuatros barcos: " << endl;
    for (int i = 0; i < 8; ++i) {
        cout << "Posicion del barco " << n2++ << ": " << endl;
        cout << "Fila: ";
        cin >> fila_inicial;
        cout << "Columna: ";
        cin >> columna_inicial;
        if (fila_inicial >= 0 && fila_inicial < 8 && columna_inicial >= 0 && columna_inicial < 8) {
            juego_largo_J2[fila_inicial][columna_inicial] = 'x';
        } else {
            cout << "Posición inválida. Intente de nuevo la ultima posicion." << endl;
            --i;
    }
    }
    
    //Mapa resultante jugador 2
    cout << "JUGADOR 2. Este es su nuevo mapa (x = barco):" << endl;
    
    cout << "      0      1      2      3      4      5      6      7" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 8; ++j) {
            cout <<" | " <<juego_largo_J2[i][j] << " | ";
        }
        cout << endl;
    }
    }

    cout << "------ATAQUES-----" << endl;
    cout << "JUGADOR 1. Ingrese las coordenadas que quiere atacar: " << endl;
    cout << "Fila: ";
    cin >> fila_ataque;
    cout << "Columna: ";
    cin >> columna_ataque;

    if (fila_ataque >= 0 && fila_ataque < 8 && columna_ataque >= 0 && columna_ataque < 8) {
        if (juego_largo_J2[fila_ataque][columna_ataque] == 'x') {
            cout << "¡Felicidades, hundiste el barco de!" << endl;
            juego_largo_J2[fila_ataque][columna_ataque] = '0'; // Cambiar el valor para reflejar que fue adivinado
        } else {
            cout << "Esa posición ya fue atacada o es incorrecta." << endl;
        }
    } else {
        cout << "Posición fuera de los límites de la matriz." << endl;
    }

    cout << "JUGADOR 2. Ingrese las coordenadas que quiere atacar: " << endl;
    cout << "Fila: ";
    cin >> fila_ataque;
    cout << "Columna: ";
    cin >> columna_ataque;

    if (fila_ataque >= 0 && fila_ataque < 8 && columna_ataque >= 0 && columna_ataque < 8) {
        if (juego_largo_J1[fila_ataque][columna_ataque] == 'x') {
            cout << "¡Felicidades, hundiste el barco de !" << endl;
            juego_largo_J1[fila_ataque][columna_ataque] = '0'; // Cambiar el valor para reflejar que fue adivinado
        } else {
            cout << "Esa posición ya fue atacada o es incorrecta." << endl;
        }
    } else {
        cout << "Posición fuera de los límites de la matriz." << endl;
    }

    cout << "MATRICES RESULTANTES"<< endl;
    
    cout << "J1.Matriz después del ataque:" << endl;
    cout << "      0      1      2      3      4      5      6      7" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 8; ++j) {
            cout << " | " << juego_largo_J1[i][j] << " | ";
        }
        cout << endl;
    }

    cout << "J2. Matriz después del ataque:" << endl;
    cout << "      0      1      2      3      4      5      6      7" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 8; ++j) {
            cout << " | " << juego_largo_J2[i][j] << " | ";
        }
        cout << endl;
    }

    
return 0;
}