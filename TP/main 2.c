#include <stdio.h>
#include <string.h>

typedef struct 
{
    char name[50];
    char size[50];
    int numericSize;
}mhs;

typedef struct 
{
    char nama1[100], nama2[100];
}tukar;


void fillNumSize(mhs *siswa){

    if (strcmp("XS",siswa->size) == 0){
        siswa->numericSize = 32;
    } else if (strcmp("S",siswa->size)==0){
        siswa->numericSize = 36;
    } else if (strcmp("M",siswa->size)==0){
        siswa->numericSize = 37;
    } else if (strcmp("L",siswa->size)==0){
        siswa->numericSize = 38;
    } else if (strcmp("XL",siswa->size)==0){
        siswa->numericSize = 40;
    } else if (strcmp("XXL",siswa->size)==0){
        siswa->numericSize = 42;
    } else if (strcmp("XXXL",siswa->size)==0){
        siswa->numericSize = 45;
    }
}


int main(){
    int n;
    int m;
    scanf("%d %d", &n, &m);

    mhs data[n][m];

    int baris, kolom, maxchar = 0;
    for(baris = 0; baris < n; baris++){
        for(kolom = 0; kolom < m; kolom++){
            scanf("%s %s", &data[baris][kolom].name, &data[baris][kolom].size);

            fillNumSize(&data[baris][kolom]);
            if (sizeof(data[baris][kolom].name) > maxchar){
                maxchar = sizeof(data[baris][kolom].name);
            }

            // if (strcmp("XS",data[baris][kolom].size) == 0){
            //     data[baris][kolom].numericSize = 32;
            // } else if (strcmp("S",data[baris][kolom].size)==0){
            //     data[baris][kolom].numericSize = 36;
            // } else if (strcmp("M",data[baris][kolom].size)==0){
            //     data[baris][kolom].numericSize = 37;
            // } else if (strcmp("L",data[baris][kolom].size)==0){
            //     data[baris][kolom].numericSize = 38;
            // } else if (strcmp("XL",data[baris][kolom].size)==0){
            //     data[baris][kolom].numericSize = 40;
            // } else if (strcmp("XXL",data[baris][kolom].size)==0){
            //     data[baris][kolom].numericSize = 42;
            // } else if (strcmp("XXXL",data[baris][kolom].size)==0){
            //     data[baris][kolom].numericSize = 45;
            // }
        }
    }
    
    tukar tempat[100];
    
    int i = 0;
    int cek = 0;
    do{
        scanf("%s", &tempat[i].nama1);
        if(strcmp(tempat[i].nama1, "Selesai") == 0){
            cek = 1;
        }else{
            scanf("%s", &tempat[i].nama2);
        }
        i++;
    }while(cek == 0);

    printf("\nPosisi awal :\n");
    for(baris = 0; baris < n; baris++){
        for(kolom = 0; kolom < m; kolom++){
            printf("%s", data[baris][kolom].name);
            int diff = 0;
            diff = maxchar - sizeof(data[baris][kolom].name);
            for (int x = 0; x <= diff+1; x++){
                printf(" ");
            }
        }
        printf("\n");
    }

    i = 0;
    while (strcmp(tempat[i].nama1,"Selesai")!= 0)
    {
        int tamprow1, tamcpol1;
        for(baris = 0; baris < n; baris++){
            for(kolom = 0; kolom < m; kolom++){
                if(strcmp(tempat[i].nama1, data[baris][kolom].name) == 0){
                    tamprow1 = baris;
                    tamcpol1 = kolom;
                }
            }
        }

        int tamprow2, tamcpol2;
        for(baris = 0; baris < n; baris++){
            for(kolom = 0; kolom < m; kolom++){
                if(strcmp(tempat[i].nama2, data[baris][kolom].name) == 0){
                    tamprow2 = baris;
                    tamcpol2 = kolom;
                }
            }
        }

        mhs temp, mhs1, mhs2;
        mhs1 = data[tamprow1][tamcpol1];
        mhs2 = data[tamprow2][tamcpol2];
        if((mhs1.numericSize > mhs2.numericSize && tamprow1 < tamprow2) 
        || (mhs1.numericSize < mhs2.numericSize && tamprow1 > tamprow2)){
            temp = data[tamprow1][tamcpol1];
            data[tamprow1][tamcpol1] = data[tamprow2][tamcpol2];
            data[tamprow2][tamcpol2] = temp;
        }

        i++;
    }
    
    printf("\nPosisi akhir :\n");
    for(baris = 0; baris < n; baris++){
        for(kolom = 0; kolom < m; kolom++){
            printf("%s  ", data[baris][kolom].name);
        }
        printf("\n");
    }

    return 0;
}