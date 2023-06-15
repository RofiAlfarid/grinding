#include <stdio.h>

void printArr(int **arr, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
    printf("\n");
  }
}


void winner(int n, int m, int matriksAkhir[][100]){
     //transpose
        printf("Matriks akhir hasil transpose :\n");
        for(int baris = 0; baris < m; baris++){ // baris < m karena agar baris sesuai dengan kolom baru
            for(int kolom = 0; kolom < n; kolom++){ // kolom < n karena agar kolom sesuai dengan baris baru
                printf("%d ", matriksAkhir[baris][kolom]);   // menampilkan matriks secara ke bawah dari kolom pertama
            }
            printf("\n");
        }
        printf("You are the Winner!\n");
}