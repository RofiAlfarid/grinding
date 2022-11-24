#include <stdio.h>


struct barang {
  int Stok;
  char Nama[20];
};


int main (void) {
    int tests, num;
    int id_c = 0;
    int base = 1;
    char c;
    char i_name[100];
    char bin1[25], bin2[25];
    char binn1[] = "1 1 1 1 1 1 0 .";
    char binn2[] = "1 0 1 0 .";

    scanf("%d\n", &tests);

    struct barang bar[tests];

    int i=0;
    while(id_c < tests) {

        // ini ngescaf tiap char terus simpen ke struct
        while(1) {
            scanf("%c ",&c);
            if (c != ';'){
                if (c != ' ') { //copy abjad nya aja
                    bar[id_c].Nama[i] = c;
                }
            } else {
                break;
            }
            i++;
        }

        // copy bit string 1
        i = 0;
        while(1) {
            scanf("%c ",&c);
            if (c != '.'){
                if (c != ' ') { //copy abjad nya aja
                    bin1[i] = c;
                }
            } else {
                break;
            }
            i++;
        }

        // copy bit string 2
        i = 0;
        while(1) {
            scanf("%c ",&c);
            if (c != '.'){
                if (c != ' ') { //copy abjad nya aja
                    bin2[i] = c;
                }
            } else {
                break;
            }
            i++;
        }

        // ambil size tiap string untuk tau size string baru untuk ngegabungin nya 
        int sbin1 = sizeof(bin1);
        int sbin2 = sizeof(bin2);
        char gabung[sbin1+sbin2];
        i = 0; // set ke 0 lagi soalnya mau dipake lagi buat index
        int lst_i = 0;

        // iterate string pertama dan copy tiap char ke array baru
        while (i < sizeof(bin1)-1) {
            gabung[i] = bin1[i];
            if ((bin1[i] == '1') || (bin1[i] == '0')) {
                lst_i = i;
            }
            i++;
        }

        int j = 0;
        lst_i++;

        // iterate string kedua dan copy tiap char ke array baru dengan melanjutkan index sebelumnya 
        while (j < sizeof(bin2)) {
            gabung[lst_i] = bin2[j];
            lst_i++;
            j++;
        }

        int g = sizeof(gabung);

        // ini buat convert binary jadi integer
        while (g > 0)
        {
            if (gabung[g] == '1') {
                num = num + 1 * base;  
                base = base * 2;
            } else if (gabung[g] == '0') {
                base = base * 2;
            }
            g--;
            
        }

        bar[id_c].Stok = num;

        base = 1;
        num = 0;
        id_c++;
        i = 0;

    }

    char code;
    int min_stok;

    // copy barang dulu sebelum di kurangin buat di tampilin di awal
    struct barang awal[tests];
    i = 0;
    while(i < tests){
        awal[i] = bar[i];
        i++;
    }

    while (1)
    {
        // tampung inputan buat pengurangan
        scanf("%c %d\n",&code,&min_stok);
        if (code == '*'){
            break;
        }

        // cari awalan huruf sama yg udah di input diatas pastikan huruf besar kecil sama
        int i = 0;
        while(i < tests) {
            if (bar[i].Nama[0] == code) { // match char kesatu dengan nama awalan barang
                bar[i].Stok = bar[i].Stok - min_stok; // kalo match kurangin stoknya
                break; // break biar gak nyari terus ke bawah, kalo gak pake break danawalannya mungkin sama di 2 barang dua duanya bakal di kurangin
            }
            i++;
        }
    }
    
    // tampilin awal barang
    printf("\n\nStok barang awal\n");
    i = 0;
    while(i < tests){
        printf("Nama Barang : %s\n",awal[i].Nama);
        printf("Jumlah Stok Barang : %d\n",awal[i].Stok);
        i++;
    }

    // tampilin awal barang
    printf("\nStok barang akhir\n");
    i = 0;
    while(i < tests){
        printf("Nama Barang : %s\n",bar[i].Nama);
        if (bar[i].Stok < 0) {
            printf("Keterangan Barang : barang tidak aman, barang kurang %d buah\n",bar[i].Stok * -1); // kali -1 biar jadi positif di tampilin
        } else {
            printf("Keterangan Barang : barang aman, Sisa barang %d buah\n",bar[i].Stok);
        }
        i++;
    }
    

}
