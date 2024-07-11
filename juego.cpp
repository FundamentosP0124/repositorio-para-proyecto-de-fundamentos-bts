#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Usuario
{
    string nombre = "";
    int puntaje = 0;
};

void logo_funcion() {
    cout << "   ___  ______   _______     _  _____ _   _____   __ " << endl;
    cout << "  / _ |/ __/ /  / __/ _ |   / |/ / _ | | / / _ | / / " << endl;
    cout << " / ___/ _// /__/ _// __ |  /    / __ | |/ / __ |/ /__" << endl;
    cout << "/_/  /___/____/___/_/ |_| /_/|_/_/ |_|___/_/ |_/____/" << endl;
    cout << endl;
}



int main()
{

    int eleccion_del_usuario_en_el_menu = 0, eleccion_del_modo_de_juego = 0, eleccion_del_tamanio_de_cuadricula = 0, fila[8] = {}, columna[8] = {}, fila_inicial [8]={}, columna_inicial[8]={}, opcion=0;

    char juego_rapido_COM[4][4] = {0};
    char juego_largo_COM[8][8] = {0};

    char juego_rapido_J1[4][4] = {0};
    char juego_rapido_J2[4][4] = {0};

    char juego_largo_J1[8][8] = {0};
    char juego_largo_J2[8][8] = {0};

    char juego_rapido_J1_sin_barcos[4][4] = {0};
    char juego_rapido_J2_sin_barcos[4][4] = {0};

    char juego_largo_J1_sin_barcos[8][8] = {0};
    char juego_largo_J2_sin_barcos[8][8] = {0};

    int n1 = 1, n2 = 1, rondas = 1,  fila_ataque=0, columna_ataque=0;




    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            juego_rapido_J1_sin_barcos[i][j] = '.';
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            juego_rapido_J2_sin_barcos[i][j] = '.';
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            juego_largo_J1_sin_barcos[i][j] = '.';
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            juego_largo_J2_sin_barcos[i][j] = '.';
        }
    }


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            juego_rapido_J1[i][j] = '.';
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            juego_rapido_J2[i][j] = '.';
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            juego_largo_J1[i][j] = '.';
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            juego_largo_J2[i][j] = '.';
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            juego_rapido_COM[i][j] = '.';
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            juego_largo_COM[i][j] = '.';
        }
    }
    do
    {

 logo_funcion();

        cout << "1. Jugar\n2. Ayuda\n3. Creditos\n4. Salir\n\n";
        cout << "Escriba el numero de su opcion aqui: ";
        cin >> eleccion_del_usuario_en_el_menu;
        cout << endl;

        switch (eleccion_del_usuario_en_el_menu)
        {
        case 1:
            do
            {
                cout << "\t---Elija el modo de juego---\n\n";
                cout << "1. Jugador vs COM\n2. Jugador vs jugador\n\n";
                cout << "Escriba el numero su opcion aqui: ";
                cin >> eleccion_del_modo_de_juego;
                cout << endl;

                if (eleccion_del_modo_de_juego == 1 || eleccion_del_modo_de_juego == 2)
                {
                    do
                    {
                        cout << "\t---Elija el tamanio de caudricula---\n\n";
                        cout << "1. Cuadricula 4x4 (Modo rapido con 4 barcos por bando)\n2. Cuadricula 8x8 (Modo largo con 8 barcos por bando)\n\n";
                        cout << "Escriba el numero de su opcion aqui: ";
                        cin >> eleccion_del_tamanio_de_cuadricula;
                        cout << endl;

                        if ((eleccion_del_modo_de_juego == 1) && (eleccion_del_tamanio_de_cuadricula == 1))
                        {
                            cout << "Escribe un nombre para tu equipo: ";
                            Usuario usuario1;
                            cin >> usuario1.nombre;
                            cout << endl;
                            cout << "JUGADOR 1, " << usuario1.nombre << ". El mapa original es:" << endl;
                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 4; j++)
                                {

                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "JUGADOR 1, " << usuario1.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                            for (int i = 0; i < 4; ++i)
                            {
                                cout << "Posicion del barco " << n1++ << ": " << endl;
                                cout << "Fila: ";
                                cin >> fila[i];
                                cout << "Columna: ";
                                cin >> columna[i];
                                if ((fila[i] >= 0) && (fila[i] < 4) && (columna[i] >= 0) && (columna[i] < 4) && (fila[i] != fila[i - 1] || columna[i] != columna[i - 1]) && (fila[i] != fila[i - 2] || columna[i] != columna[i - 2]) && (fila[i] != fila[i - 3] || columna[i] != columna[i - 3]))

                                {
                                    juego_rapido_J1[fila[i]][columna[i]] = 'x';
                                }
                                else
                                {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n1;
                                }
                            }

                            // Mapa resultante jugador 1
                            cout << usuario1.nombre << ", este es su nuevo mapa (x = barco):" << endl;
                            for (int i = 0; i < 4; ++i)
                            {
                                for (int j = 0; j < 4; ++j)
                                {
                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            srand(time(0));

                            for (int i = 0; i < 4; ++i)
                            {

                                fila[i] = rand() % 4;

                                columna[i] = rand() % 4;

                                if ((fila[i] >= 0) && (fila[i] < 4) && (columna[i] >= 0) && (columna[i] < 4) && (fila[i] != fila[i - 1] || columna[i] != columna[i - 1]) && (fila[i] != fila[i - 2] || columna[i] != columna[i - 2]) && (fila[i] != fila[i - 3] || columna[i] != columna[i - 3]))
                                {
                                    juego_rapido_COM[fila[i]][columna[i]] = 'x';
                                }
                                else
                                {
                                    --i;
                                }
                            }

                            cout << "Mapa de la COM (x = barco):" << endl;
                            for (int i = 0; i < 4; ++i)
                            {
                                for (int j = 0; j < 4; ++j)
                                {
                                    cout << " | " << juego_rapido_COM[i][j] << " | ";
                                }
                                cout << endl;
                            }
                        }

                        else if ((eleccion_del_modo_de_juego == 1) && (eleccion_del_tamanio_de_cuadricula == 2))
                        {
                            cout << "Escribe el nombre del equipo del jugador 1: ";
                            Usuario usuario1;
                            cin >> usuario1.nombre;
                            cout << "JUGADOR 1, " << usuario1.nombre << ". El mapa original es:" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {

                                    cout << " | " << juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            // Ingreso de las posiciones del jugador 1
                            cout << "JUGADOR 1, " << usuario1.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                            for (int i = 0; i < 8; ++i)
                            {
                                cout << "Posicion del barco " << n1++ << ": " << endl;
                                cout << "Fila: ";
                                cin >> fila[i];
                                cout << "Columna: ";
                                cin >> columna[i];
                                if ((fila[i] >= 0) && (fila[i] < 8) && (columna[i] >= 0) && (columna[i] < 8) && (fila[i] != fila[i - 1] || columna[i] != columna[i - 1]) && (fila[i] != fila[i - 2] || columna[i] != columna[i - 2]) && (fila[i] != fila[i - 3] || columna[i] != columna[i - 3]) && (fila[i] != fila[i - 4] || columna[i] != columna[i - 4]) && (fila[i] != fila[i - 5] || columna[i] != columna[i - 5]) && (fila[i] != fila[i - 6] || columna[i] != columna[i - 6]) && (fila[i] != fila[i - 7] || columna[i] != columna[i - 7]))
                                {
                                    juego_largo_J1[fila[i]][columna[i]] = 'x';
                                }
                                else
                                {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n1;
                                }
                            }

                            // Mapa resultante jugador 1
                            cout << usuario1.nombre << ". Este es su nuevo mapa (x = barco):" << endl;
                            for (int i = 0; i < 8; ++i)
                            {
                                for (int j = 0; j < 8; ++j)
                                {
                                    cout << " | " << juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            srand(time(0));
                            for (int i = 0; i < 8; ++i)
                            {

                                fila[i] = rand() % 8;

                                columna[i] = rand() % 8;

                                if ((fila[i] >= 0) && (fila[i] < 8) && (columna[i] >= 0) && (columna[i] < 8) && (fila[i] != fila[i - 1] || columna[i] != columna[i - 1]) && (fila[i] != fila[i - 2] || columna[i] != columna[i - 2]) && (fila[i] != fila[i - 3] || columna[i] != columna[i - 3]) && (fila[i] != fila[i - 4] || columna[i] != columna[i - 4]) && (fila[i] != fila[i - 5] || columna[i] != columna[i - 5]) && (fila[i] != fila[i - 6] || columna[i] != columna[i - 6]) && (fila[i] != fila[i - 7] || columna[i] != columna[i - 7]))
                                {
                                    juego_largo_COM[fila[i]][columna[i]] = 'x';
                                }
                                else
                                {
                                    --i;
                                }
                            }
                            cout << "Mapa de la COM (x = barco):" << endl;
                            for (int i = 0; i < 8; ++i)
                            {
                                for (int j = 0; j < 8; ++j)
                                {
                                    cout << " | " << juego_largo_COM[i][j] << " | ";
                                }
                                cout << endl;
                            }
                        }

                        else if ((eleccion_del_modo_de_juego == 2) && (eleccion_del_tamanio_de_cuadricula == 1))
                        {
                            cout << "Escribe el nombre del equipo del jugador 1: ";
                            Usuario usuario1;
                            cin >> usuario1.nombre;

                            cout << "Escribe el nombre del equipo del jugador 2: ";
                            Usuario usuario2;
                            cin >> usuario2.nombre;

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". El mapa original es:" << endl;
                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                           for (int i = 0; i < 4; ++i)
                            {
                                cout << "Posicion del barco " << n1++ << ": " << endl;
                                cout << "Fila: ";
                                cin >> fila_inicial[i];
                                cout << "Columna: ";
                                cin >> columna_inicial[i];

                                if ((fila_inicial[i] >= 0) && (fila_inicial[i] < 4) && (columna_inicial[i] >= 0) && (columna_inicial[i] < 4) && (fila_inicial[i] != fila_inicial[i - 1] || columna_inicial[i] != columna_inicial[i - 1]) && (fila_inicial[i] != fila_inicial[i - 2] || columna_inicial[i] != columna_inicial[i - 2]) && (fila_inicial[i] != fila_inicial[i - 3] || columna_inicial[i] != columna_inicial[i - 3]))
                                {
                                    juego_rapido_J1[fila_inicial[i]][columna_inicial[i]] = 'x';
                                }
                                else
                                {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n1;
                                }
                            }
                           

                            // Mapa resultante jugador 1
                            cout << "JUGADOR 1 - " << usuario1.nombre << ". este es su nuevo mapa (x = barco):" << endl;
                            cout << "      0      1      2      3 " << endl;
                            for (int i = 0; i < 4; ++i){
                            cout << i << "  ";
                                for (int j = 0; j < 4; ++j){
                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

        
                           logo_funcion();
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". El mapa original es:" << endl;
                            cout << "      0      1      2      3 " << endl;
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }
                            // Ingreso de las posiciones del jugador
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                            for (int i = 0; i < 4; ++i){
                                cout << "Posicion del barco " << n2++ << ": " << endl;
                                cout << "Fila: ";
                                cin >> fila_inicial[i];
                                cout << "Columna: ";
                                cin >> columna_inicial[i];
                                if ((fila_inicial[i] >= 0) && (fila_inicial[i] < 4) && (columna_inicial[i] >= 0) && (columna_inicial[i] < 4) && (fila_inicial[i] != fila_inicial[i - 1] || columna_inicial[i] != columna_inicial[i - 1]) && (fila_inicial[i] != fila_inicial[i - 2] || columna_inicial[i] != columna_inicial[i - 2]) && (fila_inicial[i] != fila_inicial[i - 3] || columna_inicial[i] != columna_inicial[i - 3]))
                                {
                                    juego_rapido_J2[fila_inicial[i]][columna_inicial[i]] = 'x';
                                }
                                else
                                {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n2;
                                }
                            }

                            // Mapa resultante
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Este es su nuevo mapa (x = barco):" << endl;
                            cout << "      0      1      2      3 " << endl;
                            for (int i = 0; i < 4; ++i){
                            cout << i << "  ";
                                for (int j = 0; j < 4; ++j)
                                {
                                    cout << " | " << juego_rapido_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }



                            do{
                                logo_funcion();
                            cout<<endl;

                            cout << "------RONDA " << rondas++ << "-----" << endl; 
                            cout<<"Mapa del enemigo: \n\n";
                           
                           
                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }
                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                            cout << "Fila: ";
                            cin >> fila_ataque;
                            cout << "Columna: ";
                            cin >> columna_ataque;

                            if (fila_ataque >= 0 && fila_ataque < 4 && columna_ataque >= 0 && columna_ataque < 4) {
                                if ((juego_rapido_J2[fila_ataque][columna_ataque] == 'x')&&(juego_rapido_J2[fila_ataque][columna_ataque]!='0')) {
                                    cout << "¡Felicidades, hundiste el barco de " << usuario2. nombre << "!"<< endl; 
                                    usuario1.puntaje++;
                                    cout << "Tienes " << usuario1.puntaje<< " puntos." << endl; 
                                    juego_rapido_J2[fila_ataque][columna_ataque] = '0';
                                    juego_rapido_J2_sin_barcos[fila_ataque][columna_ataque] = '0'; 
                                    cout << endl;

                                    

                                    cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;


                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }



                                } else {
                                    if (juego_rapido_J2[fila_ataque][columna_ataque]!='0')
                                    {
                                    juego_rapido_J2_sin_barcos[fila_ataque][columna_ataque] = '*';
                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<endl;
                                    }
                                    

                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;


                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }


                                }
                            } else {
                                cout << "Posición fuera de los límites de la matriz." << endl;
                            }


                         logo_funcion();
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                            cout<<"Mapa del enemigo: \n\n";
                           
                           
                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "Fila: ";
                            cin >> fila_ataque;
                            cout << "Columna: ";
                            cin >> columna_ataque;

                            if (fila_ataque >= 0 && fila_ataque < 4 && columna_ataque >= 0 && columna_ataque < 4) {
                                if ((juego_rapido_J1[fila_ataque][columna_ataque] == 'x')&&(juego_rapido_J1[fila_ataque][columna_ataque]!='0')) {
                                    cout << "¡Felicidades, hundiste un barco de "<<usuario1.nombre<<"!" << endl; 
                                    usuario2.puntaje++;
                                    cout << "Tienes " << usuario2.puntaje << " puntos." << endl; 
                                    juego_rapido_J1[fila_ataque][columna_ataque] = '0';
                                    juego_rapido_J1_sin_barcos[fila_ataque][columna_ataque] = '0'; 
                                    cout << endl;

                                    cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;


                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }
                                    
                                } else {
                                    if (juego_rapido_J1[fila_ataque][columna_ataque]!='0')
                                    {
                                    juego_rapido_J1_sin_barcos[fila_ataque][columna_ataque] = '*';
                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<endl;
                                    }
                                    

                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;




                            cout << "      0      1      2      3 " << endl;    
                            for (int i = 0; i < 4; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++){
                                    cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }


                                }
                            } else {
                                cout << "Posición fuera de los límites de la matriz." << endl;
                            }



                            
                            }while(usuario1.puntaje < 4 && usuario2.puntaje < 4 ); 
                            
                            if (usuario1.puntaje == 4){
                                cout << "¡Felicidades " << usuario1.nombre <<  ", has ganado!"<<endl;
                            } else if (usuario2.puntaje == 4) {
                                cout << "¡Felicidades " << usuario2.nombre <<  ", has ganado!"<<endl;
                            } 



                            
                            cout << "RESULTADOS"<< endl; 
    
                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Esta es su flota después del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3" << endl;
                            for (int i = 0; i < 4; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 4; j++) {
                                cout <<" | " <<juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Esta es su flota después del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3" << endl;
                            for (int i = 0; i < 4; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 4; j++) {
                                cout <<" | " <<juego_rapido_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }


                        }  else if ((eleccion_del_modo_de_juego == 2) && (eleccion_del_tamanio_de_cuadricula == 2))
                        {
                            cout << "Escribe el nombre del equipo del jugador 1: ";
                            Usuario usuario1;
                            cin >> usuario1.nombre;

                            cout << "Escribe el nombre del equipo del jugador 2: ";
                            Usuario usuario2;
                            cin >> usuario2.nombre;
                        

                            cout << "JUGADOR 1, " << usuario1.nombre << ". El mapa original es:" << endl;
                            
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 8; j++) {
                                cout <<" | " <<juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }


                            
                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                            for (int i = 0; i < 8; ++i)
                            {
                                cout << "Posicion del barco " << n1++ << ": " << endl;
                                cout << "Fila: ";
                                cin >> fila_inicial[i];
                                cout << "Columna: ";
                                cin >> columna_inicial[i];
                                if ((fila_inicial[i] >= 0) && (fila_inicial[i] < 8) && (columna_inicial[i] >= 0) && (columna_inicial[i] < 8) && (fila_inicial[i] != fila_inicial[i - 1] || columna_inicial[i] != columna_inicial[i - 1]) && (fila_inicial[i] != fila_inicial[i - 2] || columna_inicial[i] != columna_inicial[i - 2]) && (fila_inicial[i] != fila_inicial[i - 3] || columna_inicial[i] != columna_inicial[i - 3]) && (fila_inicial[i] != fila_inicial[i - 4] || columna_inicial[i] != columna_inicial[i - 4]) && (fila_inicial[i] != fila_inicial[i - 5] || columna_inicial[i] != columna_inicial[i - 5]) && (fila_inicial[i] != fila_inicial[i - 6] || columna_inicial[i] != columna_inicial[i - 6]) && (fila_inicial[i] != fila_inicial[i - 7] || columna_inicial[i] != columna_inicial[i - 7]))
                                {
                                    juego_largo_J1[fila_inicial[i]][columna_inicial[i]] = 'x';
                                }else {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n1;
                                }
                            }

                            
                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Este es su nuevo mapa (x = barco):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 8; j++) {
                                cout <<" | " <<juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            logo_funcion();
                            cout << "\n\n";
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". El mapa original es:" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 8; j++) {
                                cout <<" | " <<juego_largo_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            
                            cout << endl;
                            cout << "JUGADOR 2, " << usuario2.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                            for (int i = 0; i < 8; ++i)
                            {
                                cout << "Posicion del barco " << n2++ << ": " << endl;
                                cout << "Fila: ";
                                cin >> fila_inicial[i];
                                cout << "Columna: ";
                                cin >> columna_inicial[i];
                                if ((fila_inicial[i] >= 0) && (fila_inicial[i] < 8) && (columna_inicial[i] >= 0) && (columna_inicial[i] < 8) && (fila_inicial[i] != fila_inicial[i - 1] || columna_inicial[i] != columna_inicial[i - 1]) && (fila_inicial[i] != fila_inicial[i - 2] || columna_inicial[i] != columna_inicial[i - 2]) && (fila_inicial[i] != fila_inicial[i - 3] || columna_inicial[i] != columna_inicial[i - 3]) && (fila_inicial[i] != fila_inicial[i - 4] || columna_inicial[i] != columna_inicial[i - 4]) && (fila_inicial[i] != fila_inicial[i - 5] || columna_inicial[i] != columna_inicial[i - 5]) && (fila_inicial[i] != fila_inicial[i - 6] || columna_inicial[i] != columna_inicial[i - 6]) && (fila_inicial[i] != fila_inicial[i - 7] || columna_inicial[i] != columna_inicial[i - 7]))
                                {
                                    juego_largo_J2[fila_inicial[i]][columna_inicial[i]] = 'x';
                                }else{
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n2;
                                }
                            }

                            
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Este es su nuevo mapa (x = barco):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 8; j++) {
                                cout <<" | " <<juego_largo_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }
  

                            
                            do{
                            logo_funcion();
                            cout << "------RONDA " << rondas++ << "-----" << endl;

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                            cout<<"Mapa del enemigo: \n\n";
                           
                           
                            cout << "      0      1      2      3      4      5      6      7" << endl;    
                            for (int i = 0; i < 8; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++){
                                    cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "Fila: ";
                            cin >> fila_ataque;
                            cout << "Columna: ";
                            cin >> columna_ataque;

                            if (fila_ataque >= 0 && fila_ataque < 8 && columna_ataque >= 0 && columna_ataque < 8) {
                                if ((juego_largo_J2[fila_ataque][columna_ataque] == 'x')&&(juego_largo_J2[fila_ataque][columna_ataque]!='0')) {
                                    cout << "¡Felicidades, hundiste el barco de " << usuario2. nombre << "!"<< endl; 
                                    usuario1.puntaje++;
                                    cout << "Tienes " << usuario1.puntaje<< " puntos." << endl;  
                                    juego_largo_J2[fila_ataque][columna_ataque] = '0';
                                    juego_largo_J2_sin_barcos[fila_ataque][columna_ataque] = '0'; 
                                    cout << endl;

                                cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;


                            cout << "      0      1      2      3      4      5      6      7" << endl;    
                            for (int i = 0; i < 8; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++){
                                    cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }
                                    
                                } else {
                                    if (juego_largo_J2[fila_ataque][columna_ataque]!='0')
                                    {
                                    juego_largo_J2_sin_barcos[fila_ataque][columna_ataque] = '*';
                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<endl;
                                    }
                                    

                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;






                            cout << "      0      1      2      3      4      5      6      7" << endl;    
                            for (int i = 0; i < 8; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++){
                                    cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }


                                }
                            } else {
                                cout << "Posición fuera de los límites de la matriz." << endl;
                            }



                            logo_funcion();
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                            cout<<"Mapa del enemigo: \n\n";
                           
                           
                            cout << "      0      1      2      3      4      5      6      7" << endl;    
                            for (int i = 0; i < 8; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++){
                                    cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "Fila: ";
                            cin >> fila_ataque;
                            cout << "Columna: ";
                            cin >> columna_ataque;

                            if (fila_ataque >= 0 && fila_ataque < 8 && columna_ataque >= 0 && columna_ataque < 8) {
                                if ((juego_largo_J1[fila_ataque][columna_ataque] == 'x')&&(juego_largo_J1[fila_ataque][columna_ataque]!='0')) {
                                    cout << "¡Felicidades, hundiste el barco de " << usuario1. nombre << "!"<< endl; 
                                    usuario2.puntaje++;
                                    cout << "Tienes " << usuario2.puntaje<< " puntos." << endl; 
                                    juego_largo_J1[fila_ataque][columna_ataque] = '0';
                                    juego_largo_J1_sin_barcos[fila_ataque][columna_ataque] = '0'; 
                                    cout << endl;

                                cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;


                            cout << "      0      1      2      3      4      5      6      7" << endl;    
                            for (int i = 0; i < 8; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++){
                                    cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }
                                    
                                } else {
                                    if (juego_largo_J1[fila_ataque][columna_ataque]!='0')
                                    {
                                    juego_largo_J1_sin_barcos[fila_ataque][columna_ataque] = '*';
                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<endl;
                                    }
                                    

                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout<<"Este es el mapa del enemigo despues de su ataque: "<<endl;




                            cout << "      0      1      2      3      4      5      6      7" << endl;    
                            for (int i = 0; i < 8; i++){
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++){
                                    cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }


                                }
                            } else {
                                cout << "Posición fuera de los límites de la matriz." << endl;
                            }



                            }while(usuario1.puntaje < 8 && usuario2.puntaje < 8);
                            if (usuario1.puntaje == 8){
                                cout << "¡Felicidades " << usuario1.nombre <<  ", has ganado!"<<endl; 
                            } else if (usuario2.puntaje == 8) {
                                cout << "¡Felicidades " << usuario2.nombre <<  ", has ganado!"<<endl; 
                            }
                            
                            cout << "RESULTADOS"<< endl; 

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Esta es su flota despues del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 8; j++) {
                                cout <<" | " <<juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Esta es su flota despues del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++) {
                            cout << i << "  ";
                                for (int j = 0; j < 8; j++) {
                                cout <<" | " <<juego_largo_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }
                        }

                        if (eleccion_del_tamanio_de_cuadricula != 1 && eleccion_del_tamanio_de_cuadricula != 2)
                        {
                            cout << "Por favor escoja una opcion valida.\n\n";
                        }
                    } while (eleccion_del_tamanio_de_cuadricula != 1 && eleccion_del_tamanio_de_cuadricula != 2);
                }
                else
                {
                    cout << "Por favor escoja una opcion valida.\n\n";
                }
            } while (eleccion_del_modo_de_juego != 1 && eleccion_del_modo_de_juego != 2);

            break;

        case 2:
            cout << "Aca van las instrucciones del jueguito";
            break;

        case 3:
            cout << "\tFUNDAMENTOS DE PROGRAMACION\n\t\tCICLO 01\n\tCATEDRATICA ING. ELISA ALDANA\n\t\tJUEGO HECHO POR:\n\t\tJULIO FLORES\n\t\tJOHNNY ARTEAGA\n\t\tANDREA ALVAREZ";
            break;

        case 4:
            cout << "Ha salido del juego";
            break;

        default:
            cout << "Por favor escoger una opcion valida\n\n";
            break;
        }

    } while ((eleccion_del_usuario_en_el_menu > 4) || (eleccion_del_usuario_en_el_menu < 1));

    return 0;
}