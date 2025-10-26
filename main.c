#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sokoban.h"


int main(){
    char **map;
    int Xcaisse;
    int Ycaisse;
    int Ypoint;
    int Xpoint;
    int Xjoueur;
    int Yjoueur;

    map = malloc(11 * sizeof(*map));
    map[10] = NULL;
    
    map[0] = malloc(11 * sizeof(char));
    map[0][10] = '\0';

    map[1] = malloc(11 * sizeof(char));
    map[1][10] = '\0';

    map[2] = malloc(11 * sizeof(char));
    map[2][10] = '\0';

    map[3] = malloc(11 * sizeof(char));
    map[3][10] = '\0';

    map[4] = malloc(11 * sizeof(char));
    map[4][10] = '\0';

    map[5] = malloc(11 * sizeof(char));
    map[5][10] = '\0';

    map[6] = malloc(11 * sizeof(char));
    map[6][10] = '\0';

    map[7] = malloc(11 * sizeof(char));
    map[7][10] = '\0';

    map[8] = malloc(11 * sizeof(char));
    map[8][10] = '\0';

    map[9] = malloc(11 * sizeof(char));
    map[9][10] = '\0';

    generation(map, &Xcaisse, &Ycaisse, &Ypoint, &Xpoint, &Xjoueur, &Yjoueur);

    int i = 0;
    int b = 0;
    int ConditionVictoire = 0;
    char direction;

    printf("vous etes le rond et vous devez déplacer la caisse qui est représenter par une croix jusqu'au points \n");
    while (ConditionVictoire == 0 ){
        if (map[Ypoint][Xpoint] == ' '){
            map[Ypoint][Xpoint] = '.';
        }
        affichage(map);
        printf("dans qu'elle direction voulez vous allez?");
        scanf("%c", &direction);
        
        if (direction == 'z'){
            if (Yjoueur - 1 < 1 ){
                printf("vous sortez des limite\n");
            }
            else {
                map[Yjoueur][Xjoueur] = ' ';
                Yjoueur = Yjoueur - 1;
                if (map[Yjoueur][Xjoueur] == 'X'){
                    if (Ycaisse == 1 && Ypoint != 2){
                        ConditionVictoire = 2;
                    }
                    Ycaisse = Ycaisse - 1;
                    map[Ycaisse][Xcaisse] = 'X';
                }
                map[Yjoueur][Xjoueur] = 'O';
            }
        }
        else if (direction == 's'){
            if (Yjoueur + 1 > 9 ){
                printf("vous sortez des limite\n");
            }
            else { 
                map[Yjoueur][Xjoueur] = ' ';
                Yjoueur = Yjoueur + 1;
                if (map[Yjoueur][Xjoueur] == 'X'){
                    if (Ycaisse == 8 && Ypoint != 9){
                        ConditionVictoire = 2;
                    }
                    Ycaisse = Ycaisse + 1;
                    map[Ycaisse][Xcaisse] = 'X';
                }
                map[Yjoueur][Xjoueur] = 'O';
            }
        }
        else if (direction == 'q'){
            if (Xjoueur - 1 < 0 ){
                printf("vous sortez des limite\n");
            }
            else {
                map[Yjoueur][Xjoueur] = ' ';
                Xjoueur = Xjoueur - 1;
                if (map[Yjoueur][Xjoueur] == 'X'){
                    if (Xcaisse == 2 && Xpoint != 3){
                        ConditionVictoire = 2;
                    }
                    Xcaisse = Xcaisse - 1;
                    map[Ycaisse][Xcaisse] = 'X';
                }
                map[Yjoueur][Xjoueur] = 'O';
            }
        }
        else if (direction == 'd'){
            if (Xjoueur + 1 > 9 ){
                printf("vous sortez des limite\n");
            }
            else { 
                map[Yjoueur][Xjoueur] = ' ';
                Xjoueur = Xjoueur + 1;
                if (map[Yjoueur][Xjoueur] == 'X'){
                    if (Xcaisse == 8 && Xpoint != 9){
                        ConditionVictoire = 2;
                    }
                    Xcaisse = Xcaisse + 1;
                    map[Ycaisse][Xcaisse] = 'X';
                }
                map[Yjoueur][Xjoueur] = 'O';
            }
        }
        else if (direction == 'c'){
            ConditionVictoire = 1;
        }
        else {
            printf("ceci n'est pas un caractère corecte\n");
        }
        if (map[Ycaisse][Xcaisse] == map[Ypoint][Xpoint]){
            ConditionVictoire = 1;
        }
        while (getchar() != '\n'){} 
    }
    affichage(map);
    if (ConditionVictoire == 1){
        printf("gg tu as gagné\n");
    }
    else {
        printf("vous avez perdu\n");
    }

    i = 0;
    while(map[i] != NULL)
    {
	    free(map[i]);
	    i = i + 1;
    }

free(map);
}