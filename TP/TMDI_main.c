#include <stdio.h>
#include <string.h>
#include "TMDI_machine2.c"

int cektolong(char kata2[]) { // cek kata tolong
    char kata[] = "tolong";
    int l = 6;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekkirim(char kata2[]) { // cek kata tolong
    char kata[] = "kirim";
    int l = 5;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekberita(char kata2[]) { // cek kata tolong
    char kata[] = "berita";
    int l = 6;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekkosong(char kata2[]) { // cek kata tolong
    char kata[] = "kosong";
    int l = 6;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekmatamata(char kata2[]) { // cek kata tolong
    char kata[] = "matamata";
    int l = 8;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekpasukan(char kata2[]) { // cek kata tolong
    char kata[] = "pasukan";
    int l = 7;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekaman(char kata2[]) { // cek kata tolong
    char kata[] = "aman";
    int l = 4;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cekmasuk(char kata2[]) { // cek kata tolong
    char kata[] = "masuk";
    int l = 6;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

int cektahan(char kata2[]) { // cek kata tolong
    char kata[] = "tahan";
    int l = 6;
    for (int i = 0; i < l; i++){
        if (kata[i] != kata2[i]) {
            return 0;
        }
    }
    return 1;
}

void transtring(char pool_str[][50], char tmp[][50], int lentmp,int pre_trans, int post_trans ) { // ini bener gaak logic nyaa 
    for (int i = 0; i < lentmp; i++){
        if (strcmp(pool_str[pre_trans],tmp[i]) == 0) {
            strcpy(tmp[i],pool_str[post_trans-1]);
            return;
        }
    }
}

void printkodesamping(int thick, int jum_baris,char tmp[][50]){
    int row = 5*thick, col = 3*thick;
    for (int i = 0; i<row; i++){
        for(int k = 0; k < jum_baris; k++){
            for(int j=1; j<=col; j++){
                printKodeside(tmp[k],thick,'H',i,j,row,col);
            }
            printf("|||");
        }
        printf("\n");
    }
}

int main (void){

    // ini buat coba coba cek prosedur
    // char x = 'H';
    // pola9(x,1);
    // char c[] = "tolong";
    // int v = -1;
    // v = cektolong(c);
    // printf("%d\n",v);

    // printKode("tolong",2);

    // end of coba coba prosedur 

    // int jum_baris, jum_trans, after_trans,thickness,i = 0;

    // scanf("%d",&jum_baris); // ambil input untuk jumlah baris
    // char str_baris[jum_baris][50];

    // for(i = 0; i< jum_baris; i++){
    //     scanf("%s",&str_baris[i]);
    // }

    // scanf("%d",&jum_trans); // ambil input untuk jumlah transisi
    // int arr_trans[jum_trans];
    // char tmp[jum_trans][50];

    // for(i = 0; i < jum_trans; i++){
    //     scanf("%d",&arr_trans[i]);
    //     strcpy(tmp[i],str_baris[arr_trans[i]]);
    // }

    // scanf("%d",&after_trans); // ambil input untuk transisi string
    // int pre_trans, post_trans;

    // for(i = 0; i < after_trans; i++){
    //     scanf("%d %d",&pre_trans,&post_trans);
    //     transtring(str_baris,tmp,jum_trans,pre_trans,post_trans); // prosedur mentarnsisikan dari string sebelum ke sesuadah, ini masih gak ngerti coba benerin :))
    // }

    // scanf("%d",&thickness); // ambil input untuk ketebalan

    // for (int i = 0; i < jum_trans; i++) {
    //     printf("%s  ",tmp[i]); // print baris yg urutannya inputan kedua tiap line transisi
    //     // printKode(str_baris[arr_trans[i]-1],thickness);
    // }

    // printf("\n");

    int thickness = 2;
    int jum_baris = 3;
    char x[3][50];

    strcpy(x[0], "tolong");
    strcpy(x[1], "kirim");
    strcpy(x[2], "berita");

    printkodesamping(thickness,jum_baris,x);

    // for (int i = 0; i < jum_trans; i++) {
    //     printKode(tmp[i],thickness);
    //     printf("\n\n");
    // }
    
}