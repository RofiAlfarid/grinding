/*
Saya Revana Faliha Salma [2202869] mengerjakan soal TP6 dalam mata kuliah Algoritma dan Pemrograman 2 
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>

int i;
char temp1[100];
int temp2;
char temp3[100];


typedef struct{
    char name[100];
    int power;
    char spell[100];
    char tanda;
}sihir;

void printspasi(int n){
    for(i = 0; i < n; i++){
        printf(" ");
    }
}

void sorting(int n, sihir murid[], char tipe[]){
    if(strcmp(tipe, "Spell") == 0){
        for (i = 1; i < n; i++)
        {
            // memasukan nilai data dengan indeks i ke dalam temp
            strcpy(temp1, murid[i].name);                                  
            temp2 = murid[i].power;
            strcpy(temp3, murid[i].spell);

            int j = i - 1;
            while (j >= 0 && (strcmp(temp3, murid[j].spell) < 0))
            {
                // memasukan nilai data dengan indeks j ke dalam data dengan indeks j+1
                strcpy(murid[j+1].name, murid[j].name);                         
                murid[j+1].power = murid[j].power;
                strcpy(murid[j+1].spell, murid[j].spell);   
                j--;
            }
            // memasukan nilai temp ke dalam data dengan indeks j+1
            strcpy(murid[j+1].name, temp1);                                
            murid[j+1].power = temp2;
            strcpy(murid[j+1].spell, temp3);  

        }
    }else if(strcmp(tipe, "Power") == 0){
        for (i = 1; i < n; i++)
        {
            // memasukan nilai data dengan indeks i ke dalam temp
            strcpy(temp1, murid[i].name);                                  
            temp2 = murid[i].power;
            strcpy(temp3, murid[i].spell);

            int j = i - 1;
            while (j >= 0 && temp2 > murid[j].power)
            {
                // memasukan nilai data dengan indeks j ke dalam data dengan indeks j+1
                strcpy(murid[j+1].name, murid[j].name);                         
                murid[j+1].power = murid[j].power;
                strcpy(murid[j+1].spell, murid[j].spell);   
                j--;
            }
            // memasukan nilai temp ke dalam data dengan indeks j+1
            strcpy(murid[j+1].name, temp1);                                
            murid[j+1].power = temp2;
            strcpy(murid[j+1].spell, temp3);  

        }
    }

}

void merge(int n1, int n2, sihir murid1[], sihir murid2[], sihir murid12[], char tipe[]){
    if(strcmp(tipe, "Spell") == 0){
        int i1 = 0, i2 = 0, i12 = 0;

        // ulangi hingga murid1 habis atau murid2 habis
        while ((i1 < n1) && (i2 < n2))
        {
            // jika elemen teratas murid1 lebih kecil dari murid2
            if (strcmp(murid1[i1].spell, murid2[i2].spell) <= 0 )
            {
                // masukkan elemen teratas murid1 ke dalam murid12
                strcpy(murid12[i12].name, murid1[i1].name);
                murid12[i12].power = murid1[i1].power;
                strcpy(murid12[i12].spell, murid1[i1].spell);
                murid12[i12].tanda = murid1[i1].tanda;
                i12++;
                i1++;
            }
            // jika elemen teratas murid1 lebih besar dari murid2
            else
            {
                // masukkan elemen teratas murid2 ke dalam murid12
                strcpy(murid12[i12].name, murid2[i2].name);
                murid12[i12].power = murid2[i2].power;
                strcpy(murid12[i12].spell, murid2[i2].spell);
                murid12[i12].tanda = murid2[i2].tanda;
                i12++;
                i2++;
            }
        }


        // masukkan sisa murid1 jika ada
        while(i1 < n1)
        {
            // pemindahan nilai data di sebelah kanan ke dalam data di selebah kiri
            strcpy(murid12[i12].name, murid1[i1].name);
            murid12[i12].power = murid1[i1].power;
            strcpy(murid12[i12].spell, murid1[i1].spell);
            murid12[i12].tanda = murid1[i1].tanda; // INI GANTI GAAAN !!
            i12++;
            i1++;
        }
        // masukkan sisa murid2 jika ada
        while(i2 < n2)
        {
            // pemindahan nilai data di sebelah kanan ke dalam data di selebah kiri
            strcpy(murid12[i12].name, murid2[i2].name);
            murid12[i12].power = murid2[i2].power;
            strcpy(murid12[i12].spell, murid2[i2].spell);
            murid12[i12].tanda = murid2[i2].tanda;
            i12++;
            i2++;
        }

    }else if(strcmp(tipe, "Power") == 0){
        int i1 = 0, i2 = 0, i12 = 0;

        // ulangi hingga murid1 habis atau murid2 habis
        while ((i1 < n1) && (i2 < n2))
        {
            // jika elemen teratas murid1 lebih kecil dari murid2
            if (murid1[i1].power >= murid2[i2].power)
            {
                // masukkan elemen teratas murid1 ke dalam murid12
                strcpy(murid12[i12].name, murid1[i1].name);
                murid12[i12].power = murid1[i1].power;
                strcpy(murid12[i12].spell, murid1[i1].spell);
                murid12[i12].tanda = murid1[i1].tanda;
                i12++;
                i1++;
            }
            // jika elemen teratas murid1 lebih besar dari murid2
            else
            {
                // masukkan elemen teratas murid2 ke dalam murid12
                strcpy(murid12[i12].name, murid2[i2].name);
                murid12[i12].power = murid2[i2].power;
                strcpy(murid12[i12].spell, murid2[i2].spell);
                murid12[i12].tanda = murid2[i2].tanda;
                i12++;
                i2++;
            }
        }


        // masukkan sisa murid1 jika ada
        while(i1 < n1)
        {
            // pemindahan nilai data di sebelah kanan ke dalam data di selebah kiri
            strcpy(murid12[i12].name, murid1[i1].name);
            murid12[i12].power = murid1[i1].power;
            strcpy(murid12[i12].spell, murid1[i1].spell);
            murid12[i12].tanda = murid1[i1].tanda;
            i12++;
            i1++;
        }
        // masukkan sisa murid2 jika ada
        while(i2 < n2)
        {
            // pemindahan nilai data di sebelah kanan ke dalam data di selebah kiri
            strcpy(murid12[i12].name, murid2[i2].name);
            murid12[i12].power = murid2[i2].power;
            strcpy(murid12[i12].spell, murid2[i2].spell);
            murid12[i12].tanda = murid2[i2].tanda;
            i12++;
            i2++;
        }
    }
        
}

void output(int n, sihir murid[], int maxname){
    int i = 0;
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n");
    printf("= A L L   W I Z A R D S =\n");
    for(i = 0; i < n; i++){
        printf("%s ", murid[i].name);
        printspasi(maxname - strlen(murid[i].name));
        printf("%c ", murid[i].tanda);
        printf("%d ", murid[i].power);
        printf("%s\n", murid[i].spell);
    }
    printf("\n");

}

int battlelineup(int n, sihir murid[], int minpow, int maxname, int pow){
    int i = 0;
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n");
    printf("= B A T T L E   L I N E U P =\n");

    for(i ; i < n; i++){

        if (pow - murid[i].power >= minpow){
            printf("%s ", murid[i].name);
            printspasi(maxname - strlen(murid[i].name));
            printf("%c ", murid[i].tanda);
            printf("%d ", murid[i].power);
            printf("%s\n", murid[i].spell);
            pow -= murid[i].power;
        } else {
            return pow;
        }
    }

    return pow;

}


int totalPower(int n, sihir murid[]){
    int totPower = 0;
    for(i = 0; i < n; i++){
        totPower += murid[i].power;
    }
    return totPower;
}

void battlePower(int n, sihir murid[]){
    int totBattle = 0;
    for(i = 0; i < n; i++){
        totBattle += murid[i].power;
    }
    printf("Battle Power     : %d\n", totBattle);
}

void EvPower(int n, sihir murid[]){
    int totEv = 0;
    for(i = 0; i < n; i++){
        totEv += murid[i].power;
    }
    printf("Evacuation Power : %d\n", totEv);
}


int main(){
    int minPower;
    char typeSort[100];
    int maxname = 0;
    int maxpower = 0;

    int power = 0;

    int n1;
    scanf("%d", &n1);
    sihir murid1[n1];
    for(i = 0; i < n1; i++){
        scanf("%s %d %s", &murid1[i].name, &murid1[i].power, &murid1[i].spell);
        murid1[i].tanda = '@';
        // kondisi untuk mencari jumlah karakter terbanyak pada nama murid
        if (maxname < strlen(murid1[i].name)){
            maxname = strlen(murid1[i].name);
        }

        power += murid1[i].power;

    }

    int n2;
    scanf("%d", &n2);
    sihir murid2[n2];
    for(i = 0; i < n2; i++){
        scanf("%s %d %s", &murid2[i].name, &murid2[i].power, &murid2[i].spell);
        murid2[i].tanda = '&';
        // kondisi untuk mencari jumlah karakter terbanyak pada nama murid
        if (maxname < strlen(murid2[i].name)){
            maxname = strlen(murid2[i].name);
        }
    }

    int n12 = n1 + n2;
    sihir murid12[n12];

    int n3;
    scanf("%d", &n3);
    sihir murid3[n3];
    for(i = 0; i < n3; i++){
        scanf("%s %d %s", &murid3[i].name, &murid3[i].power, &murid3[i].spell);
        murid3[i].tanda = '!';
        // kondisi untuk mencari jumlah karakter terbanyak pada nama murid
        if (maxname < strlen(murid3[i].name)){
            maxname = strlen(murid3[i].name);
        }
    }

    int n123 = n12 + n3;
    sihir murid123[n123];

    int n4;
    scanf("%d", &n4);
    sihir murid4[n4];
    for(i = 0; i < n4; i++){
        scanf("%s %d %s", &murid4[i].name, &murid4[i].power, &murid4[i].spell);
        murid4[i].tanda = '$';
        // kondisi untuk mencari jumlah karakter terbanyak pada nama murid
        if (maxname < strlen(murid4[i].name)){
            maxname = strlen(murid4[i].name);
        }
    }

    int n1234 = n123 + n4;
    sihir murid1234[n1234];

    scanf("%d", &minPower);
    
    scanf("%s", &typeSort);

    printf("\n");

    sorting(n1, murid1, typeSort);
    sorting(n2, murid2, typeSort);
    merge(n1, n2, murid1, murid2, murid12, typeSort);
    sorting(n3, murid3, typeSort);
    merge(n12, n3, murid12, murid3, murid123, typeSort);
    sorting(n4, murid4, typeSort);
    merge(n123, n4, murid123, murid4, murid1234, typeSort);

    output(n1234, murid1234, maxname);

    power = totalPower(n1234, murid1234);

    int defpow = battlelineup(n1234,murid1234,minPower,maxname, power);

    printf("\n");
    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");
    printf("\n");
    printf("= P O W E R   S T A T I S T I C S =\n");
    printf("Total Power      : %d\n",power);
    printf("Battle Power     : %d\n",power - defpow);
    printf("Evacuation Power : %d\n",defpow);

    printf("*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*`*-,_,-*\n");

    return 0;
}