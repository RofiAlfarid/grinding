#include <stdio.h>



void main(){
    int ganjil[3];
    int genap[3];


    ganjil[0] = 1;
    ganjil[1] = 3;
    ganjil[2] = 5;

    genap[0] = 2;
    genap[1] = 4;
    genap[2] = 6;


    for (int i =0; i<3; i++) {
        printf("%d",ganjil[i]);
        printf("\n");
        printf("%d",genap[i]);
        printf("\n");
    }
}