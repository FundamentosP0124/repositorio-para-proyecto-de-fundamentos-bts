#include <iostream>
using namespace std;

struct Usuario
{
    string nombre = "";
    int puntos = 0;
};

int main(){

int eleccion_del_usuario_en_el_menu = 0, eleccion_del_modo_de_juego = 0, eleccion_del_tamanio_de_cuadricula = 0;
do
{

cout << "   ___  ______   _______     _  _____ _   _____   __ " << endl;
cout << "  / _ |/ __/ /  / __/ _ |   / |/ / _ | | / / _ | / / " << endl;
cout << " / ___/ _// /__/ _// __ |  /    / __ | |/ / __ |/ /__" << endl;
cout << "/_/  /___/____/___/_/ |_| /_/|_/_/ |_|___/_/ |_/____/" << endl<<endl; 

cout<<"1. Jugar\n2. Ayuda\n3. Creditos\n4. Salir\n\n";
cout<<"Escriba el numero de su opcion aqui: ";
cin>>eleccion_del_usuario_en_el_menu;
cout<<endl;

switch (eleccion_del_usuario_en_el_menu) {
            case 1:
                do 
                {
                    cout << "\t---Elija el modo de juego---\n\n";
                    cout << "1. Jugador vs COM\n2. Jugador vs jugador\n\n";
                    cout << "Escriba el numero su opcion aqui: ";
                    cin >> eleccion_del_modo_de_juego;
                    cout << endl;

                    if (eleccion_del_modo_de_juego == 1 || eleccion_del_modo_de_juego == 2) {
                        do {
                            cout << "\t---Elija el tamanio de caudricula---\n\n";
                            cout << "1. Cuadricula 4x4 (Modo rapido con 4 barcos por bando)\n2. Cuadricula 8x8 (Modo largo con 8 barcos por bando)\n\n";
                            cout << "Escriba el numero de su opcion aqui: ";
                            cin >> eleccion_del_tamanio_de_cuadricula;
                            cout << endl;



                            if ((eleccion_del_modo_de_juego==1)&&(eleccion_del_tamanio_de_cuadricula==1)){
                            cout<<"Escribe un nombre para tu equipo: ";
                                Usuario usuario1;
                                cin>>usuario1.nombre;
                                //Acá va la matriz de 4x4 
                            }
                            else if ((eleccion_del_modo_de_juego==2)&&(eleccion_del_tamanio_de_cuadricula==1)){
                            cout<<"Escribe el nombre del equipo del jugador 1: ";
                                Usuario usuario1;
                                cin>>usuario1.nombre;
                            
                            cout<<"Escribe el nombre del equipo del jugador 2: ";
                                Usuario usuario2;
                                cin>>usuario2.nombre;
                                //Acá van las matrices de 4x4 
                            }


                            else if ((eleccion_del_modo_de_juego==1)&&(eleccion_del_tamanio_de_cuadricula==2)){
                            cout<<"Escribe el nombre del equipo del jugador 1: ";
                                Usuario usuario1;
                                cin>>usuario1.nombre;
                            
                            cout<<"Escribe el nombre del equipo del jugador 2: ";
                                Usuario usuario2;
                                cin>>usuario2.nombre;
                                //Acá van las matrices de 8x8 
                            }


                            else if ((eleccion_del_modo_de_juego==2)&&(eleccion_del_tamanio_de_cuadricula==2)){
                            cout<<"Escribe el nombre del equipo del jugador 1: ";
                                Usuario usuario1;
                                cin>>usuario1.nombre;
                            
                            cout<<"Escribe el nombre del equipo del jugador 2: ";
                                Usuario usuario2;
                                cin>>usuario2.nombre;
                                //Acá van las matrices de 8x8 
                            }

                            if (eleccion_del_tamanio_de_cuadricula != 1 && eleccion_del_tamanio_de_cuadricula != 2) {
                                cout << "Por favor escoja una opcion valida.\n\n";
                            }
                        } while (eleccion_del_tamanio_de_cuadricula != 1 && eleccion_del_tamanio_de_cuadricula != 2);
                    } else {
                        cout << "Por favor escoja una opcion valida.\n\n";
                    }
                } while (eleccion_del_modo_de_juego != 1 && eleccion_del_modo_de_juego != 2);
                
            break;





            case 2:
            cout<<"Aca van las instrucciones del jueguito";
            break;

        case 3:
            cout<<"\tFUNDAMENTOS DE PROGRAMACION\n\t\tCICLO 01\n\tCATEDRATICA ING. ELISA ALDANA\n\t\tJUEGO HECHO POR:\n\t\tJULIO FLORES\n\t\tJOHNNY ARTEAGA\n\t\tANDREA ALVAREZ";
            break;

        case 4:
            cout<<"Ha salido del juego";
            break;


        default:
        cout<<"Por favor escoger una opcion valida\n\n";
            break;
        }
    
    } while ((eleccion_del_usuario_en_el_menu > 4)||(eleccion_del_usuario_en_el_menu < 1));


    return 0;
}