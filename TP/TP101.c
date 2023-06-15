/*
Saya Revana Faliha Salma [2202869] mengerjakan soal TP10 dalam mata kuliah Algoritma dan Pemrograman 2 
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>

typedef struct { 
  int IsEncrypt, IsNormal, IsKeyword; // tiap kata punya atribut apakah dia encrypted, normal, atau keyword
  char Word[100]; // save per kata nya ntar disini
}kata; // definisi kata dalam konteks TP10

kata words[100];
char codename;
int digit, numkata;

void splitTeks(char tape[100]){

    int key = 0; // anggap semua kata bukan encrypt normal atau key
 // indeks buat iterate dan indeks buat si kata dan indeks buat char di dalam masing masing struct kata
    int lenKata = 0; // ini buat panjang per kata nya 
    int i = 0;
    int ki = 0;
    int encrypt = 0;
    int ii = 0;
    int normal = 0;
    kata tmp;

    
    // proses detect kata
    while (tape[i] != ';'){ // iterate teroos sampe akhir bang
        if (tape[i-1] == ';'){
            break;
        }
        while (tape[i] != ' ' && tape[i] != ';') { // iterate sampe ketemu spasi, kalo ketemu spasi berarti itu dianggap kata kan ?
            char c = tape[i];
            tmp.Word[ii] = c; // tambah char nya terus sebelum ketemu spasi mah biar ntar pas ketemu ngebentuk kata
            lenKata ++; // tambah len kata saat ini karena udah nambah char diatas

            // detect encrypted gak 
            if (tape[i] == codename) { // cek sama gak kek codename
                tmp.IsEncrypt = 1; // kalo sama flag encrypt nya jadiin satu
                tmp.IsNormal = 0; // kalo encrypted berarti bukan normal
            }
            ii++; //indeks buat iterasi char di tape terusain
            i++;
        }

        // jangan lupa set terminating nulll di akhir word dan  
        tmp.Word[ii] = '\0'; // ii karena di akhir iterate sebelum tau spasi udah nambah duluan si indeksnya 

        // nah disini pas udah ketemu spasi berarti udah satu kata kan, cek lagi length nya sama kek mod dari codename gak 
        if (lenKata <= digit && tmp.IsEncrypt == 1) {
            tmp.IsEncrypt = 0; // kalo kurang dari mod ganti flag encrypt jadi gak encrypt
            tmp.IsNormal = 1; // bukan encrypted tapi jadi normal
        }

        if (tmp.IsEncrypt == 0) {
            tmp.IsNormal = 1;
        }

        words[ki] = tmp; // copy semua dari tmp

        // after copy reset semua value agar tidak terbawa value sebelumnya ke iterasi selanjutnya
        tmp.IsEncrypt = 0;
        tmp.IsNormal = 0;
        tmp.IsKeyword = 0;

        // nah karena satu kata udah kedetect berarti ++ in indeks yg harus di ++
        ki++;
        i++;

        // proses rest var yg harus direset
        lenKata=0; // reset panjang kata karena mau ada kata baru 
        ii=0;// reset indeks char nya karena mau ada kata baru 

    }
    // wrd[ki]->Word[ii] = '\0'; // ii karena di akhir iterate sebelum tau spasi udah nambah duluan si indeksnya 
    numkata = ki;

}


void cekKeyword(){
    for (int i = 1; i < numkata -1; i++) {
        if (words[i-1].IsEncrypt == 1 && words[i+1].IsEncrypt == 1 && words[i].IsNormal == 1) { // ini kalo diapit oleh encrup maka keyword
            words[i].IsKeyword = 1;
        }
    }
}

void printEncryptKata(){
    printf("\nKATA TERENKRIPSI\n");
    int cnt = 0;
    for (int i=0;i < numkata; i++){
        if (words[i].IsEncrypt ==1){
            cnt++;
            printf("- %s\n",words[i].Word);
        }
    }

    if (cnt == 0){
        printf("Kosong.\n");
    }
}

void printKeyKata(){
    printf("\nKATA KUNCI\n");
    int cnt = 0;
    for (int i=0;i < numkata; i++){
        if (words[i].IsKeyword ==1) {
            cnt++;
            printf("- %s\n",words[i].Word);
        }
    }
    if (cnt == 0){
        printf("Kosong.\n");
    }
}

void printNormalKata(){
    printf("\nKATA BIASA\n");
    int cnt = 0;
    for (int i=0;i < numkata; i++){
        if (words[i].IsKeyword == 0 && words[i].IsNormal == 1) {
            cnt++;
            printf("- %s\n",words[i].Word);
        }
    }
    if (cnt == 0){
        printf("Kosong.\n");
    }
}

int main()
{
    // deklarasi variabel pita
    char tape[101];
    int i, j;
    

    // meminta masukan
    scanf("%c\n", &codename);
    scanf("%100[^\n]s", &tape);

    // mengetahui panjang minimal kata
    digit = codename % 10;

    // break kalimat itu dan assign attribute sesuai kata tersebut 
    splitTeks(tape);
    cekKeyword();

    printEncryptKata();
    printKeyKata();
    printNormalKata();
    


    return 0;
}