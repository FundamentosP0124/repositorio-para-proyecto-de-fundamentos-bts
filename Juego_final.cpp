#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

struct Usuario
{
    string nombre = "";
    int puntaje = 0;
};

void logo_funcion()
{
    cout << "   ___  ______   _______     _  _____ _   _____   __ " << endl;
    cout << "  / _ |/ __/ /  / __/ _ |   / |/ / _ | | / / _ | / / " << endl;
    cout << " / ___/ _// /__/ _// __ |  /    / __ | |/ / __ |/ /__" << endl;
    cout << "/_/  /___/____/___/_/ |_| /_/|_/_/ |_|___/_/ |_/____/" << endl;
    cout << endl;
}

void creacion_archivo(); //Para crear archivo
void lectura_archivo (); //Para leer archivo
void add(Usuario usuario1, Usuario usuario2);



int main()
{

Usuario usuario1, usuario2;


    int eleccion_del_usuario_en_el_menu = 0, eleccion_del_tamanio_de_cuadricula = 0, fila[8] = {}, columna[8] = {}, fila_inicial[8] = {}, columna_inicial[8] = {}, opcion = 0;

    char juego_rapido_J1[4][4] = {0};
    char juego_rapido_J2[4][4] = {0};

    char juego_largo_J1[8][8] = {0};
    char juego_largo_J2[8][8] = {0};

    char juego_rapido_J1_sin_barcos[4][4] = {0};
    char juego_rapido_J2_sin_barcos[4][4] = {0};

    char juego_largo_J1_sin_barcos[8][8] = {0};
    char juego_largo_J2_sin_barcos[8][8] = {0};

    int n1 = 1, n2 = 1, rondas = 1, fila_ataque = 0, columna_ataque = 0;



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

    do
    {

        logo_funcion();

        cout << "1. Jugar\n2. Ayuda\n3. Creditos\n4. Salir\n5. Record de partidas\n\n";
        cout << "Escriba el numero de su opcion aqui: ";
        cin >> eleccion_del_usuario_en_el_menu;
        cout << endl;

        switch (eleccion_del_usuario_en_el_menu)
        {
        case 1:


                do
                {
                    cout << "\t---Elija el tamanio de caudricula---\n\n";
                    cout << "1. Cuadricula 4x4 (Modo rapido con 4 barcos por bando)\n2. Cuadricula 8x8 (Modo largo con 8 barcos por bando)\n\n";
                    cout << "Escriba el numero de su opcion aqui: ";
                    cin >> eleccion_del_tamanio_de_cuadricula;
                    cout << endl;

                    if (eleccion_del_tamanio_de_cuadricula == 1)
                    {
                        cout << "Escribe el nombre del equipo del jugador 1: ";
                        Usuario usuario1;
                        cin >> usuario1.nombre;

                        cout << "Escribe el nombre del equipo del jugador 2: ";
                        Usuario usuario2;
                        cin >> usuario2.nombre;

                        cout << "JUGADOR 1 - " << usuario1.nombre << ". El mapa original es:" << endl;
                        cout << "      0      1      2      3 " << endl;
                        for (int i = 0; i < 4; i++)
                        {
                            cout << i << "  ";
                            for (int j = 0; j < 4; j++)
                            {
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
                        for (int i = 0; i < 4; ++i)
                        {
                            cout << i << "  ";
                            for (int j = 0; j < 4; ++j)
                            {
                                cout << " | " << juego_rapido_J1[i][j] << " | ";
                            }
                            cout << endl;
                        }

                        logo_funcion();
                        cout << "JUGADOR 2 - " << usuario2.nombre << ". El mapa original es:" << endl;
                        cout << "      0      1      2      3 " << endl;
                        for (int i = 0; i < 4; i++)
                        {
                            cout << i << "  ";
                            for (int j = 0; j < 4; j++)
                            {
                                cout << " | " << juego_rapido_J2[i][j] << " | ";
                            }
                            cout << endl;
                        }
                        // Ingreso de las posiciones del jugador
                        cout << "JUGADOR 2 - " << usuario2.nombre << ". Ingrese  las posiciones de sus cuatro barcos: " << endl;
                        for (int i = 0; i < 4; ++i)
                        {
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
                        for (int i = 0; i < 4; ++i)
                        {
                            cout << i << "  ";
                            for (int j = 0; j < 4; ++j)
                            {
                                cout << " | " << juego_rapido_J2[i][j] << " | ";
                            }
                            cout << endl;
                        }

                        do
                        {
                            logo_funcion();
                            cout << endl;

                            cout << "\t------RONDA " << rondas++ << "------" << endl;
                            cout << "\tMapa de " << usuario2.nombre << " :" << "\n\n";

                            cout << "      0      1      2      3 " << endl;
                            for (int i = 0; i < 4; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++)
                                {
                                    cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << endl;

                            cout << "Para utilizar un bombardero cuando tengas 2 puntos colocar las cordenadas (fila: 10, columa: 10)"<<endl ;

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                            cout << "Fila: ";
                            cin >> fila_ataque;
                            cout << "Columna: ";
                            cin >> columna_ataque;

                            if (fila_ataque >= 0 && fila_ataque < 4 && columna_ataque >= 0 && columna_ataque < 4)
                            {
                                if ((juego_rapido_J2[fila_ataque][columna_ataque] == 'x') && (juego_rapido_J2[fila_ataque][columna_ataque] != '0'))
                                {
                                    cout << "¡Felicidades, hundiste el barco de " << usuario2.nombre << "!" << endl;
                                    usuario1.puntaje++;
                                    cout << "Tienes " << usuario1.puntaje << " puntos." << endl;
                                    juego_rapido_J2[fila_ataque][columna_ataque] = '0';
                                    juego_rapido_J2_sin_barcos[fila_ataque][columna_ataque] = '0';
                                    cout << endl;

                                    cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                    cout << "      0      1      2      3 " << endl;
                                    for (int i = 0; i < 4; i++)
                                    {
                                        cout << i << "  ";
                                        for (int j = 0; j < 4; j++)
                                        {
                                            cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                        }
                                        cout << endl;
                                    }
                                }
                                else
                                {
                                    if (juego_rapido_J2[fila_ataque][columna_ataque] != '0')
                                    {
                                        juego_rapido_J2_sin_barcos[fila_ataque][columna_ataque] = '*';
                                        cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                        cout << endl;
                                    }

                                    cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                    cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                    cout << "      0      1      2      3 " << endl;
                                    for (int i = 0; i < 4; i++)
                                    {
                                        cout << i << "  ";
                                        for (int j = 0; j < 4; j++)
                                        {
                                            cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                        }
                                        cout << endl;
                                    }
                                }
                            }
                            else if ((fila_ataque == 10) && (columna_ataque == 10) && (usuario1.puntaje == 2))
                            {

                                for (int i = 0; i < 2; ++i)
                                {

                                    fila[i] = rand() % 4;

                                    columna[i] = rand() % 4;

                                    if ((juego_rapido_J2[fila[i]][columna[i]] == 'x') && (juego_rapido_J2[fila[i]][columna[i]] != '0'))
                                    {
                                        juego_rapido_J2[fila[i]][columna[i]] = '0';
                                        juego_rapido_J2_sin_barcos[fila[i]][columna[i]] = '0';
                                        cout << endl;
                                    }
                                    else
                                    {
                                        if (juego_rapido_J2[fila[i]][columna[i]] != '0')
                                        {
                                            juego_rapido_J2_sin_barcos[fila[i]][columna[i]] = '*';
                                            


                                        }

                                    

                                        else
                                        {
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                            cout << "      0      1      2      3 " << endl;
                                            for (int i = 0; i < 4; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 4; j++)
                                                {
                                                    cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
                                }
                                            cout << endl;
                                            cout<<"Este es el mapa de "<<usuario2.nombre<<" Luego de tu ataque bombardero:\n\n ";
                                            cout << "      0      1      2      3 " << endl;
                                            for (int i = 0; i < 4; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 4; j++)
                                                {
                                                    cout << " | " << juego_rapido_J2_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                            }
                                else 
                                {

                                    cout << "Posición fuera de los límites de la matriz o aun no tienes los puntos necesarios para realizar un ataque bombardero" << endl;
                                }

                                logo_funcion();

                                cout << "\tMapa de " << usuario1.nombre << ":\n\n";

                                cout << "      0      1      2      3 " << endl;
                                for (int i = 0; i < 4; i++)
                                {
                                    cout << i << "  ";
                                    for (int j = 0; j < 4; j++)
                                    {
                                        cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                    }
                                    cout << endl;
                                }

                                cout << endl;

                                cout << "Para utilizar un bombardero cuando tengas 2 puntos colocar las cordenadas (fila: 10, columa: 10)"<<endl;

                                cout << "JUGADOR 2 - " << usuario2.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                                cout << "Fila: ";
                                cin >> fila_ataque;
                                cout << "Columna: ";
                                cin >> columna_ataque;

                                if (fila_ataque >= 0 && fila_ataque < 4 && columna_ataque >= 0 && columna_ataque < 4)
                                {
                                    if ((juego_rapido_J1[fila_ataque][columna_ataque] == 'x') && (juego_rapido_J1[fila_ataque][columna_ataque] != '0'))
                                    {
                                        cout << "¡Felicidades, hundiste un barco de " << usuario1.nombre << "!" << endl;
                                        usuario2.puntaje++;
                                        cout << "Tienes " << usuario2.puntaje << " puntos." << endl;
                                        juego_rapido_J1[fila_ataque][columna_ataque] = '0';
                                        juego_rapido_J1_sin_barcos[fila_ataque][columna_ataque] = '0';
                                        cout << endl;

                                        cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                        cout << "      0      1      2      3 " << endl;
                                        for (int i = 0; i < 4; i++)
                                        {
                                            cout << i << "  ";
                                            for (int j = 0; j < 4; j++)
                                            {
                                                cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                            }
                                            cout << endl;
                                        }
                                    }
                                    else
                                    {
                                        if (juego_rapido_J1[fila_ataque][columna_ataque] != '0')
                                        {
                                            juego_rapido_J1_sin_barcos[fila_ataque][columna_ataque] = '*';
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << endl;
                                        }

                                        cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                        cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                        cout << "      0      1      2      3 " << endl;
                                        for (int i = 0; i < 4; i++)
                                        {
                                            cout << i << "  ";
                                            for (int j = 0; j < 4; j++)
                                            {
                                                cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                            }
                                            cout << endl;
                                        }
                                    }
                                }
                                else if ((fila_ataque == 10) && (columna_ataque == 10) && (usuario2.puntaje==2))
                            {

                                for (int i = 0; i < 2; ++i)
                                {

                                    fila[i] = rand() % 4;

                                    columna[i] = rand() % 4;

                                    if ((juego_rapido_J1[fila[i]][columna[i]] == 'x') && (juego_rapido_J1[fila[i]][columna[i]] != '0'))
                                    {
                                        juego_rapido_J1[fila[i]][columna[i]] = '0';
                                        juego_rapido_J1_sin_barcos[fila[i]][columna[i]] = '0';
                                        cout << endl;
                                    }
                                    else
                                    {
                                        if (juego_rapido_J1[fila[i]][columna[i]] != '0')
                                        {
                                            juego_rapido_J1_sin_barcos[fila[i]][columna[i]] = '*';
                                            


                                        }

                                    

                                        else
                                        {
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                            cout << "      0      1      2      3 " << endl;
                                            for (int i = 0; i < 4; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 4; j++)
                                                {
                                                    cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
                                }
                                            cout << endl;
                                            cout<<"Este es el mapa de "<<usuario1.nombre<<" Luego de tu ataque bombardero:\n\n ";
                                            cout << "      0      1      2      3 " << endl;
                                            for (int i = 0; i < 4; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 4; j++)
                                                {
                                                    cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                            }
                                else
                                {
                                    cout << "Posición fuera de los límites de la matriz o aun no tienes los puntos necesarios para realizar un ataque bombardero" << endl;
                                }
                            }
                            while (usuario1.puntaje < 4 && usuario2.puntaje < 4);
                                

                            if (usuario1.puntaje == 4)
                            {
                                cout << "¡Felicidades " << usuario1.nombre << ", has ganado!" << endl;
                            }
                            else if (usuario2.puntaje == 4)
                            {
                                cout << "¡Felicidades " << usuario2.nombre << ", has ganado!" << endl;
                            }

                            cout << "RESULTADOS" << endl;

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Esta es su flota después del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3" << endl;
                            for (int i = 0; i < 4; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++)
                                {
                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Esta es su flota después del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3" << endl;
                            for (int i = 0; i < 4; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 4; j++)
                                {
                                    cout << " | " << juego_rapido_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }
                        }
                        else if (eleccion_del_tamanio_de_cuadricula == 2)
                        {
                            cout << "Escribe el nombre del equipo del jugador 1: ";
                            Usuario usuario1;
                            cin >> usuario1.nombre;

                            cout << "Escribe el nombre del equipo del jugador 2: ";
                            Usuario usuario2;
                            cin >> usuario2.nombre;

                            cout << "JUGADOR 1, " << usuario1.nombre << ". El mapa original es:" << endl;

                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++)
                                {
                                    cout << " | " << juego_largo_J1[i][j] << " | ";
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
                                }
                                else
                                {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n1;
                                }
                            }

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Este es su nuevo mapa (x = barco):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++)
                                {
                                    cout << " | " << juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            logo_funcion();
                            cout << "\n\n";
                            cout << "JUGADOR 2 - " << usuario2.nombre << ". El mapa original es:" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++)
                                {
                                    cout << " | " << juego_largo_J2[i][j] << " | ";
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
                                }
                                else
                                {
                                    cout << "Posicion invalida. Intente de nuevo la ultima posicion." << endl;
                                    --i;
                                    --n2;
                                }
                            }

                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Este es su nuevo mapa (x = barco):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++)
                                {
                                    cout << " | " << juego_largo_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            do
                            {
                                logo_funcion();
                                cout << "\t------RONDA " << rondas++ << "-----" << endl;

                                cout << "\tMapa de " << usuario2.nombre << ": \n\n";

                                cout << "      0      1      2      3      4      5      6      7" << endl;
                                for (int i = 0; i < 8; i++)
                                {
                                    cout << i << "  ";
                                    for (int j = 0; j < 8; j++)
                                    {
                                        cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                    }
                                    cout << endl;
                                }

                                cout << endl;

                                cout << "Para utilizar un bombardero cuando tengas 4 puntos colocar las cordenadas (fila: 10, columa: 10)"<<endl ;

                                cout << "JUGADOR 1 - " << usuario1.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;

                                cout << "Fila: ";
                                cin >> fila_ataque;
                                cout << "Columna: ";
                                cin >> columna_ataque;

                                if (fila_ataque >= 0 && fila_ataque < 8 && columna_ataque >= 0 && columna_ataque < 8)
                                {
                                    if ((juego_largo_J2[fila_ataque][columna_ataque] == 'x') && (juego_largo_J2[fila_ataque][columna_ataque] != '0'))
                                    {
                                        cout << "¡Felicidades, hundiste el barco de " << usuario2.nombre << "!" << endl;
                                        usuario1.puntaje++;
                                        cout << "Tienes " << usuario1.puntaje << " puntos." << endl;
                                        juego_largo_J2[fila_ataque][columna_ataque] = '0';
                                        juego_largo_J2_sin_barcos[fila_ataque][columna_ataque] = '0';
                                        cout << endl;

                                        cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                        cout << "      0      1      2      3      4      5      6      7" << endl;
                                        for (int i = 0; i < 8; i++)
                                        {
                                            cout << i << "  ";
                                            for (int j = 0; j < 8; j++)
                                            {
                                                cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                            }
                                            cout << endl;
                                        }
                                    }
                                    else
                                    {
                                        if (juego_largo_J2[fila_ataque][columna_ataque] != '0')
                                        {
                                            juego_largo_J2_sin_barcos[fila_ataque][columna_ataque] = '*';
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << endl;
                                        }

                                        cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                        cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                        cout << "      0      1      2      3      4      5      6      7" << endl;
                                        for (int i = 0; i < 8; i++)
                                        {
                                            cout << i << "  ";
                                            for (int j = 0; j < 8; j++)
                                            {
                                                cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                            }
                                            cout << endl;
                                        }
                                    }
                                }
                                else if ((fila_ataque == 10) && (columna_ataque == 10)&& (usuario1.puntaje == 4))
                            {

                                for (int i = 0; i < 4; ++i)
                                {

                                    fila[i] = rand() % 8;

                                    columna[i] = rand() % 8;

                                    if ((juego_largo_J2[fila[i]][columna[i]] == 'x') && (juego_largo_J2[fila[i]][columna[i]] != '0'))
                                    {
                                        juego_largo_J2[fila[i]][columna[i]] = '0';
                                        juego_largo_J2_sin_barcos[fila[i]][columna[i]] = '0';
                                        cout << endl;
                                    }
                                    else
                                    {
                                        if (juego_largo_J2[fila[i]][columna[i]] != '0')
                                        {
                                            juego_largo_J2_sin_barcos[fila[i]][columna[i]] = '*';
                                            


                                        }

                                    

                                        else
                                        {
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                            cout << "      0      1      2      3      4      5      6      7 " << endl;
                                            for (int i = 0; i < 8; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 8; j++)
                                                {
                                                    cout << " | " << juego_largo_J2_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
                                }
                                            cout << endl;
                                            cout<<"Este es el mapa de "<<usuario2.nombre<<" Luego de tu ataque bombardero:\n\n ";
                                            cout << "      0      1      2      3      4      5      6      7 " << endl;
                                            for (int i = 0; i < 8; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 8; j++)
                                                {
                                                    cout << " | " << juego_rapido_J1_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                            }
                                else
                                {
                                    cout << "Posición fuera de los límites de la matriz o aun no tienes los puntos necesarios para realizar un ataque bombardero" << endl;
                                }

                                logo_funcion();

                                cout << "\tMapa de " << usuario1.nombre << ":\n\n";
                                cout << endl;
                                cout << "      0      1      2      3      4      5      6      7" << endl;
                                for (int i = 0; i < 8; i++)
                                {
                                    cout << i << "  ";
                                    for (int j = 0; j < 8; j++)
                                    {
                                        cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                    }
                                    cout << endl;
                                }
                                cout << "Para utilizar un bombardero cuando tengas 4 puntos colocar las cordenadas (fila: 10, columa: 10)"<<endl ;

                                cout << "JUGADOR 2 - " << usuario2.nombre << ". Ingrese las coordenadas que quiere atacar: " << endl;
                                cout << "Fila: ";
                                cin >> fila_ataque;
                                cout << "Columna: ";
                                cin >> columna_ataque;

                                if (fila_ataque >= 0 && fila_ataque < 8 && columna_ataque >= 0 && columna_ataque < 8)
                                {
                                    if ((juego_largo_J1[fila_ataque][columna_ataque] == 'x') && (juego_largo_J1[fila_ataque][columna_ataque] != '0'))
                                    {
                                        cout << "¡Felicidades, hundiste el barco de " << usuario1.nombre << "!" << endl;
                                        usuario2.puntaje++;
                                        cout << "Tienes " << usuario2.puntaje << " puntos." << endl;
                                        juego_largo_J1[fila_ataque][columna_ataque] = '0';
                                        juego_largo_J1_sin_barcos[fila_ataque][columna_ataque] = '0';
                                        cout << endl;

                                        cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                        cout << "      0      1      2      3      4      5      6      7" << endl;
                                        for (int i = 0; i < 8; i++)
                                        {
                                            cout << i << "  ";
                                            for (int j = 0; j < 8; j++)
                                            {
                                                cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                            }
                                            cout << endl;
                                        }
                                    }
                                    else
                                    {
                                        if (juego_largo_J1[fila_ataque][columna_ataque] != '0')
                                        {
                                            juego_largo_J1_sin_barcos[fila_ataque][columna_ataque] = '*';
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << endl;
                                        }

                                        cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                        cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                        cout << "      0      1      2      3      4      5      6      7" << endl;
                                        for (int i = 0; i < 8; i++)
                                        {
                                            cout << i << "  ";
                                            for (int j = 0; j < 8; j++)
                                            {
                                                cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                            }
                                            cout << endl;
                                        }
                                    }
                                }
                                else if ((fila_ataque == 10) && (columna_ataque == 10)&&(usuario2.puntaje==4))
                            {

                                for (int i = 0; i < 4; ++i)
                                {

                                    fila[i] = rand() % 4;

                                    columna[i] = rand() % 4;

                                    if ((juego_largo_J1[fila[i]][columna[i]] == 'x') && (juego_largo_J1[fila[i]][columna[i]] != '0'))
                                    {
                                        juego_largo_J1[fila[i]][columna[i]] = '0';
                                        juego_largo_J1_sin_barcos[fila[i]][columna[i]] = '0';
                                        cout << endl;
                                    }
                                    else
                                    {
                                        if (juego_largo_J1[fila[i]][columna[i]] != '0')
                                        {
                                            juego_largo_J1_sin_barcos[fila[i]][columna[i]] = '*';
                                            


                                        }

                                    

                                        else
                                        {
                                            cout << "Suerte para la proxima, no hundiste ningun barco o ya atacaste esta posicion." << endl;
                                            cout << "Este es el mapa del enemigo despues de su ataque: " << endl;

                                            cout << "      0      1      2      3      4      5      6      7 " << endl;
                                            for (int i = 0; i < 8; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 8; j++)
                                                {
                                                    cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                                        }
                                    }
                                }
                                            cout << endl;
                                            cout<<"Este es el mapa de "<<usuario1.nombre<<" Luego de tu ataque bombardero:\n\n ";
                                            cout << "      0      1      2      3      4      5      6      7 " << endl;
                                            for (int i = 0; i < 8; i++)
                                            {
                                                cout << i << "  ";
                                                for (int j = 0; j < 8; j++)
                                                {
                                                    cout << " | " << juego_largo_J1_sin_barcos[i][j] << " | ";
                                                }
                                                cout << endl;
                                            }
                            }
                                else
                                {
                                    cout << "Posición fuera de los límites de la matriz o aun no tienes el puntaje suficiente para realizar un ataque bombardero" << endl;
                                }

                            } while (usuario1.puntaje < 8 && usuario2.puntaje < 8);
                            if (usuario1.puntaje == 8)
                            {
                                cout << "¡Felicidades " << usuario1.nombre << ", has ganado!" << endl;
                            }
                            else if (usuario2.puntaje == 8)
                            {
                                cout << "¡Felicidades " << usuario2.nombre << ", has ganado!" << endl;
                            }

                            cout << "RESULTADOS" << endl;

                            cout << "JUGADOR 1 - " << usuario1.nombre << ". Esta es su flota despues del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++)
                                {
                                    cout << " | " << juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

                            cout << "JUGADOR 2 - " << usuario2.nombre << ". Esta es su flota despues del ataque (0 = barco hundido):" << endl;
                            cout << "      0      1      2      3      4      5      6      7" << endl;
                            for (int i = 0; i < 8; i++)
                            {
                                cout << i << "  ";
                                for (int j = 0; j < 8; j++)
                                {
                                    cout << " | " << juego_largo_J2[i][j] << " | ";
                                }
                                cout << endl;
                            }
                        }

                        if (eleccion_del_tamanio_de_cuadricula != 1 && eleccion_del_tamanio_de_cuadricula != 2)
                        {
                            cout << "Por favor escoja una opcion valida.\n\n";
                        }
                    }
                    while (eleccion_del_tamanio_de_cuadricula != 1 && eleccion_del_tamanio_de_cuadricula != 2);

                break;

             case 2:
                int dificultad;
                cout << "Seleccione la dificultad:\n1. Facil\n2. Dificil\n\n";
                cout << "Escriba su opcion aqui: ";
                cin >> dificultad;

                if (dificultad == 1) {
                    cout << "Instrucciones del Juego:\n\n";
                    cout << "Usted esta en el  modo facil (cuadricula 4x4)\n\n";
                    cout << "SIMBOLOGIA DEL JUEGO: \n\n";
                    cout << "Tener presente lo siguiente para identificar cada ataque:\n";
                    cout << "  X Indica donde esta asignado el  barco.\n";
                    cout << "  0 Indica que se ha realizado un ataque exitoso y se ha golpeado un barco.\n";
                    cout << "  * Indica que no se ha golpeado ningun barco y el ataque ha sido en otro lugar de la matriz.\n\n";
                    cout << "El objetivo del juego es ser el primero en hundir todos los barcos del oponente.\n\n";
                    cout << "INDICACION DEL JUEGO:\n";
                    cout << "1. Tableros de Juego: Cada jugador tiene dos tableros de 4x4 casillas.\n";
                    cout << "2. Barcos: Cada jugador tiene una flota que incluye los siguientes barcos:\n";
                    cout << "    - 1 portaaviones \n";          
                    cout << "    - 1 destructor\n";
                    cout <<" El jugador tiene un total de 4 barcos para ubicarlos en un lugar estrategico.\n\n";
                    cout << "PREPARACION DEL JUEGO:\n";
                    cout << "   Ubiacion de Barcos:\n";
                    cout << "    - Cada jugador posiciona sus barcos en su propio tablero.\n";
                    cout << "    - La ubicacion de los barcos debe mantenerse en secreto para el oponente.\n\n";
                    cout << "COMO SE JUEGA:\n";
                    cout << "1. Turnos Alternos: Los jugadores se turnan para atacar. Un jugador hace un ataque por turno.\n";
                    cout << "AL REALIZAR UN ATAQUE ";
                    cout << "el jugador indica una coordenada en el tablero del oponente (por ejemplo, fila |1| Columna |0|).\n";
                    cout << "El juego termina cuando un jugador hunde todos los barcos del oponente. Ese jugador es declarado ganador.\n\n";
               
               
               
               
               // estas son las indicaciones para el modo dificil
            
               
            
               
                } else if (dificultad == 2) {

                    cout << "Instrucciones del Juego:\n\n";
                    cout << "Usted esta en el  modo dificil (cuadricula 8x8) \n\n";
                    cout << "SIMBOLOGIA DE JUEGO:\n\n";
                    cout << "Tener presente lo siguiente para identificar cada ataque:\n";
                    cout << "  X Indica donde esta asignado el  barco.\n";
                    cout << "  0 Indica que se ha realizado un ataque exitoso y se ha golpeado un barco.\n";
                    cout << "  * Indica que no se ha golpeado ningun barco y el ataque ha sido en otro lugar de la matriz.\n\n";

            
        
                    cout << "El objetivo del juego es ser el primero en hundir todos los barcos del oponente.\n\n";
                    cout << "INDICACIONES DEL JUEGO:\n";
                    cout << "1. Tableros de Juego: Cada jugador tiene dos tableros de 8x8 casillas.\n\n";
                    cout << "2. Barcos: Cada jugador tiene una flota que incluye los siguientes barcos:\n";
                    cout << "    - 1 portaaviones \n";
                    cout << "    - 1 acorazado \n";
                    cout << "    - 1 crucero \n";
                    cout << "    - 1 submarino \n";
                    cout << "    - 1 destructor\n\n";
                    cout << " El jugador tiene un maximo de 8 barcos para colocar en distintos lugares del tablero\n\n";
                    cout << "PREPARACION DEL JUEGO:\n";
                    cout << "1. Posicionamiento de Barcos:\n";
                    cout << "    - Cada jugador posiciona sus barcos en su propio tablero.\n";
                    cout << "    - La ubicacion de los barcos debe mantenerse en secreto para el oponente.\n\n";
                    cout << "COMO SE JUEGA:\n";
                    cout << "1. Turnos Alternos: Los jugadores se turnan para atacar. Un jugador hace un ataque por turno.\n";
                    cout << "AL REALIZAR UN ATAQUE ";
                    cout << " el jugador indica una coordenada en el tablero del oponente (por ejemplo, |0| fila |1|columna).\n";
                    cout << "El juego termina cuando un jugador hunde todos los barcos del oponente. Ese jugador es declarado ganador.\n\n";
                } else {
                    cout << "Dificultad no válida. Volviendo al menú principal.\n\n";
                }
                break;
            

         case 3:
            
             logo_funcion () ;
               
                cout << "Nombre: Julio Alejandro Flores Diaz\nNumero de carne: 00018824\n\n";
                cout << "Nombre: Johnny Omar Arteaga Ponce\nNumero de carne: 00143824\n\n";
                cout << "Nombre: Andrea Pamela Alvarez Lopez\nNumero de carne: 00073824\n\n";
                
                break;

         case 4:
            cout << "Ha salido del juego";
            break;
        
        case 5:  
        cout<<"RECORD DE PARTIDAS"<<endl;  
        creacion_archivo();
    add(usuario1, usuario2);
    lectura_archivo();
break; 

            default:
            cout << "Por favor escoger una opcion valida\n\n";
            break;
        }

    } while ((eleccion_del_usuario_en_el_menu > 5) || (eleccion_del_usuario_en_el_menu < 1));














    return 0;
}

using namespace std;
void creacion_archivo() {
    //o = output "Producion, creacion o emision"
    ofstream archivo; //creamos un tipo de variable y el nombre

    archivo.open("record_partidas.txt", ios::app); //Creando y abriendo el archivo
    //out = output, crea el archivo

    if (archivo.fail()) {
        cout << "No se pudo crear el archivo";
        exit(1);
    }

    archivo.close(); //cerramos el archivo
}


void add(Usuario usuario1, Usuario usuario2){
    ofstream archivo;
    archivo.open("record_partidas.txt", ios::app); //app = abrir el documento para AÑADIR texto

    if (archivo.fail()) {
        cout << "No se pudo crear el archivo";
        exit(1);
    }

    archivo << "\t Partida " << endl; //ciclo
    archivo << "Jugador 1 - " << usuario1.nombre << " con puntaje: " << usuario1.puntaje << endl;
    archivo << "Jugador 2 - " << usuario2.nombre << " con puntaje: " << usuario2.puntaje << endl;

    archivo.close(); //cerrar archivo

}

void lectura_archivo (){
    ifstream archivo; // i = input "Abrir, entrada de archivo"
    string texto;

    archivo.open("record_partidas.txt", ios::in); //Abrimos el archivo en modo lectura

    if (archivo.fail()) {
        cout << "No se pudo crear el archivo";
        exit(1);
    }

    while (!archivo.eof()){ //eof = recorrer todo el archivo
        getline(archivo, texto);
        cout << texto << endl;
    }

    archivo.close(); //cerramos el archivo

}