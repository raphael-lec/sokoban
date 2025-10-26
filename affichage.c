#include <stdio.h>
#include <stdlib.h>


void affichage(char **map){
    int i = 0;
    int b = 0;
    printf("############\n");
    while (i != 10){
        printf("#");
        printf("%c",map[1][1]);
        while (b != 10){
            printf("%c",map[i][b]);
            b = b + 1;
        }
        printf("#\n");
        i = i + 1;
        b = 0;
    }
    printf("############\n");

}