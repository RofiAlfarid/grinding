#include <stdio.h>

typedef struct {
    char Name[100];
    int NumericSize;
    char SizeEU[5];
}mhs;

typedef struct {
    int row;
    int col;
}coor;

coor getCoor(int m[][100]);
void showLine(mhs *kursi[][100], int n, int m);
