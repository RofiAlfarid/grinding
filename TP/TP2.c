#include <stdio.h>
#include <string.h>


typedef struct {
    char Name[100];
    int NumericSize;
    char SizeEU[5];
}mhs;

typedef struct {
    int name[100];
    int name2[100];
}tuker;

typedef struct {
    int row;
    int col;
}coor;

void showLine( int n, int m, mhs kursi[n][m]){
    printf("\n");
    for (int i = 0; i< n; i++){
        for (int j = 0; j< m;j++){
            printf("%s  ",kursi[i][j].Name);
        }
        printf("\n");
    }
}


int main(){
    int n,m, maxc;

    scanf("%d %d",&n,&m);

    int maxcol[m];
    mhs kursi[n][m];

    char name[100];
    for (int i = 0; i< n; i++){
        for (int j = 0; j< m;j++){
            scanf("%s %s",&kursi[i][j].Name, &kursi[i][j].SizeEU);

            if (strcmp("XS",kursi[i][j].SizeEU) == 0){
                kursi[i][j].NumericSize = 32;
            } else if (strcmp("S",kursi[i][j].SizeEU)==0){
                kursi[i][j].NumericSize = 36;
            } else if (strcmp("M",kursi[i][j].SizeEU)==0){
                kursi[i][j].NumericSize = 37;
            } else if (strcmp("L",kursi[i][j].SizeEU)==0){
                kursi[i][j].NumericSize = 38;
            } else if (strcmp("XL",kursi[i][j].SizeEU)==0){
                kursi[i][j].NumericSize = 40;
            } else if (strcmp("XXL",kursi[i][j].SizeEU)==0){
                kursi[i][j].NumericSize = 42;
            } else if (strcmp("XXXL",kursi[i][j].SizeEU)==0){
                kursi[i][j].NumericSize = 45;
            }
        }
    }

    mhs jk = kursi[0][0];


    char name1[100],name2[100];
    for(;;){
        scanf("%s",&name1);
        if (strcmp(name1, "Selesai") == 0) {
            break;
        }

        scanf("%s",&name2);

        // mulai pertukaran

        int i1,j1;
        for (int i = 0; i< n; i++){
            for (int j =0;j < m; j++){
                if (strcmp(name1,kursi[i][j].Name) == 0){
                    i1 = i;
                    j1 = j;
                }
            }
        }

        int i2,j2;
        for (int i = 0; i< n; i++){
            for (int j =0;j < m; j++){
                if (strcmp(name2,kursi[i][j].Name) == 0){
                    i2 = i;
                    j2 = j;
                }
            }
        }

        

        if (kursi[i1][j1].NumericSize > kursi[i2][j2].NumericSize) {
            mhs tmp;
            tmp = kursi[i1][j1];
            kursi[i1][j1] = kursi[i2][j2];
            kursi[i2][j2] = tmp ;
        }



        showLine(n,m,kursi);
    }

}