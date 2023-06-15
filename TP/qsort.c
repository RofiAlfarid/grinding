#include <stdio.h>
void printArr(int arr[])
{
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void qsTengah(int arr[], int kiri, int kanan)
{
    int i, j, temp, pivot;
    i = kiri, j = kanan;
    pivot = arr[(kanan + kiri) / 2];
    do
    {
        while ((arr[i] < pivot) && (i <= j))
        {
            i++;
        }
        while ((arr[j] > pivot) && (i <= j))
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }


    } while (i < j);
    printArr(arr);
    if (kiri < j && j < kanan)
    {
        qsTengah(arr, kiri, j);
    }
    if (i < kanan && i > kiri)
    {
        qsTengah(arr, i, kanan);
    }
}
int main()
{
    int key, i, j, swap, temp;


    int arr[8] = {6, 4, 3, 1, 2, 5, 8, 7};
    printf("Sebelum di sort:(Pivot Tengah)\n");
    printArr(arr);
    // algoritma QS Pivot Tengah
    qsTengah(arr, 0, 8 - 1);
    printf("Setelah di sort:\n");
    printArr(arr);
    // printf("===================\n");
    // printf("Sebelum di sort:(Pivot Pinggir)\n");
    // int arr2[8] = {6, 3, 4, 7, 2, 5, 8, 1};
    // // algoritma QS Pivot Pinggir
    // qsPinggir(arr2, 0, 8 - 1);
    // printf("Setelah di sort:\n");
    // printArr(arr2);
    return 0;
}
