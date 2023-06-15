#include <stdio.h>


int calc(int i){

    if (i > 0){
        return calc(i-1) * 2 - 3;
    }
    return 6;
}

int abs(int a, int b){
    if (a - b >= 0){
        return a - b;
    } else {
        return (a - b) * -1;
    }
}

int countdigits(int num){
    int count = 0;
    do
    {
        count++;
        num /= 10;
    } while(num != 0);

    return count;
}

int maxlen(int a, int b){
    if (countdigits(a) > countdigits(b)){
        return countdigits(a);
    } else {
        return countdigits(b);
    }
}

void print(int a, int b){
    printf("%d",a);
    if (countdigits(a) == 1){
        printf("  ");
    } else if (countdigits(a) == 2){
        printf(" ");
    }
    printf("|");
    if (countdigits(b) == 1){
        printf("  ");
    } else if (countdigits(b) == 2){
        printf(" ");
    }
    printf("%d",b);
    printf(" >> %d",calc(abs(a,b)));
    printf("\n");

}

void step(int a, int b){
    // printf("%d | %d >> %d\n",a,b, calc(abs(a,b)));
    print(a,b);
    if (a > 2 && a >= b && b != 1) {
        step(a/3,b);
    }else if (b > 2 && b >= a && a != 1){
        step(a,b/3);
    }
}

void main() {
    int a,b;
    scanf("%d %d",&a,&b);
    step(a,b);

}