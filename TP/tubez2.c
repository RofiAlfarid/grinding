/*
Saya Revana Faliha Salma [2202869] mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
Pemrograman II untuk keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char noPelanggan[50]; // Deklarasi variabel yang digunakan untuk menampung nama barang
    char nama[50]; // Deklarasi variabel yang digunakan untuk menampung kode Kategori
    char noTelepon[50]; // Deklarasi variabel yang digunakan untuk menampung kode Toko
    char kodeProduk[50]; // Deklarasi variabel yang digunakan untuk menampung kode ketegori, merk serta kode
    char namaProduk[100]; // Deklarasi variabel yang digunakan untuk menampung nama ketegori, merk serta kode
    char jenisProduk[50];
    int harga;
    char kodeJenis[50];
    char namaJenis[50];
}data; // Deklarasi bungkusan untuk menampung dataListBarang

data dataPelanggan[100];
data dataProduk[100];
data dataJenis[100];

// Deklarasi variabel global
int idx;     // index dari karakter terakhir pada kata
int wlen;    // panjang kata (word length)
char cw[50]; // kata saat ini (current word)
int a11;
int a12;
int a13;

// Bagian untuk memulai, mereset, dan mengakhiri mesin kata
void start(char str[]);
void reset();
int eop(char str[]);

// Bagian memajukan mesin kata
void inc(char str[]);

// Bagian mendapatkan variabel global/atribut mesin kata
int getlen();
char *getcw();
int EOPCMD(char str[]);

void start(char str[])
{
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;


    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }


    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }


    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses
int eop(char str[])
{
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Prosedur untuk memajukan kata
void inc(char str[])
{
    // inisialisasi ulang panjang kata
    wlen = 0;


    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }


    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }


    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}


// Fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}

int EOPCMD(char str[]){

    if (strcmp(str,"jangan lupa bahagian hari ini") == 0) {
        return 1;
    }
    return 0;
}

void writeToFileJenis(int a13, data data[], char filename[])
{
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "a"); // buka file dengan mode write

        fprintf(fTemp, "%s %s\n", // tulis 4 kolom lalu beri newline
                data[a13].kodeJenis,
                data[a13].namaJenis);


    // "tutup file"
    fclose(fTemp);
}

void writeToFilePelanggan(int a11, data data[], char filename[])
{
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "a"); // buka file dengan mode write
   
    // tulis data ke file
        fprintf(fTemp, "%s %s %s\n", // tulis 4 kolom lalu beri newline
                data[a11].noPelanggan,
                data[a11].nama,
                data[a11].noTelepon);



    // // berikan EOF di akhir file
    // fprintf(fTemp, "%s %s %s\n", "####", "####", "####");


    // "tutup file"
    fclose(fTemp);
}

void writeToFileProduk(int a12, data data[], char filename[])
{
    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "a"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < a12; i++)
    {
        fprintf(fTemp, "%s %s %s %d\n", // tulis 4 kolom lalu beri newline
                data[i].kodeProduk,
                data[i].namaProduk,
                data[i].jenisProduk,
                data[i].harga);
    }

    // "tutup file"
    fclose(fTemp);
}

void writedata(char str[], data dataPelanggan[], data dataProduk[], data dataJenis[]){
    inc(str);
    if(strcmp(getcw(), "tpelanggan") == 0){
        // a11 = 0;

        inc(str);
        strcpy(dataPelanggan[a11].noPelanggan, getcw());

        inc(str);
        strcpy(dataPelanggan[a11].nama, getcw());

        inc(str);
        strcpy(dataPelanggan[a11].noTelepon, getcw());

        writeToFilePelanggan(a11, dataPelanggan, "tpelanggan.dat");
    }else if(strcmp(getcw(), "tproduk") == 0){
        // int a12 = 0;

        inc(str);
        strcpy(dataProduk[a12].kodeProduk, getcw());

        inc(str);
        strcpy(dataProduk[a12].namaProduk, getcw());

        inc(str);
        strcpy(dataProduk[a12].jenisProduk, getcw());

        inc(str);
        dataProduk[a12].harga = atoi(getcw());

        writeToFileProduk(a12, dataProduk, "tproduk.dat");
    }else if(strcmp(getcw(), "tjenis") == 0){
        // int a13 = 0;

        inc(str);
        strcpy(dataJenis[a13].kodeJenis, getcw());

        inc(str);
        strcpy(dataJenis[a13].namaJenis, getcw());

        writeToFileJenis(a13, dataJenis, "tjenis.dat");
    }
}

void dumpfileProduk(char filename[], data dataProduk[]){

    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < a12; i++)
    {
        fprintf(fTemp, "%s %s %s %d\n", // tulis 4 kolom lalu beri newline
                dataProduk[i].kodeProduk,
                dataProduk[i].namaProduk,
                dataProduk[i].jenisProduk,
                dataProduk[i].harga);
    }

    // "tutup file"
    fclose(fTemp);
}

void dumpfilePelanggan(char filename[], data datapelanggan[]){

    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < a11; i++)
    {
        fprintf(fTemp, "%s %s %s\n", // tulis 4 kolom lalu beri newline
                datapelanggan[i].noPelanggan,
                datapelanggan[i].nama,
                datapelanggan[i].noTelepon);

    }

    // "tutup file"
    fclose(fTemp);
}

void dumpfileJenis(char filename[], data datajenis[]){

    FILE *fTemp; // pointer ke file
    fTemp = fopen(filename, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < a13; i++)
    {
        fprintf(fTemp, "%s %s\n", // tulis 4 kolom lalu beri newline
                datajenis[i].kodeJenis,
                datajenis[i].namaJenis);
    }

    // "tutup file"
    fclose(fTemp);
}

void readFile(char str[], data dataPelanggan[], data dataProduk[], data dataJenis[]){
    inc(str);
    if(strcmp(getcw(), "tpelanggan") == 0){
        // a11 = 0;

        FILE *fTemp;
        fTemp = fopen("tpelanggan.dat", "r"); // buka file dengan mode read

        while (fscanf(fTemp, "%s %s %s", dataPelanggan[a11].noPelanggan, dataPelanggan[a11].nama, dataPelanggan[a11].noTelepon) != EOF) {
            a11++; // Maju ke indeks penampung berikutnya
        }

            printf("Data Pelanggan(%d):\n", a11);
            for (int i = 0; i < a11; i++)
            {
                printf("%s %s %s\n",
                    dataPelanggan[i].noPelanggan,
                    dataPelanggan[i].nama,
                    dataPelanggan[i].noTelepon);
            }
            printf("\n");

        // "tutup file"
        fclose(fTemp);
    }else if(strcmp(getcw(), "tproduk") == 0){
        // int a12 = 0;
        FILE *fTemp;
        fTemp = fopen("tproduk.dat", "r"); // buka file dengan mode read

        while (fscanf(fTemp, "%s %s %s %d", dataProduk[a12].kodeProduk, dataProduk[a12].namaProduk, dataProduk[a12].jenisProduk, &dataProduk[a12].harga) != EOF) {
            a12++; // Maju ke indeks penampung berikutnya
        }

            printf("Data Produk(%d):\n", a12);
            for (int i = 0; i < a12; i++)
            {
                printf("%s %s %s %d\n",
                    dataProduk[i].kodeProduk,
                    dataProduk[i].namaProduk,
                    dataProduk[i].jenisProduk,
                    dataProduk[i].harga);
            }
            printf("\n");

        // "tutup file"
        fclose(fTemp);
    }else if(strcmp(getcw(), "tjenis") == 0){
        // int a13 = 0;
        FILE *fTemp;
        fTemp = fopen("tjenis.dat", "r"); // buka file dengan mode read
        
        while (fscanf(fTemp, "%s %s", dataJenis[a13].kodeJenis, dataJenis[a13].namaJenis) != EOF) {
            a13++; // Maju ke indeks penampung berikutnya
        }

            printf("Data Jenis Produk(%d):\n", a13);
            for (int i = 0; i < a13; i++)
            {
                printf("%s %s\n",
                    dataJenis[i].kodeJenis,
                    dataJenis[i].namaJenis);
            }
            printf("\n");

        // "tutup file"
        fclose(fTemp);
    }
    
}

void updateData(char str[], data dataPelanggan[], data dataProduk[], data dataJenis[]) {
    inc(str);
    char namafile[100];

    strcpy(namafile,getcw());

    if (strcmp(getcw(), "tpelanggan") == 0) {

        FILE *fTemp;
        fTemp = fopen("tpelanggan.dat", "r"); // buka file dengan mode read

        inc(str);
        char noPelanggan[50];
        strcpy(noPelanggan, getcw());
        
        int index = -1;

        while (fscanf(fTemp, "%s %s %s", dataPelanggan[a11].noPelanggan, dataPelanggan[a11].nama, dataPelanggan[a11].noTelepon) != EOF) {
            a11++; // Maju ke indeks penampung berikutnya
        }
        
        // Cari indeks data dengan nomor pelanggan yang sesuai
        int jumlahData = 0;
        while (strlen(dataPelanggan[jumlahData].noPelanggan) != 0) {
            if (strcmp(dataPelanggan[jumlahData].noPelanggan, noPelanggan) == 0) {
                index = jumlahData;
                break;
            }
            jumlahData++;
        }
        
        // Jika indeks ditemukan
        if (index != -1) {
            inc(str);
            char nama[50];
            strcpy(nama, getcw());
            
            // Update data pelanggan
            strcpy(dataPelanggan[index].nama, nama);

            dumpfilePelanggan("tpelanggan.dat",dataPelanggan);
            
            printf("Data Pelanggan dengan nomor %s telah diubah.\n", noPelanggan);
        } else {
            printf("Data dengan nomor pelanggan %s tidak ditemukan.\n", noPelanggan);
        }

        fclose(fTemp);

    }else if(strcmp(getcw(), "tproduk") == 0){
        FILE *fTemp;
        fTemp = fopen("tproduk.dat", "r"); // buka file dengan mode read

        inc(str);
        char code[50];
        strcpy(code, getcw());
        
        int index = -1;

        while (fscanf(fTemp, "%s %s %s %d", dataProduk[a12].kodeProduk, dataProduk[a12].namaProduk, dataProduk[a12].jenisProduk, &dataProduk[a12].harga) != EOF) {
            a12++; // Maju ke indeks penampung berikutnya
        }
        
        // Cari indeks data dengan nomor pelanggan yang sesuai
        int jumlahData = 0;
        while (strlen(dataProduk[jumlahData].kodeProduk) != 0) {
            if (strcmp(dataProduk[jumlahData].kodeProduk, code) == 0) {
                index = jumlahData;
                break;
            }
            jumlahData++;
        }
        
        // Jika indeks ditemukan
        if (index != -1) {
            inc(str);
            char nameProduk[50];
            strcpy(nameProduk, getcw());
            
            // Update data pelanggan
            strcpy(dataProduk[index].namaProduk, nameProduk);
            dumpfileProduk("tproduk.dat",dataProduk);
            
            printf("Data dengan nomor %s telah diubah.\n", code);
        } else {
            printf("Data dengan nomor %s tidak ditemukan.\n", code);
        }

        fclose(fTemp);

    }else if(strcmp(getcw(), "tjenis") == 0){
        FILE *fTemp;
        fTemp = fopen("tjenis.dat", "r"); // buka file dengan mode read

        inc(str);
        char jenis[50];
        strcpy(jenis, getcw());
        
        int index = -1;

        while (fscanf(fTemp, "%s %s", dataJenis[a13].kodeJenis, dataJenis[a13].namaJenis) != EOF) {
            a13++; // Maju ke indeks penampung berikutnya
        }
        
        // Cari indeks data dengan nomor pelanggan yang sesuai
        int jumlahData = 0;
        while (strlen(dataJenis[jumlahData].kodeJenis) != 0) {
            if (strcmp(dataJenis[jumlahData].kodeJenis, jenis) == 0) {
                index = jumlahData;
                break;
            }
            jumlahData++;
        }
        
        // Jika indeks ditemukan
        if (index != -1) {
            inc(str);
            char names[50];
            strcpy(names, getcw());
            
            // Update data pelanggan
            strcpy(dataJenis[index].namaJenis, names);
            dumpfileJenis("tjenis.dat",dataJenis);
            
            printf("Data Pelanggan dengan nomor %s telah diubah.\n", jenis);
        } else {
            printf("Data dengan nomor pelanggan %s tidak ditemukan.\n", jenis);
        }

        fclose(fTemp);

    }
    
}

void deleteData(char str[], data dataPelanggan[], data dataProduk[], data dataJenis[]){
    inc(str); // maju satu kata
        if (strcmp(getcw(), "tpelanggan") == 0) // lalu di cek apakah kata selanjutnya tersebut adalah "mahasiswa" atau bukan
        { // jika iya maka
            inc(str); // maju satu kata
            int found = 0, ind; // variabel penanda true or false untuk ketemunya nim yang dicari di perintah tersebut, dan menandakan indeks tersebut
            data tmppel[100];

            FILE *fTemp;
            fTemp = fopen("tpelanggan.dat", "r"); // buka file dengan mode read

            while (fscanf(fTemp, "%s %s %s", tmppel[a11].noPelanggan, tmppel[a11].nama, tmppel[a11].noTelepon) != EOF) {
                if (strcmp(getcw(),tmppel[a11].noPelanggan) == 0){
                    found = 1;
                } else {
                    dataPelanggan[a11-found] = tmppel[a11]; // ini buat ngurang indeks nya karena kan di hapus jadi geser kesebelumnya ketika udah dound
                }
                a11++; // Maju ke indeks penampung berikutnya
            }

            if (found == 0) // jika nim nya tidak ketemu
            {
                printf("tidak ada data yang dimaksud!\n");
            } else {
                a11--; // ini biar looping di dump file nya gak melebihi karena kan udah di kurang atu

                dumpfilePelanggan("tpelanggan.dat",dataPelanggan);
                printf("Pelanggan Yth %s Telah di hapus di tpelanggan.dat, Thank You !\n",getcw());
            } 

        }else if(strcmp(getcw(), "tproduk") == 0){
            inc(str); // maju satu kata
            int found = 0, ind; // variabel penanda true or false untuk ketemunya nim yang dicari di perintah tersebut, dan menandakan indeks tersebut
            data tmpproduk[100];

            FILE *fTemp;
            fTemp = fopen("tproduk.dat", "r"); // buka file dengan mode read

            while (fscanf(fTemp, "%s %s %s %d", tmpproduk[a12].kodeProduk, tmpproduk[a12].namaProduk, tmpproduk[a12].jenisProduk, &tmpproduk[a12].harga) != EOF) {
                if (strcmp(getcw(),tmpproduk[a12].kodeProduk) == 0){
                    found = 1;
                } else {
                    dataProduk[a12-found] = tmpproduk[a12]; // ini buat ngurang indeks nya karena kan di hapus jadi geser kesebelumnya ketika udah dound
                }
                a12++; // Maju ke indeks penampung berikutnya
            }

            if (found == 0) // jika nim nya tidak ketemu
            {
                printf("tidak ada data yang dimaksud!\n");
            } else {
                a12--; // ini biar looping di dump file nya gak melebihi karena kan udah di kurang atu

                dumpfileProduk("tproduk.dat",dataProduk);
                printf("Ploduk %s Telah di hapus di tproduk.dat, Thank You !\n",getcw());
            }

        }else if(strcmp(getcw(), "tjenis") == 0){
            inc(str); // maju satu kata
            int found = 0, ind; // variabel penanda true or false untuk ketemunya nim yang dicari di perintah tersebut, dan menandakan indeks tersebut
            data tmpjen[100];

            FILE *fTemp;
            fTemp = fopen("tjenis.dat", "r"); // buka file dengan mode read

            while (fscanf(fTemp, "%s %s", tmpjen[a13].kodeJenis, tmpjen[a13].namaJenis) != EOF) {
                if (strcmp(getcw(),tmpjen[a13].kodeJenis) == 0){
                    found = 1;
                } else {
                    dataJenis[a13-found] = tmpjen[a13]; // ini buat ngurang indeks nya karena kan di hapus jadi geser kesebelumnya ketika udah dound
                }
                a13++; // Maju ke indeks penampung berikutnya
            }

            if (found == 0) // jika nim nya tidak ketemu
            {
                printf("tidak ada data yang dimaksud!\n");
            } else {
                a13--; // ini biar looping di dump file nya gak melebihi karena kan udah di kurang atu

                dumpfileJenis("tjenis.dat",dataJenis);
                printf("Jenis %s Telah di hapus di tjenis.dat, Thank You !\n",getcw());
            }

        }
}


void pilihan(char str[], data dataPelanggan[], data dataProduk[], data dataJenis[]){
    start(str);
    if(strcmp(getcw(), "ISI") == 0){
        writedata(str, dataPelanggan, dataProduk, dataJenis);
    }else if(strcmp(getcw(), "TAMPIL") == 0){
        readFile(str, dataPelanggan, dataProduk, dataJenis);
    }else if(strcmp(getcw(), "UBAH") == 0){
        updateData(str, dataPelanggan, dataProduk, dataJenis);
    }else if(strcmp(getcw(), "HAPUS") == 0){
        deleteData(str, dataPelanggan, dataProduk, dataJenis);
    }else if(strcmp(getcw(), "ISI UBAH") == 0){
        
    }else if(EOPCMD(str) == 0){
        printf("thank u sudah menggunakan dbms rere!\n");
    }else{
        printf("maap tidak ada pilihan yang Anda maksud!\n");
    }
}

// void pilih(char str[], data dataPelanggan[], data dataProduk[], data dataJenis[]){
//     // start(str);
//     if(str[wlen-1] == ';'){
//         start(str);
//         if(strcmp(getcw(), "ISI") == 0){
//             writedata(str, dataPelanggan, dataProduk, dataJenis);
//         }else if(strcmp(getcw(), "TAMPIL") == 0){
//             readFile(str, dataPelanggan, dataProduk, dataJenis);
//         }else if(strcmp(getcw(), "UBAH") == 0){
//             updateData(str, dataPelanggan, dataProduk, dataJenis);
//         }else if(strcmp(getcw(), "HAPUS") == 0){
//             deleteData(str, dataPelanggan, dataProduk, dataJenis);
//         }else if(strcmp(getcw(), "ISI UBAH") == 0){
            
//         }else{
//             printf("maap tidak ada pilihan yang Anda maksud!\n");
//         }
//     }else if(str[wlen-1] != ';'){
//         printf("maaf sintaks error!\n");
//     }
// }

int main(){

    char str[200];

    printf("Welcome to DBMS UMKM Fashion Revana!\nVersi 1.0\n\n");

    do{
        printf("rere's dbms>");
        scanf(" %199[^\n]s", str);
        wlen = strlen(str);

        if(str[wlen-1] == ';'){
            pilihan(str, dataPelanggan, dataProduk, dataJenis);
        }else if(str[wlen-1] != ';'){
            printf("maaf sintaks error!\n");
        }

        // pilih(str, dataPelanggan, dataProduk, dataJenis);

    }while(EOPCMD(str) == 0);

    printf("thank u sudah menggunakan dbms rere!\n"); 

    return 0;
}
