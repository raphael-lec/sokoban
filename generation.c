#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generation(char **map,int *Xcaisse,int *Ycaisse,int *Ypoint,int *Xpoint,int *Xjoueur,int *Yjoueur){

    int i = 0;
    i = 0;
    while(i != 10)
    {
        int b = 1;
        
        while(b != 10)
        {
            map[i][b] = ' ';
            b = b + 1;
        }
        i = i + 1;
    }
    srand(time(NULL));
    *Xcaisse = rand() % 9 + 1;
    *Ycaisse = 9;

    while (*Xcaisse == 9 || *Xcaisse == 1){
        *Xcaisse = rand() % 9 + 1;
    }

    while (*Ycaisse == 9 || *Ycaisse == 1){
        *Ycaisse = rand() % 9 + 1;
    }

    map[*Ycaisse][*Xcaisse] = 'X';
    
    *Ypoint = rand() % 9 + 1;
    *Xpoint = rand() % 9 + 1;

    map[*Ypoint][*Xpoint] = '.';

    *Xjoueur = rand() % 9 + 1;
    *Yjoueur = rand() % 9 + 1;

    map[*Yjoueur][*Xjoueur] = 'O';
}
