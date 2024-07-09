#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Usuario {
    string nombre = "";
    int puntaje = 0;
};

void creacion_archivo(); //Para crear archivo
void lectura_archivo (); //Para leer archivo
void add(Usuario usuario1, Usuario usuario2);

int main() {
    Usuario usuario1, usuario2;
    int opcion = 0;
    
    cout << "Ingrese una opcion:" << endl;
    cout << "1. 4x4" << endl;
    cout << "2. 8x8" << endl;
    cout << "Opcion elegida: ";
    cin >> opcion;

    if (opcion==1){
    cout << "Escribe un nombre para tu equipo: ";
    cin >> usuario1.nombre;

    cout << "Escribe un nombre para tu equipo: ";
    cin >> usuario2.nombre;
    } else if (opcion==2) {
        cout << "Escribe un nombre para tu equipo: ";
    cin >> usuario1.nombre;
    cout << "Escribe un nombre para tu equipo: ";
    cin >> usuario2.nombre;
    }

    creacion_archivo();
    add(usuario1, usuario2);
    lectura_archivo();


    return 0;
}

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
