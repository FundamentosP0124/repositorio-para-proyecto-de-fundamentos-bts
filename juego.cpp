#include <iostream>
using namespace std;
int main(){

int eleccion_del_usuario_en_el_menu = 0;
do
{

cout << "   ___  ______   _______     _  _____ _   _____   __ " << endl;
cout << "  / _ |/ __/ /  / __/ _ |   / |/ / _ | | / / _ | / / " << endl;
cout << " / ___/ _// /__/ _// __ |  /    / __ | |/ / __ |/ /__" << endl;
cout << "/_/  /___/____/___/_/ |_| /_/|_/_/ |_|___/_/ |_/____/" << endl<<endl; 

cout<<"1. Jugar\n2. Ayuda\n3. Creditos\n4. Salir\n\n";
cout<<"Escriba su opcion aqui: ";
cin>>eleccion_del_usuario_en_el_menu;

switch (eleccion_del_usuario_en_el_menu)
{
case 1:
    cout<<"Aca va el jueguito";
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