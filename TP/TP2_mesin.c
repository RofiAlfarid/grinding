#include <stdio.h>
#include <string.h>
#include "TP2_header.h"



void showLine(mhs *kursi[][100], int n, int m){

    for (int i = 0; i< n; i++){
        for (int j = 0; j< m;j++){
            printf("%s  ",kursi[i][j].Name);
        }
        printf("\n");
    }
}