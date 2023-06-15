// #include "header.h"

#include <stdio.h>
#include <string.h>

typedef struct{
    char namaAtom[50];
    int noAtom;
    int formaAtom;
    double rasio;
}atom;

typedef struct{
    char namaAtom[50];
    char namaAtom1[50];
    char namaAtom2[50];
    int totalAtom;
    int totalPerfoma;
    double rasio;
}atomfusion;

void input(int n, atom masukan[]){
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", &masukan[i].namaAtom, &masukan[i].noAtom, &masukan[i].formaAtom);
    }
}

// void selectionSort(int n, atom masukan[], int ratio){
//     int min_idx;
//     for (int i = 0; i < n - 1; i++) {
//         min_idx = i;
//         for (int j = i + 1; j < n; j++) {
//             if (ratio[j] < ratio[min_idx]) {
//                 min_idx = j;
//             }
//         }
//         int temp = ratio[min_idx];
//         ratio[min_idx] = ratio[i];
//         ratio[i] = temp;
//     }
// }

void bubbleSort(atomfusion hasil[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++){
            if (hasil[j].rasio > hasil[j + 1].rasio){
                atomfusion temp;
                temp = hasil[j];
                hasil[j] = hasil[j+1];
                hasil[j+1] = temp;
            }
        }    
}


void sequentialSearch(int n, atom masukan[],atomfusion hasil[]){
    int i, j, k,ihasil;
    int total_noAtom, total_power;
    double rasio = 0;
    ihasil = 0;

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            for(k = j + 1; k < n; k++) {
                total_noAtom = masukan[i].noAtom + masukan[j].noAtom + masukan[k].noAtom;
                total_power = masukan[i].formaAtom + masukan[j].formaAtom + masukan[k].formaAtom;
                rasio = (double) total_power / total_noAtom;

                if(total_power >= 1.5 * total_noAtom) {
                    // printf("{%s, %s, %s} - Total Nomor Atom: %d - Total Power: %d - Rasio: %.2f\n", masukan[i].namaAtom, masukan[j].namaAtom, masukan[k].namaAtom, total_noAtom, total_power, rasio);
                    // selectionSort(n, masukan, rasio);
                    strcpy(hasil[ihasil].namaAtom, masukan[i].namaAtom);
                    strcpy(hasil[ihasil].namaAtom1, masukan[j].namaAtom);
                    strcpy(hasil[ihasil].namaAtom2, masukan[k].namaAtom);
                    hasil[ihasil].rasio = rasio;
                    hasil[ihasil].totalAtom = total_noAtom;
                    hasil[ihasil].totalPerfoma = total_power;
                    ihasil++;
                }
            }
        }
    }

}

int binarySearch(int n, atomfusion fusion[]){
    int i = 0, j = n -1, mid;
    int found = 0;

    while(found == 0 && i <= j){
        mid = (i + j) / 2;
        if(fusion[mid].rasio == 3){
            found = 1;
        }else{
            if(fusion[mid].rasio >= 3){
                j = mid - 1;
            }else{
                i = mid + 1;
            }
        }
    }
    return found;
}

void printHasil(int n, atomfusion fusion[],int found){
    printf("Hasil Seleksi:\n");
    int i =0;
    int ii =0;
    while (i < n){
        if (fusion[i].rasio > 1.5) {
            printf("No: %d\n",ii+1);
            printf("{%s, %s, %s}\n",fusion[i].namaAtom,fusion[i].namaAtom1,fusion[i].namaAtom2);
            printf("TotalNoAtom: %d\n",fusion[i].totalAtom);
            printf("TotalPerforma: %d\n",fusion[i].totalPerfoma);
            printf("Rasio: %.2f\n",fusion[i].rasio);
            ii++;
        } 
        i++;
    }

    if (found == 1) {
        printf("ada kombinasi barang dengan rasio tepat 3 kali lipat James T. Kirk berhasil menghancurkan starship Narada\n");
    } else {
        printf("Tidak ada kombinasi atom dengan rasio tepat 3 kali lipat James T. Kirk gagal menghancurkan starship Narada\n");
    }
}

void printHasil2(int n, atomfusion fusion[],int found){
    printf("Hasil Seleksi:\n");

    for(int i = 0; i < n; i++){
        if (fusion[i].rasio > 1.5) {
            printf("No: %d\n",i+1);
            printf("{%s, %s, %s}\n",fusion[i].namaAtom,fusion[i].namaAtom1,fusion[i].namaAtom2);
            printf("TotalNoAtom: %d\n",fusion[i].totalAtom);
            printf("TotalPerforma: %d\n",fusion[i].totalPerfoma);
            printf("Rasio: %.2f\n",fusion[i].rasio);
        } else {
            i--;
        }
    }

    if (found == 1) {
        printf("ada kombinasi barang dengan rasio tepat 3 kali lipat James T. Kirk berhasil menghancurkan starship Narada\n");
    } else {
        printf("Tidak ada kombinasi atom dengan rasio tepat 3 kali lipat James T. Kirk gagal menghancurkan starship Narada\n");
    }
}


int main(){
    int n,n_fusion,ketemu;
    scanf("%d", &n);
    n_fusion = 0;
    

    atom masukan[n];
    atomfusion hasil[n*n]; // dimensi nya random karena gatau ada berapa kombinasinya 

    for(int i = 0; i < n; i++){
        scanf("%s %d %d", &masukan[i].namaAtom, &masukan[i].noAtom, &masukan[i].formaAtom);
    }

    sequentialSearch(n,masukan,hasil);

    printf("\n");

    for(int i = 0; i < n*n; i++){ // ngitung ada berapa yg keisi di hasil struct 
        if (strlen(hasil[i].namaAtom1) != 0 && hasil[i].rasio > 1.5){
            n_fusion++; // dapet jumlah struct yg keisi
        }
    }

    bubbleSort(hasil, n_fusion);

    ketemu = binarySearch(n_fusion,hasil);

    printHasil(n_fusion,hasil,ketemu);


    return 0;
}
