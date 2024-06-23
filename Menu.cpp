#include <iostream>
using namespace std;
int main(){

int eleccion_del_usuario_en_el_menu = 0;
do
{


cout<<"\t---Juego sobre hundir barquitos---\n"; //después le cambiamos el nombre
cout<<"1. Jugar\n2. Ayuda\n3. Grupo de trabajo\n4. Salir\n\n";
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
    cout<<"Nombre: Julio Alejandro Flores Diaz\nNumero de carne: 00018824\n\n";
    cout<<"Nombre: Johnny Omar Arteaga Ponce\nNumero de carne: 00143824\n\n";
    cout<<"Nombre: Andrea Pamela Alvarez Lopez\nNumero de carne: 00073824\n\n";
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