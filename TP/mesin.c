#include <stdio.h>
#include "header.c"

void attack(shinobi subject, shinobi target) {
    target.Health -= subject.Atk - target.Def;
    printf("%s received %d damage from %s, his/her current health is %d",target.Nama, subject.Atk, subject.Nama,target.Health);
}

void defense(shinobi ninja) {
    ninja.Def += 3;
    printf("%s increased his/her own defense by 3, it is now %d", ninja.Nama, ninja.Def);
}

void heal(shinobi ninja) {
    ninja.Health += 10;
    printf("%s used heal to recover 10 health, his/her current health is %d", ninja.Nama, ninja.Health);
}


void winner(shinobi konoha1, shinobi konoha2,shinobi lawan1, shinobi lawan2, char desalawan[50]) {

    printf("Exam Result: \n");
    printf("Konoha Village: \n");
    printf("%s %d %d %d %s \n",konoha1.Nama, konoha1.Health, konoha1.Atk, konoha1.Def, konoha1.Jurus);
    printf("%s %d %d %d %s \n",konoha2.Nama, konoha2.Health, konoha2.Atk, konoha2.Def, konoha2.Jurus);
    printf("%s Village\n",desalawan);
    printf("%s %d %d %d %s \n",lawan1.Nama, lawan1.Health, lawan1.Atk, lawan1.Def, lawan1.Jurus);
    printf("%s %d %d %d %s \n",lawan2.Nama, lawan2.Health, lawan2.Atk, lawan2.Def, lawan2.Jurus);

    int total_konoha = konoha1.Health + konoha2.Health;
    int total_lawan = lawan1.Health + lawan2.Health;

    if (total_konoha > total_lawan) {
        printf(">>> Konoha Village Passed <<<");
    } else if (total_konoha < total_lawan) {
        printf(">>> %s Village Passed <<<", desalawan);
    } else {
        printf(">>> Both Village Passed <<<");
    }
}