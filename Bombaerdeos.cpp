#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){

char juego_largo_J1[8][8] = {};

srand(time (0));

int puntos=0;

int fila[8]={} , columna [8]={}; 



    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            juego_largo_J1[i][j] = '.';
        }
    }


                        cout << " El mapa original es:" << endl;

                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {

                                    cout << " | " << juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }



                            for (int i = 0; i < 3; ++i)
                            {

                                fila[i] = rand() % 8;

                                columna[i] = rand() % 8;

                                if ((fila[i] >= 0) && (fila[i] < 8) && (columna[i] >= 0) && (columna[i] < 8) && (fila[i] != fila[i - 1] || columna[i] != columna[i - 1]) && (fila[i] != fila[i - 2] || columna[i] != columna[i - 2]) && (fila[i] != fila[i - 3] || columna[i] != columna[i - 3]) && (fila[i] != fila[i - 4] || columna[i] != columna[i - 4]) && (fila[i] != fila[i - 5] || columna[i] != columna[i - 5]) && (fila[i] != fila[i - 6] || columna[i] != columna[i - 6]) && (fila[i] != fila[i - 7] || columna[i] != columna[i - 7]))
                                {
                                    juego_largo_J1[fila[i]][columna[i]] = 'x';
                                }
                                else
                                {
                                    --i;
                                }
                            }




                        cout << " El mapa luego del bombardeo es:" << endl;

                            for (int i = 0; i < 8; i++)
                            {
                                for (int j = 0; j < 8; j++)
                                {

                                    cout << " | " << juego_largo_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

    return 0;
}