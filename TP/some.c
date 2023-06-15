#include <stdio.h>
const int M = 3;
 
typedef struct {
    char Name[100];
    int NumericSize;
    char SizeEU[5];
}mhs;
 
void print(mhs (*s)[100])
{
    // int i, j;
    // for (i = 0; i < M; i++)
    // for (j = 0; j < M; j++)
        // printf("%d ", s[i][j].NumericSize);
}
 
int main()
{
    mhs arr[][3] = {
        {"ji", 2, "XL"}, 
        {"wa", 5, "L"}, 
        {"lu", 8, "M"}
    };
    print(arr);
    return 0;
}