#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){

char juego_rapido_J1[4][4] = {};

srand(time (0));

int puntos=0;

int fila[8]={} , columna [8]={}; 



    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            juego_rapido_J1[i][j] = '.';
        }
    }


                        cout << " El mapa original es:" << endl;

                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 4; j++)
                                {

                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }



                            for (int i = 0; i < 2; ++i)
                            {

                                fila[i] = rand() % 4;

                                columna[i] = rand() % 4;

                                if ((fila[i] >= 0) && (fila[i] < 4) && (columna[i] >= 0) && (columna[i] < 4) && (fila[i] != fila[i - 1] || columna[i] != columna[i - 1]) && (fila[i] != fila[i - 2] || columna[i] != columna[i - 2]) && (fila[i] != fila[i - 3] || columna[i] != columna[i - 3]))
                                {
                                    juego_rapido_J1[fila[i]][columna[i]] = 'x';
                                }
                                else
                                {
                                    --i;
                                }
                            }




                        cout << " El mapa luego del bombardeo es:" << endl;

                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 4; j++)
                                {

                                    cout << " | " << juego_rapido_J1[i][j] << " | ";
                                }
                                cout << endl;
                            }

    return 0;
}