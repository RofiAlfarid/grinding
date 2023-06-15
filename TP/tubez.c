/*
Saya Revana Faliha Salma [2202869] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
Pemrograman II untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>
#include <string.h>


int indeks;				//variabel untuk indeks pada pita
int panjangkata;		//variabl untuk menampung panjang pita
char ckata [50];		//variabel untuk menampung kata pada pita
char semuacmd[100][10]; // variable buat nampung semua perintah yg diketahui
char command[100][10];
char tmpc[100];

typedef struct{
    char noPelanggan[50]; // Deklarasi variabel yang digunakan untuk menampung nama barang
    char nama[50]; // Deklarasi variabel yang digunakan untuk menampung kode Kategori
    char noTelepeon[50]; // Deklarasi variabel yang digunakan untuk menampung kode Toko
} pelanggan; // Deklarasi bungkusan untuk menampung dataListBarang

typedef struct{
    char kodeProduk[50]; // Deklarasi variabel yang digunakan untuk menampung kode ketegori, merk serta kode
    char namaProduk[100]; // Deklarasi variabel yang digunakan untuk menampung nama ketegori, merk serta kode
    char jenisProduk[50];
    char deskripsi[200];
    float harga;
} produk; // Deklarasi bungkusan untuk menampung dataKategori, dataMerk, serta dataKode

typedef struct{
    char kodeJenis[50];
    char namaJenis[50];
}jenis;

int jumlahTerpanjang1, jumlahTerpanjang2, jumlahTerpanjang3, jumlahTerpanjang4;  // Deklarasi variabel yang digunakan untuk menghitung jumlah terpanjang

pelanggan dataPelanggan[100];
produk dataProduk[100];

void STARTKATA(char pita[]){
    indeks = 0;
    panjangkata = 0;
    while (pita[indeks] == ' ')
    {
        indeks++;
    }
    while ((pita[indeks] != ' ') && (pita[indeks] != ';'))
    {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    ckata[panjangkata] = '\0';
}

// Fungsi untuk membaca kata selanjutnya dari pita
void INCKATA(char pita[]){
    panjangkata = 0;
    while (pita[indeks] == ' ')
    {
        indeks++;
    }
    while ((pita[indeks] != ' ') && (pita[indeks] != ';'))
    {
        ckata[panjangkata] = pita[indeks];

        indeks++;
        panjangkata++;
    }
    ckata[panjangkata] = '\0';
}

//fungsi untuk EOP pada pita
int EOP (char pita []){
	if (pita [indeks] == '.'){		//membuat kondisi jika pita adalah EOP
		return 1;					//mengembalikan nilai 1
	}else {
		return 0;					//mengembalikan nilai 0
	}
}


int EOPCMD(char pita[]){

    if (strcmp(pita,"udahan;") == 0) {
        return 1;
    }
    return 0;
}

int EOPKATA(char pita[]){

    if (EOPCMD(pita) == 1){
        return 1;
    }

    int i = 0;
    while(pita[i] != '\0'){
        if (pita[i] == ';'){
            pita[i] == '\0';
            return 1;
        }
        i++;
    }
    return 0;
}

int IsCommand(char pita[]){
    for (int i =0; i < 4; i++) { // 4 karena jumlah daftar cmd yg diketahui nya 4
        if (strcmp(semuacmd[i], pita) == 0){
            return 1;
        }
    }
    return 0;
}

void DaftarCmd(){
    strcpy(semuacmd[0],"ISI");
    strcpy(semuacmd[1],"TAMPIL");
    strcpy(semuacmd[2],"UBAH");
    strcpy(semuacmd[3],"HAPUS");
}

int AffhUdahAda(char key[], char namafile[]) {
    int nF = 0; 
    char tmpPel[100];
    char tmpNoTelp[100];
    char tmpName[100];
    FILE *pail;                  // pointer ke file
    pail = fopen(namafile, "r"); // buka file dengan mode read

    nF = fscanf(pail, "%s %s %s ",&tmpPel,&tmpName,&tmpNoTelp);

    if (strcmp(tmpPel, "####") == 0 || EOF == nF){
        // FILE *bikin; 
        // bikin = fopen(namafile, "a");
        // fclose(bikin);
        return 0;
    }

    if (strcmp(tmpPel, key) == 0){
            fclose(pail);
            return 1;
    }

    while (strcmp(tmpPel, "####") != 0) {
        fscanf(pail, "%s %s %s ",tmpPel,&tmpName,&tmpNoTelp);

        if (strcmp(tmpPel, key) == 0){
            fclose(pail);
            return 1;
        }
    }

    fclose(pail);

    return 0;
}

void cleancmd(){
    int i = 0;
    while(tmpc[i] != '\0'){
        if (tmpc[i] == ';'){
            tmpc[i] = '\0';
            return;
        }
        i++;
    }
}

void BacaFilePelanggan(char namafile[]){
    int ic = 0;
    int cek = 0;
    FILE *pail;                  // pointer ke file
    pail = fopen(namafile, "r"); // buka file dengan mode write

    cek = fscanf(pail, "%s %s %s ",&dataPelanggan[ic].noPelanggan,&dataPelanggan[ic].nama,&dataPelanggan[ic].noTelepeon);

    if (strcmp(dataPelanggan[ic].noPelanggan, "####") == 0 || cek == EOF){
        strcpy(dataPelanggan[ic].noPelanggan, "####");
        return;
    }

    while (strcmp(dataPelanggan[ic].noPelanggan, "####") != 0) {
        ic++;
        fscanf(pail, "%s %s %s ",&dataPelanggan[ic].noPelanggan,&dataPelanggan[ic].nama,&dataPelanggan[ic].noTelepeon);
    }

    fclose(pail);

}

void BacaFileProduk(char namafile[]){
    int ic = 0;
    int cek = 0;
    FILE *pail;                  // pointer ke file
    pail = fopen(namafile, "r"); // buka file dengan mode write

    cek = fscanf(pail, "%s %s %s %s %f",&dataProduk[ic].kodeProduk,&dataProduk[ic].namaProduk,&dataProduk[ic].jenisProduk, &dataProduk[ic].deskripsi, &dataProduk[ic].harga);

    if (strcmp(dataProduk[ic].kodeProduk, "####") == 0 || cek == EOF){
        strcpy(dataProduk[ic].kodeProduk, "####");
        return;
    }

    while (strcmp(dataProduk[ic].kodeProduk, "####") != 0) {
        ic++;
        fscanf(pail, "%s %s %s %s %f",&dataProduk[ic].kodeProduk,&dataProduk[ic].namaProduk,&dataProduk[ic].jenisProduk, &dataProduk[ic].deskripsi, &dataProduk[ic].harga);
    }

    fclose(pail);

}

void TulisdipailPelanggan(char namafile[]){
    FILE *pail;                  // pointer ke file
    pail = fopen(namafile, "w"); // buka file dengan mode write

    int ic = 0;

    while (strcmp(dataPelanggan[ic].noPelanggan,"####")) {
        fprintf(pail, "%s %s %s\n", dataPelanggan[ic].noPelanggan, dataPelanggan[ic].nama, dataPelanggan[ic].noTelepeon);
        ic++;
    }

    fprintf(pail, "%s %s %s\n", command[2], command[3], command[4]);
    fprintf(pail, "%s %s %s\n", "####", "####", "####");

    fclose(pail);
}

void TulisdipailProduk(char namafile[]){
    FILE *pail;                  // pointer ke file
    pail = fopen(namafile, "w"); // buka file dengan mode write

    int ic = 0;

    while (strcmp(dataProduk[ic].kodeProduk,"####")) {
        fprintf(pail, "%s %s %s %s %.2f\n", dataProduk[ic].kodeProduk, dataProduk[ic].namaProduk, dataProduk[ic].jenisProduk, dataProduk[ic].deskripsi, dataProduk[ic].harga);
        ic++;
    }

    fprintf(pail, "%s %s %s %s %s\n", command[2], command[3], command[4],command[5],command[6]);
    fprintf(pail, "%s %s %s %s %.2f\n", "####", "####", "####","####",-1);

    fclose(pail);
}

void RunPerintah(){

    if(IsCommand(command[0]) == 0) { // cek apakah command pertama terkenali 
        printf("\nPerintah Tak dikenali gan\n");
        return;
    }

    if (strcmp(command[0],"ISI") == 0) { // cek apakah command pertama "ISI" atau engga

        if (strcmp(command[1],"tpelanggan") == 0) { // cek file apa yg mau diisi 
            if (AffhUdahAda(command[2],"tpelanggan.dat") == 1) {
                printf("Udah Ada");
                return;
            }

            BacaFilePelanggan("tpelanggan.dat");
            TulisdipailPelanggan("tpelanggan.dat");
        } else if (strcmp(command[1],"tproduk") == 0){
            if (AffhUdahAda(command[2],"tproduk.dat") == 1) {
                printf("Udah Ada");
                return;
            }

            BacaFileProduk("tproduk.dat");
            TulisdipailProduk("tproduk.dat");
        }

    } else if (strcmp(command[0],"TAMPIL") == 0) {

        if (strcmp(command[1],"tpelanggan") == 0) { // cek file apa yg mau tampil 
            
        } else if (strcmp(command[1],"tproduk") == 0){
            
        }

    } else if (strcmp(command[0],"UBAH") == 0) {

        if (strcmp(command[1],"tpelanggan") == 0) { // cek file apa yg mau ubah 
            
        } else if (strcmp(command[1],"tproduk") == 0){
            
        }
        
    } else if (strcmp(command[0],"HAPUS") == 0) {

        if (strcmp(command[1],"tpelanggan") == 0) { // cek file apa yg mau hapus 
            
        } else if (strcmp(command[1],"tproduk") == 0){
            
        }
        
    }
}

int main(){
    int a11 = 0;
    int a2 = 0;
    DaftarCmd(); // ini daftarin semau command yg bisa di recognize

    // readFile(&a1, dataPelanggan, "tpelanggan.dat");

    // inputData(a2, dataPelanggan, "tpelanggan.dat");

    // printFromFile(dataPelanggan);
    int jumlahcmd = 0;

    char perintah[100];
    char cmd[100];
    // BacaFile("tpelanggan.dat");

    printf("\nWelcome to DBMS UMKM Revana\n");
    printf("Versi 1.0\n");
    do {
        printf("dbms Revana>");
        
        do {
            scanf("%s", &perintah);
            strcpy(tmpc, perintah); // ini copy tampung dulu biar bisa di bersihin pake global variable 
            cleancmd(); // ini ngehapus ; biar bersih pass write di file
            strcpy(command[jumlahcmd], tmpc); // ini copy data input ke cmd 
            jumlahcmd ++; 
        } while (EOPKATA(perintah) == 0);
        RunPerintah(); // ini run perintah berdasarkan global variable  command jadi pas disini si cmd bakalan niputan user misal ISI tproduk PK01 nama produk jenis desc 2000; cmd nya bakalan ["ISI","tproduk","nama","produk","jenis","desc","2000"]
        printf("\n"); // buat string message ajaa disnin mah
        jumlahcmd = 0; // buat nimpah cammnad sebelumnya karena indeksnya kemabli ke 0
    } while (EOPCMD(perintah) == 0);

    printf("Yaudah !");

    return 0;
}
