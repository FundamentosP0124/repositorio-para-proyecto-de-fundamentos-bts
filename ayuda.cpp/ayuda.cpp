 #include <iostream>
using namespace std;

int main() {
    int eleccion_del_usuario_en_el_menu = 0;
    do {
        cout << "\t---Juego sobre hundir barquitos---\n"; // después le cambiamos el nombre
        cout << "1. Jugar\n2. Ayuda\n3. Grupo de trabajo\n4. Salir\n\n";
        cout << "Escriba su opcion aqui:";
        cin >> eleccion_del_usuario_en_el_menu;

        switch (eleccion_del_usuario_en_el_menu) {
            case 1:
                cout << "Aca va el jueguito\n";
                break;

            case 2: {
                int dificultad;
                cout << "Seleccione la dificultad (Tener en cuenta que las indicaciones son para COM y para 1 vs 1):\n1. Facil\n2. Dificil\n\n";
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
                    cout << "Al realizar un Ataque ";
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
                    cout << "Al realizar un Ataque ";
                    cout << " el jugador indica una coordenada en el tablero del oponente (por ejemplo, |0| fila |1|columna).\n";
                    cout << "El juego termina cuando un jugador hunde todos los barcos del oponente. Ese jugador es declarado ganador.\n\n";
                } else {
                    cout << "Dificultad no válida. Volviendo al menú principal.\n\n";
                }
                break;
            }

            case 3:
            
             logo_funcion();
               
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
