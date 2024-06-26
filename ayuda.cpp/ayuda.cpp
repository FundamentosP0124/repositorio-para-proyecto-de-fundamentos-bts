#include <iostream>
using namespace std;

int main() {
    int eleccion_del_usuario_en_el_menu = 0;
    do {
        cout << "\t---Juego sobre hundir barquitos---\n"; // después le cambiamos el nombre
        cout << "1. Jugar\n2. Ayuda\n3. Grupo de trabajo\n4. Salir\n\n";
        cout << "Escriba su opcion aqui: ";
        cin >> eleccion_del_usuario_en_el_menu;

        switch (eleccion_del_usuario_en_el_menu) {
            case 1:
                cout << "Aca va el jueguito\n";
                break;

            case 2: {
                int dificultad;
                cout << "Seleccione la dificultad:\n1. Facil\n2. Dificil\n\n";
                cout << "Escriba su opcion aqui: ";
                cin >> dificultad;

                if (dificultad == 1) {
                    cout << "Instrucciones del Juego:\n";
                    cout << "El objetivo del juego es ser el primero en hundir todos los barcos del oponente.\n\n";
                    cout << "Indicacion del Juego:\n";
                    cout << "1. Tableros de Juego: Cada jugador tiene dos tableros de 4x4 casillas. Uno para posicionar sus propios barcos y otro para registrar sus ataques al oponente.\n";
                    cout << "2. Barcos: Cada jugador tiene una flota que incluye los siguientes barcos:\n";
                    cout << "    - 1 portaaviones \n";          
                    cout << "    - 1 destructor\n\n";
                    cout << "Preparacion del Juego:\n";
                    cout << "1. Posicionamiento de Barcos:\n";
                    cout << "    - Cada jugador posiciona sus barcos en su propio tablero.\n";
                    cout << "    - La ubicacion de los barcos debe mantenerse en secreto para el oponente.\n\n";
                    cout << "Como se  Juega\n";
                    cout << "1. Turnos Alternos: Los jugadores se turnan para atacar. Un jugador hace un ataque por turno.\n";
                    cout << "2. Realizar un Ataque:\n";
                    cout << "    - El jugador indica una coordenada en el tablero del oponente (por ejemplo, |11|).\n";
                    cout << "3. Registrar el Ataque:\n";
                    cout << "    - Cada jugador registra sus ataques en el tablero de ataque, marcando las casillas con 'o', 'tocado' o 'hundido' 'x' segun lo que suceda.\n\n";
                    cout << "El juego termina cuando un jugador hunde todos los barcos del oponente. Ese jugador es declarado ganador.\n\n";
                } else if (dificultad == 2) {
                    cout << "Instrucciones del Juego:\n";
                    
                    cout << "El objetivo del juego es ser el primero en hundir todos los barcos del oponente.\n\n";
                    cout << "Indicaciones del Juego\n";
                    cout << "1. Tableros de Juego: Cada jugador tiene dos tableros de 8x8 casillas. Uno para posicionar sus propios barcos y otro para registrar sus ataques al oponente.\n";
                    cout << "2. Barcos: Cada jugador tiene una flota que incluye los siguientes barcos:\n";
                    cout << "    - 1 portaaviones \n";
                    cout << "    - 1 acorazado \n";
                    cout << "    - 1 crucero \n";
                    cout << "    - 1 submarino \n";
                    cout << "    - 1 destructor\n\n";
                    cout << "Preparacion del Juego:\n";
                    cout << "1. Posicionamiento de Barcos:\n";
                    cout << "    - Cada jugador posiciona sus barcos en su propio tablero.\n";
                    cout << "    - La ubicacion de los barcos debe mantenerse en secreto para el oponente.\n\n";
                    cout << "Como se juega:\n";
                    cout << "1. Turnos Alternos: Los jugadores se turnan para atacar. Un jugador hace un ataque por turno.\n";
                    cout << "2. Realizar un Ataque:\n";
                    cout << "    - El jugador indica una coordenada en el tablero del oponente (por ejemplo, |25|).\n";
                    cout << "3. Registrar el Ataque:\n";
                    cout << "    - Cada jugador registra sus ataques en el tablero de ataque, marcando las casillas con 'o', 'tocado' o 'hundido' 'x' segun lo que suceda.\n\n";
                    cout << "El juego termina cuando un jugador hunde todos los barcos del oponente. Ese jugador es declarado ganador.\n\n";
                } else {
                    cout << "Dificultad no válida. Volviendo al menú principal.\n\n";
                }
                break;
            }

            case 3:
                cout << "Nombre: Julio Alejandro Flores Diaz\nNumero de carne: 00018824\n\n";
                cout << "Nombre: Johnny Omar Arteaga Ponce\nNumero de carne: 00143824\n\n";
                cout << "Nombre: Andrea Pamela Alvarez Lopez\nNumero de carne: 00073824\n\n";
                break;

            case 4:
                cout << "Ha salido del juego\n";
                break;

            default:
                cout << "Por favor escoger una opcion valida\n\n";
                break;
        }
    } while (eleccion_del_usuario_en_el_menu != 4);

    return 0;
}