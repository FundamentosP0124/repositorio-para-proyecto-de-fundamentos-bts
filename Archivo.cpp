#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct Usuario {
    string nombre = "";
    int puntaje = 0;
};

void creacion_archivo(); // Para crear archivo
void lectura_archivo(); // Para leer el archivo
void add(Usuario usuario1, Usuario usuario2); // Para agregar usuarios al archivo

int main() {
    Usuario usuario1, usuario2;
    int opcion = 0;
    
    cout << "Ingrese una opcion:" << endl;
    cout << "1. 4x4" << endl;
    cout << "2. 8x8" << endl;
    cout << "Opcion elegida: ";
    cin >> opcion;

    cout << "Escribe un nombre para tu equipo: ";
    cin >> usuario1.nombre;

    cout << "Escribe un nombre para tu equipo: ";
    cin >> usuario2.nombre;

    creacion_archivo(); // Asegurarse de que el archivo exista
    add(usuario1, usuario2); // Agregar los usuarios al archivo
    lectura_archivo(); // Leer el contenido del archivo

    return 0;
}

void creacion_archivo() {
    ofstream archivo;
    archivo.open("prueba.txt", ios::app); // Abrir en modo append para no sobrescribir el contenido
    if (archivo.fail()) {
        cout << "No se pudo crear el archivo";
        exit(1);
    }
    archivo.close(); // Solo asegurarse de que el archivo existe y luego cerrarlo
}

void add(Usuario usuario1, Usuario usuario2){
    static int partida = 1; // Static para mantener el conteo entre llamadas
    ofstream archivo;
    archivo.open("prueba.txt", ios::app); // Abrir en modo append para agregar texto

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    archivo << "\nPartida " << partida++ << endl;
    archivo << "Jugador 1 - " << usuario1.nombre << " con puntaje: " << usuario1.puntaje << endl;
    archivo << "Jugador 2 - " << usuario2.nombre << " con puntaje: " << usuario2.puntaje << endl;

    archivo.close(); // Cerrar el archivo
}

void lectura_archivo() {
    ifstream archivo; // Abrir el archivo para lectura
    string texto;

    archivo.open("prueba.txt", ios::in); // Abrir en modo lectura

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while (getline(archivo, texto)) { // Leer línea por línea
        cout << texto << endl;
    }

    archivo.close(); // Cerrar el archivo
}
