#include <stdio.h>
#include <string.h>

int indeks; // indeks karakter
char cc,cb,ca;    // cb => char before, cc => current char , ca => char after
char code;

void START (char pita[]){
    indeks = 0;
    cc = pita[indeks];
}

char Kapital (char karakter) {
    if (karakter >= 'a' && karakter <='z'){
        return karakter - ('a'-'A');
    }
    return karakter;
}

int IsVocal(char chr){
    switch (chr)
    {
        case 'a':
           return 1;
            break;
        case 'i':
            return 1;
            break;
        case 'u':
            return 1;
            break;
        case 'e':
            return 1;
            break;
        case 'o':
            return 1;
            break;
        case 'A':
           return 1;
            break;
        case 'I':
            return 1;
            break;
        case 'U':
            return 1;
            break;
        case 'E':
            return 1;
            break;
        case 'O':
            return 1;
            break;
    }

    return 0;
}

int CHECKCODE(){
    int check = 0;
    if ((Kapital(cc) == Kapital(code)) && (IsVocal(ca) && (IsVocal(cb)))) {
        return 1;
    }

    return 0;
}

int EOP(){
    if(ca == ';'){
        return 1;
    }else{
        return 0;
    }
}

void ADV(char pita[]){
    indeks++;
    cb = cc;
    cc = pita[indeks];
    ca = pita[indeks+1];
    while((cc == ' ') && (EOP() == 0)){
        indeks++;
        cc = pita[indeks];
    }

    int i = indeks + 1;

    while((ca == ' ') && (EOP() == 0)){
        i++;
        ca = pita[i];
    }
}

char GETCC(){
    return cc;
}

int main(){
    // deklarasi variabel pita
    char pita[100];


    // meminta masukan pita
    printf("Masukan pita : ");
    scanf("%99[^\n]s", &pita);


    // memulai mesin dan membaca pita
    START(pita);
    code = GETCC();
    while (EOP() == 0)
    { 
        // maju ke karakter selanjutnya
        ADV(pita);

        // jika EOP bernilai salah, maka...
        if(EOP() == 0){
            // jika karakter yang berada di tampungan adalah m dan karakter selajutnya adalah a, maka...
            if(CHECKCODE() == 1){
                printf("Pesan rahasia yg dikirim oleh codename %c\n",code);
                return 0;
            }
        } 
    }

    printf("Bukan Pesan Rahasia\n",code);


    return 0;
}