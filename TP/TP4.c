#include <stdio.h>
#include <string.h>

void garis(){
    printf("=========================");
    printf("\n");
}

void printspasi(int n){
    for (int i = 0; i < n + 2; i++ ){
        printf(" ");
    }
}

void output(int n, char nama[][100], int umur[], int ln){
    for(int i = 0; i < n; i++){
        printf("%s", nama[i]);
        printspasi(ln - strlen(nama[i]));
        printf("%d\n", umur[i]);
    }
}

// void jumAge(int ageAwal, int ageAkhir, int sumAge){
//     sumAge = ageAwal + ageAkhir;
// }

int main(){
    int n;
    scanf("%d", &n);
    char nama[n][100];
    int umur[n];
    int i;
    int maxstr = 0;
    for(i = 0; i < n; i++){
        scanf("%s %d", &nama[i], &umur[i]);

        if (maxstr < strlen(nama[i])) {
            maxstr = strlen(nama[i]);
        }
    }

    char sorting[100];
    scanf("%s", &sorting);

    int namAwal = 0; 
    int namAkhir = 0;
    int sumNama;
    int ageAwal, ageAkhir, sumAge;

    for(int i = 0; i < n; i++){
        ageAwal = umur[0];
    }

    for(i = 0; i < strlen(nama[0]); i++){
        namAwal = namAwal + nama[0][i];
    }

    char temp[100];
    int tempAge;

    if(strcmp(sorting, "ANI") == 0){
        for (int i = 1; i < n; i++){
            ageAkhir = umur[0];
            strcpy(temp, nama[i]);   
            tempAge = umur[i];                       
            int j = i - 1;                                  
            while (j >= 0 && (strcmp(temp, nama[j]) < 0)){  
                strcpy(nama[j+1], nama[j]); 
                umur[j+1] = umur[j];                 
                j--;                                        
            }
            strcpy(nama[j+1], temp);
            umur[j+1] = tempAge;                       
        }

    }else if(strcmp(sorting, "DNS") == 0){
        int minIndex;                                       
        for (int i = 0; i < (n - 1); i++){
            ageAkhir = umur[0];
            minIndex = i;                                               
            for (int j = i+1; j < n; j++){
                if (strcmp(nama[minIndex], nama[j]) < 0){   
                    minIndex = j;                           
                }
            }
            strcpy(temp, nama[i]);                      
            strcpy(nama[i], nama[minIndex]);            
            strcpy(nama[minIndex], temp); 

            tempAge = umur[i];                      
            umur[i] = umur[minIndex];            
            umur[minIndex] = tempAge;  
    
        }
    }else if(strcmp(sorting, "AUS") == 0){
        int minIndex;                                       
        for (int i = 0; i < (n - 1); i++){
            ageAkhir = umur[0];
            minIndex = i;                                               
            for (int j = i+1; j < n; j++){
                if (umur[minIndex] > umur[j]){   
                    minIndex = j;                           
                }
            }
            tempAge = umur[i];                      
            umur[i] = umur[minIndex];            
            umur[minIndex] = tempAge;   

            strcpy(temp, nama[i]);                      
            strcpy(nama[i], nama[minIndex]);            
            strcpy(nama[minIndex], temp);            
    
        }
    }

    for(i = 0; i < strlen(nama[0]); i++){
        namAkhir = namAkhir + nama[0][i];
    }

    // jumAge(ageAwal, ageAkhir, sumAge);
    sumAge = ageAwal + ageAkhir;
    sumNama = namAwal + namAkhir;

    printf("Hasil setelah diurutkan :\n");
    garis();
    output(n, nama, umur, maxstr);
    garis();
    if(sumNama % 2 == 0 && sumAge % 2 == 0){
        printf("Selamat, Anda masuk ke asrama Adora Rourie!\n");
    }else if(sumNama % 2 == 0 && sumAge % 2 == 1){
        printf("Selamat, Anda masuk ke asrama Jocelin Cosu!\n");
    }else if(sumNama % 2 == 1 && sumAge % 2 == 1){
        printf("Selamat, Anda masuk ke asrama Boden Sournois!\n");
    }else if(sumNama % 2 == 1 && sumAge % 2 == 0){
        printf("Selamat, Anda masuk ke asrama Pyneres Cannes!\n");
    }
    
    return 0;
}