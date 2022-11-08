#include <stdio.h>  
void main()  
{  
    // declaration of variables  
    int num, binary_num, decimal_num = 0, base = 1, rem;
    int i = 0;
    char g[] = "1 1 1 1 1 1 0";
    char h[] = "1 0 1 0";
    int fus = sizeof(g) + sizeof(h);
    int n = sizeof(g) + sizeof(h);
    char ns[n];
    char f[fus];
    char fv ;
    int x;
    x = sizeof(g);
    printf("%s",g);
    printf("%d\n",x);


    while (i < sizeof(g)-1) {
        f[i] = g[i];
        i++;
    }

    int j = 0;

    while (j < sizeof(h)) {
        f[i] = h[j];
        i++;
        j++;
    }

    fus = fus-2;
    while (fus > 0)  
    {
        fv = f[fus];
        
        if (fv == '1') {
            rem = 1; /* divide the binary number by 10 and store the remainder in rem variable. */  
            decimal_num = decimal_num + rem * base;  
            base = base * 2;
        } else if (fv == '0') {
            base = base * 2;
        }

        fus = fus - 1;
        
    }  
  
    printf ( " \nThe binary number is %d \t", binary_num); // print the binary number  
    printf (" \n The decimal number is %d \t", decimal_num); // print the decimal   
}  