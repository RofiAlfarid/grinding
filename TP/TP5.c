/*
Saya Revana Faliha Salma [2202869] mengerjakan soal TP5 dalam mata kuliah Algoritma dan Pemrograman 2 
untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>

int i;

typedef struct{
    int magicPower;
    int time;
    char name[100];
    int panjang;
    int digitmp,digittime;
}mantra;

int countdigits(int num){
    int count = 0;
    do
    {
        count++;
        num /= 10;
    } while(num != 0);

    return count;
}


void printdash(int n){
     for(i = 0; i < n; i++){
        printf("-");
     }
}

void printspasi(int n){
     for(i = 0; i < n; i++){
        printf(" ");
     }
}

void garisprinter(int maxname){
    printf("+");
    printdash(4);
    printf("+");
    printdash(maxname + 3);
    printf("+");
    printdash(13);
    printf("+");
    printdash(7);
    printf("+\n");
}

void judulprinter(int maxname){
    printf("|");
    printf(" No "); // ini asumsi kalo inputnya cuman sampe 99, kalo udah ratusan bakal geser dikit si > 99 makanya spasinya langsunf di print
    printf("|");
    printf(" Nama Mantra "); 
    printspasi(maxname - 10); // ini buat ngitung harus print berapa spasi buat mengakomodasi string isi mantra nya lebih dari string judul nya angka 10 dateng dari jumlah char "Nama Mantra" 11 di kurangi kan di line 59 udah ngeprint spasi satu jadi 11-1 = 10 -> berarti cara bacanya line 59-60 "print nama mantra nah print spasinya buat max nama mantar dikurangi char dari judul "nama mantra" 
    printf("|");
    printf(" Magic Power "); // ini jugamasih static si spasinya, drawback nya kalo mp nya lebih dari char masgic power yaa dia akan menceng
    printf("|");
    printf(" Waktu "); // ini juga masih static bakalan menceng kalo time nya leih dari 4 digit
    printf("|\n");
}

void spellprinter(mantra sihir[], int n, int maxname){
    int ii = 0;
    garisprinter(maxname); // print garis doang
    judulprinter(maxname); // print judul doang
    garisprinter(maxname); // print garis doang
    for(ii = 0; ii < n; ii++){
        printf("| %d",ii);
        printspasi(3 - countdigits(ii)); // angka 3 itu dateng dari kita pokoknya nyediain lahan 3
        printf("| %s  ",sihir[ii].name);
        printspasi(maxname - strlen(sihir[ii].name)); // print spasi berdasarkan pengurangan maxname dari semua spell dikurang spell si ii, misal nama spell paling panjang ExpectoPatronum = 15 char, dan kalo spell ke ii adalah lumos = char 5 yaa sisanya berarti print spasinya 15 - 5 = 10
        printf("| %d ",sihir[ii].magicPower);
        printspasi(11 - sihir[ii].digitmp); // angka 11 juga dapet dari panjang char judulnya, ini gak plus satu soalnya udah ada spasi tambahan di line 78 seabis %d  
        printf("| %d",sihir[ii].time);
        printspasi(6 - sihir[ii].digittime); // angka 6 juga dapet dari panjang char judul + 1, plus 1 karena harus print spasi tambahan di terakhir
        printf("|\n");
    }
    garisprinter(maxname); // print garis doang
}

void bubbleBig(int n, mantra sihir[]){
    int swap; //deklarasi variabel apakah ditukar
    char tempName[100];   //deklarasi penampung
    int tempMP;
    int tempTime;

    do {

        for(i = 0; i < n; i++){
            sihir[i].panjang = strlen(sihir[i].name);
        }

        swap = 0; // inisialisasi variabel tukar diset 0
        for (i = 0; i < n-1; i++) { 
            if(sihir[i].panjang < sihir[i+1].panjang) { 
                strcpy(tempName, sihir[i].name);
                strcpy(sihir[i].name, sihir[i + 1].name);
                strcpy(sihir[i + 1].name, tempName);

                tempMP = sihir[i].magicPower;
                sihir[i].magicPower = sihir[i + 1].magicPower;
                sihir[i + 1].magicPower = tempMP;
                
                tempTime = sihir[i].time;
                sihir[i].time = sihir[i + 1].time;
                sihir[i + 1].time = tempTime;
                
                swap = 1;
            }
        }
    }while (swap  == 1);   //Kondisi berjalan selama tukar bernilai 1
}

void bubbleSmall(int n, mantra sihir[]){
    int swap; //deklarasi variabel apakah ditukar
    char tempName[100];   //deklarasi penampung
    int tempMP;
    int tempTime;

    do {
        for(i = 0; i < n; i++){
            sihir[i].panjang = strlen(sihir[i].name);
        }

        swap = 0; // inisialisasi variabel tukar diset 0
        for (i = 0; i < n-1; i++) { 
            if(sihir[i].panjang > sihir[i+1].panjang) { 

                strcpy(tempName, sihir[i].name);
                strcpy(sihir[i].name, sihir[i + 1].name);
                strcpy(sihir[i + 1].name, tempName);

                tempMP = sihir[i].magicPower;
                sihir[i].magicPower = sihir[i + 1].magicPower;
                sihir[i + 1].magicPower = tempMP;
                
                tempTime = sihir[i].time;
                sihir[i].time = sihir[i + 1].time;
                sihir[i + 1].time = tempTime;
                
                swap = 1;
            }
        }
    }while (swap  == 1);   //Kondisi berjalan selama tukar bernilai 1
}

void quickBig(int n, mantra sihir[n], int kiri, int kanan) {
    char temp[100]; //Dekalrasi penampung
    int i = kiri;   //Deklarasi i = kiri
    int j = kanan;  //Deklarasi j = kanan
    int temp1;
    int temp2;

    int pivot = sihir[(kanan+kiri)/2].panjang;    //Nilai pivot diisi dari kanan+kiri dibagi 2
    int pivotmp = sihir[(kanan+kiri)/2].magicPower;

    //Algoritma Quick Sort Tengah
    do {
        while((sihir[i].panjang > pivot) && (i <= j)) {
            //Mencegah i berjalan terlau jauh melewati batas j
            i++;
        }
        while((sihir[j].panjang < pivot) && (i <= j)) {
            //mencegah j berjalan terlau jauh melewati batas i
            j--;
        }
        if(i < j) {
            // tukar data name
            strcpy(temp, sihir[i].name);
            strcpy(sihir[i].name, sihir[j].name);
            strcpy(sihir[j].name, temp);

            // tukar data magicPower
            temp1 = sihir[i].magicPower;
            sihir[i].magicPower = sihir[j].magicPower;
            sihir[j].magicPower = temp1;

            // tukar data time
            temp2 = sihir[i].time;
            sihir[i].time = sihir[j].time;
            sihir[j].time = temp2;

            i++;
            j--;
        }
    } while(i < j);


    if(kiri < j && j < kanan) {
        quickBig(n, sihir, kiri, j);
    }
    if(i < kanan && i > kiri) {
        quickBig(n, sihir, i, kanan);
    }
}

void quickSmall(int n, mantra sihir[n], int kiri, int kanan) {
    char temp[100]; //Dekalrasi penampung
    int i = kiri;   //Deklarasi i = kiri
    int j = kanan;  //Deklarasi j = kanan
    int temp1;
    int temp2;

    int pivot = sihir[(kanan+kiri)/2].panjang;    //Nilai pivot diisi dari kanan+kiri dibagi 2
    int pivotmp = sihir[(kanan+kiri)/2].magicPower;

    //Algoritma Quick Sort Tengah
    do {
        while((sihir[i].panjang < pivot ) && (i <= j)) {
            //Mencegah i berjalan terlau jauh melewati batas j
            i++;
        }
        while((sihir[i].panjang > pivot ) && (i <= j)) {
            //mencegah j berjalan terlau jauh melewati batas i
            j--;
        }
        if(i < j) {
            // tukar data name
            strcpy(temp, sihir[i].name);
            strcpy(sihir[i].name, sihir[j].name);
            strcpy(sihir[j].name, temp);

            // tukar data magicPower
            temp1 = sihir[i].magicPower;
            sihir[i].magicPower = sihir[j].magicPower;
            sihir[j].magicPower = temp1;

            // tukar data time
            temp2 = sihir[i].time;
            sihir[i].time = sihir[j].time;
            sihir[j].time = temp2;

            i++;
            j--;
        }
    } while(i < j);


    if(kiri < j && j < kanan) {
        quickSmall(n, sihir, kiri, j);
    }
    if(i < kanan && i > kiri) {
        quickSmall(n, sihir, i, kanan);
    }
}

int main(){
    int n;
    int maxname = 0;
    scanf("%d", &n);

    mantra sihir[n];
    int i;
    for(i = 0; i < n; i++){
        scanf("%s %d %d", &sihir[i].name, &sihir[i].magicPower, &sihir[i].time);
        
        if (maxname < strlen(sihir[i].name)){
            maxname = strlen(sihir[i].name);
        }

        sihir[i].digitmp = countdigits(sihir[i].magicPower);
        sihir[i].digittime = countdigits(sihir[i].time);
    }

    char typeSorting;
    char urutan[50];
    int limit;

    scanf(" %c", &typeSorting);
    scanf("%s", &urutan);
    scanf("%d", &limit);

    for(int ii = 0; ii < n; ii++){
        sihir[ii].panjang = strlen(sihir[ii].name);
    }


    if(typeSorting == 'b'){
        if(strcmp(urutan, "Besar") == 0){
            bubbleBig(n, sihir);
        }else if(strcmp(urutan, "Kecil") == 0){
            bubbleSmall(n, sihir);
        }
    }else if(typeSorting == 'q'){
        if(strcmp(urutan, "Besar") == 0){
            quickBig(n, sihir, 0, n-1);
        }else if(strcmp(urutan, "Kecil") == 0){
            quickSmall(n, sihir, 0, n-1);
        }
    }

    printf("\n\n");
    spellprinter(sihir, n, maxname);


    return 0;
}