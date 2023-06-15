#include <stdio.h>
#include <string.h>
#include "TP1_header.h"

// void printArr(int **arr, int rows, int cols){
//     for (int i = 0; i < rows; i++) {
//         for (int j = 0; j < cols; j++) {
//             printf("%d ", arr[i][j]);
//         }
//     printf("\n");
//   }
// }

int JumlahRotasi(int num){
    return num % 4;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int matriksAwal[n][m];

    // scan
    int baris, kolom;
    for(baris = 0; baris < n; baris++){
        for(kolom = 0; kolom < m; kolom++){
            scanf("%d", &matriksAwal[baris][kolom]);
        }
    }
    printf("\n");

    // menampilkan
    printf("Matriks awal :\n");
    // printArr(matriksAwal, n, m);
    
    for(baris = 0; baris < n; baris++){
        for(kolom = 0; kolom < m; kolom++){
            printf("%d ", matriksAwal[baris][kolom]);
        }
        printf("\n");
        
    }

    // penjumlahan baris 1 dan kolom 1
    int jumlahBaris = 0;
    int jumlahKolom = 0;
    for(baris = 0; baris < n; baris++){
        for(kolom = 0; kolom < m; kolom++){
            if(baris == 0){
                jumlahBaris += matriksAwal[baris][kolom];
            }
            if(kolom == 0){
                jumlahKolom += matriksAwal[baris][kolom];
            }
        }
    }

    int total;
    total = jumlahBaris + jumlahKolom;
    printf("jumlah: %d\n", total);

    // jumlah rotasi
    int jumRotasi = JumlahRotasi(total);
    printf("jum rotasi: %d\n", jumRotasi);

    printf("rotasi:\n");
    int sama = 1;
    int l1,l2;
    if (jumRotasi % 2 == 1){
        l1 = m;
        l2 = n;
    } else {
        l1 = n;
        l2 = m;
    }
    int matriksAkhir[l1][l2];
    // peng rotasian
    if(total % 2 == 0){
        if(jumRotasi == 1){
            for(baris = m - 1; baris >= 0; baris--){
                for(kolom = 0; kolom < n; kolom++){
                    printf("%d ", matriksAwal[kolom][baris]);
                    matriksAkhir[kolom][baris] = matriksAwal[kolom][baris];
                }
                printf("\n");
            }
        }
        if(jumRotasi == 2){
            for (baris = n - 1; baris >= 0; baris--) {
                for (kolom = m - 1; kolom >= 0; kolom--) {
                    printf("%d ", matriksAwal[baris][kolom]);
                    matriksAkhir[baris][kolom] = matriksAwal[baris][kolom];
                }
                printf("\n");
            }
        }
        if(jumRotasi == 3){
            for(baris = 0; baris < m; baris++){
                for(kolom = n - 1; kolom >= 0; kolom--){
                    printf("%d ", matriksAwal[kolom][baris]);
                    matriksAkhir[kolom][baris] = matriksAwal[kolom][baris];
                }
                printf("\n");
            }
        }
        if(jumRotasi == 0){
            for(baris = 0; baris < n; baris++){
                for(kolom = 0; kolom < m; kolom++){
                    printf("%d ", matriksAwal[baris][kolom]);
                    matriksAkhir[baris][kolom] = matriksAwal[baris][kolom];
                }
                printf("\n");
            }
        }
    }else{
        int m1 = 0;
        int m2 = 0;
        if(jumRotasi == 0){
           for(baris = 0; baris < n; baris++){
                for(kolom = 0; kolom < m; kolom++){
                    printf("%d ", matriksAwal[baris][kolom]);
                    matriksAkhir[baris][kolom] = matriksAwal[baris][kolom];
                }
                printf("\n");
            } 
        }
        if(jumRotasi == 1){
            for(baris = 0; baris < m; baris++){
                m2 = 0;
                for(kolom = n - 1; kolom >= 0; kolom--){
                    printf("%d ", matriksAwal[kolom][baris]);
                    int tmp = matriksAwal[kolom][baris];
                    matriksAkhir[m1][m2] = tmp;
                    m2++;
                }
                printf("\n");
                m1++;
            }
        }
        if(jumRotasi == 2){
            for (baris = n - 1; baris >= 0; baris--) {
                for (kolom = m - 1; kolom >= 0; kolom--) {
                    printf("%d ", matriksAwal[baris][kolom]);
                    matriksAkhir[baris][kolom] = matriksAwal[baris][kolom];
                }
                printf("\n");
            }
        }
        if(jumRotasi == 3){
            for(baris = m - 1; baris >= 0; baris--){
                for(kolom = 0; kolom < n; kolom++){
                    printf("%d ", matriksAwal[kolom][baris]);
                    matriksAkhir[kolom][baris] = matriksAwal[kolom][baris];
                }
                printf("\n");
            }
        }
    }

    printf("sama: %d\n", sama);
    // ngecek
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(matriksAwal[i][j] != matriksAkhir[i][j]){
                sama = 0;
                // printf("matriks awal[%d][%d]= %d | matriks akhir[%d][%d]= %d", i, j, matriksAwal[i][j], i, j, matriksAkhir[i][j]);
            }
            // printf("matriks awal[%d][%d]= %d | matriks akhir[%d][%d]= %d", i, j, matriksAwal[i][j], i, j, matriksAkhir[i][j]);
            // printf("\n");
        }
    }
    printf("sama after: %d\n", sama);

    for(i = 0; i < l1; i++){
        for(j = 0; j < l2; j++){
            printf("%d ", matriksAkhir[i][j]);
        }
        printf("\n");
    }

    // membandingkan matriks
    if(sama == 1){
        // //transpose
        // printf("Matriks akhir hasil transpose :\n");
        // for(baris = 0; baris < m; baris++){ // baris < m karena agar baris sesuai dengan kolom baru
        //     for(kolom = 0; kolom < n; kolom++){ // kolom < n karena agar kolom sesuai dengan baris baru
        //         printf("%d ", matriksAkhir[baris][kolom]);   // menampilkan matriks secara ke bawah dari kolom pertama
        //     }
        //     printf("\n");
        // }
        // printf("You are the Winner!\n");
        winner(n,m,matriksAkhir);
    }else{
        // refleksi
        printf("Matriks akhir hasil refleksi :\n");
        for(baris = 0; baris < n; baris++){
            for(kolom = m - 1; kolom >= 0; kolom--){  // (m-1) karena dimulai dari indeks 0, (kolom--) agar dimulai dari belakang
                printf("%d ", matriksAkhir[kolom][baris]);   // menampilkan matriks
            }
            printf("\n");
        }
        printf("Oops You Lose the game!\n");
    }

    return 0;
}