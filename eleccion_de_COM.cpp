#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Usuario
{
    string nombre = "";
    int puntos = 0;

};

int main(){

int eleccion_del_usuario_en_el_menu = 0, eleccion_del_modo_de_juego = 0, eleccion_del_tamanio_de_cuadricula = 0;

int componente_en_x1_COM = 0, componente_en_x2_COM = 0, componente_en_x3_COM = 0, componente_en_x4_COM = 0, componente_en_x5_COM = 0, componente_en_x6_COM = 0, componente_en_x7_COM = 0, componente_en_x8_COM = 0;

int componente_en_y1_COM = 0, componente_en_y2_COM = 0, componente_en_y3_COM = 0, componente_en_y4_COM = 0, componente_en_y5_COM = 0, componente_en_y6_COM = 0, componente_en_y7_COM = 0, componente_en_y8_COM = 0;

int componente_en_x1_us1 = 0, componente_en_x2_us1 = 0, componente_en_x3_us1 = 0, componente_en_x4_us1 = 0, componente_en_x5_us1 = 0, componente_en_x6_us1 = 0, componente_en_x7_us1 = 0, componente_en_x8_us1 = 0;

int componente_en_y1_us2 = 0, componente_en_y2_us2 = 0, componente_en_y3_us2 = 0, componente_en_y4_us2 = 0, componente_en_y5_us2 = 0, componente_en_y6_us2 = 0, componente_en_y7_us2 = 0, componente_en_y8_us2 = 0;


                                srand(time(0)); 

                                 componente_en_x1_COM = rand() % 4;
                                 componente_en_x2_COM = rand() % 4;
                                 componente_en_x3_COM = rand() % 4;
                                 componente_en_x4_COM = rand() % 4;

                                 componente_en_y1_COM = rand() % 4;
                                 componente_en_y2_COM = rand() % 4;
                                 componente_en_y3_COM = rand() % 4;
                                 componente_en_y4_COM = rand() % 4;

//Probando que funcione correctamente 
cout<<"componente en x1: "<<componente_en_x1_COM<<endl;
cout<<"componente en x2: "<<componente_en_x2_COM<<endl;
cout<<"componente en x3: "<<componente_en_x3_COM<<endl;
cout<<"componente en x4: "<<componente_en_x4_COM<<endl;
cout<<"componente en y1: "<<componente_en_y1_COM<<endl;
cout<<"componente en y2: "<<componente_en_y2_COM<<endl;
cout<<"componente en y3: "<<componente_en_y3_COM<<endl;
cout<<"componente en y4: "<<componente_en_y4_COM<<endl;


return 0; 

}