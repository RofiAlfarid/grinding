#include <stdio.h>
#include <string.h>

void pola1(char fill, int thick) {

    int row = 5*thick, col = 3*thick;

    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (i <= thick || i > row-thick){
                printf(" ");
            }else {
                if ((j <= thick || j > col-thick) && (i <= thick*2 || i > row-thick*2)){
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
            }
        }
        printf("\n");
    }
}

void pola2 (char fill, int thick){
    int row = 5*thick, col = 3*thick;

    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j <= thick){
                if (i <= thick*2 || i > row - thick*2){
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
            }else {
                int x = col - thick*2;
                if (j > col - thick && (i <= thick || i > row - thick)){
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
            }
        }
        printf("\n");
    }
}


void pola3 (char fill, int thick){
    int row = 5*thick, col = 3*thick;

    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j > col - thick){ // ini buat kolom ketiga
                printf("%c",fill);
            } else if (j <= thick) { // ini buat kolom pertama
                if (i <= 3*thick || i > 4*thick){
                    printf(" ");
                }else{
                    printf("%c",fill);
                }
            } else { // ini buat kolom ditengah

                if (i <= 2*thick || (i > 3*thick && i <= 4*thick)){
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
                
            }
        }
        printf("\n");
    }

}
void pola4(char fill, int thick){
    int row = 5*thick, col = 3*thick;
    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j <= thick || j > 2*thick ){
                if (i<= thick || i > row - thick){
                    printf(" ");
                }else {
                    printf("%c",fill);
                }
            }else {
                if (i > thick && i <= row - thick) {
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
            }
        }
        printf("\n");
    }

}

void pola5(char fill, int thick){ // ide nya adalah kan ada 3 kolom, bagi pola per kolom nya, kalo udah di bagi misal kolom 1 kek gimana tinggal ngurusin barisnya mau gimana 

    int row = 5*thick, col = 3*thick;
    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j <= thick || j > col - thick){
                if ((i > thick && i <= 2*thick) || (i > 3*thick && i <= 4*thick)) {
                    printf("%c",fill);
                }else {
                    printf(" ");
                }
            } else {
                if ((i > thick && i <= 2*thick) || (i > 3*thick && i <= 4*thick)) {
                    printf(" ");
                }else {
                    printf("%c",fill);
                }
            }
        }
        printf("\n");
    }
}


void pola6(char fill, int thick){

    int row = 5*thick, col = 3*thick;
    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j > col - thick){ // ini buat kolom ketiga
                if (i <= 3*thick || i > 4*thick){
                    printf(" ");
                }else{
                    printf("%c",fill);
                }
            } else if (j <= thick) { // ini buat kolom pertama
                printf("%c",fill);
            } else { // ini buat kolom ditengah

                if (i <= 2*thick || (i > 3*thick && i <= 4*thick)){
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
                
            }
        }
        printf("\n");
    }
}


void pola7 (char fill, int thick){ // ide nya adalah kan ada 3 kolom, bagi pola per kolom nya, kalo udah di bagi misal kolom 1 kek gimana tinggal ngurusin barisnya mau gimana 
    int row = 5*thick, col = 3*thick;

    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j > col - thick){ // ini buat kolom terakhir
                if (i <= 2*thick) { // ini untuk baris yg mau di print, tar ganti * jadi %c char nya aja jadi bisa custom mau print H atau yg lain 
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
                
            } else if (j <= thick) { // ini buat kolom pertama
                if (i <= 3*thick || i > 4*thick){ // ini untuk baris yg mau di print, tar ganti * jadi %c char nya aja jadi bisa custom mau print H atau yg lain 
                    printf(" ");
                }else{
                    printf("%c",fill);
                }
            } else { // ini buat kolom ditengah

                if (i <= 2*thick || (i > 3*thick && i <= 4*thick)){ // ini untuk baris yg mau di print, tar ganti * jadi %c char nya aja jadi bisa custom mau print H atau yg lain 
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
                
            }
        }
        printf("\n");
    }

}

void pola8 (char fill, int thick){ // ide nya adalah kan ada 3 kolom, bagi pola per kolom nya, kalo udah di bagi misal kolom 1 kek gimana tinggal ngurusin barisnya mau gimana 
    int row = 5*thick, col = 3*thick;

    for (int i = 1; i<= row; i++){
        for (int j=1; j<= col; j++){
            if (j <= 2*thick){
                if ((i > thick && i <= 2*thick) || (i > 3*thick && i <= 4*thick)) {
                    printf(" ");
                }else {
                    printf("%c",fill);
                }
            } else {
                if ((i > thick && i <= 2*thick) || (i > 3*thick && i <= 4*thick)) {
                    printf("%c",fill);
                }else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}

void pola9 (char fill, int thick){ // ide nya adalah kan ada 3 kolom, bagi pola per kolom nya, kalo udah di bagi misal kolom 1 kek gimana tinggal ngurusin barisnya mau gimana 
    int row = 5*thick, col = 3*thick; // set canvas seluas base kali ketebalan 

    for (int i = 1; i<= row; i++){ // counter buat panjang baris
        for (int j=1; j<= col; j++){ // counter buat panajng kolom
            if (j <= thick) { // ini untuk kolom pertama 
                if (i <= thick){ // ini untuk baris yg mau di print, tar ganti * jadi %c char nya aja jadi bisa custom mau print H atau yg lain 
                    printf("%c",fill);
                } else {
                    printf(" ");
                }
            } else if (j > 2*thick) { // ini untuk kolom ketiga
                if (i > thick*2 && i <= thick*3){
                    printf("%c",fill);
                }else {
                    printf(" ");
                }
            } else { // ini untuk kolom di tengah 
                if (i <= thick){ 
                    printf(" ");
                } else {
                    printf("%c",fill);
                }
            }
        }
        printf("\n");
    }
}

void printKode(char kata[], int tebal) {

    if (strcmp(kata,"tolong") == 0) {
        pola1('H',tebal);
    }

    if (strcmp(kata,"kirim") == 0) {
        pola2('H',tebal);
    } 

    if (strcmp(kata,"berita") == 0) {
        pola3('H',tebal);
    } 

    if (strcmp(kata,"kosong") == 0) {
        pola4('H',tebal);
    } 

    if (strcmp(kata,"matamata") == 0) {
        pola5('H',tebal);
    } 

    if (strcmp(kata,"pasukan") == 0) {
        pola6('H',tebal);
    } 

    if (strcmp(kata,"aman") == 0) {
        pola7('H',tebal);
    } 

    if (strcmp(kata,"masuk") == 0) {
        pola8('H',tebal);
    } 

    if (strcmp(kata,"tahan") == 0) {
        pola9('H',tebal);
    } 
}