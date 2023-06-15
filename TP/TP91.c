// #include "header.h"
// #include <stdio.h>
#include "mesin.c"

// Naruto 24 13 2 Rasengan
// RockLee 29 10 3 Drunken
// Suna
// Gaara 32 14 3 SabakuTaisou
// Temari 29 9 4 Kuchiyose
// 3
// a Naruto Temari
// d Gaara
// h Temari


int main (void) {
  shinobi konoha1; // deklarasi struct 
  shinobi konoha2; // deklarasi struct 
  shinobi lawan1; // deklarasi struct 
  shinobi lawan2; // deklarasi struct 
  int act;

  char action; // store actions 
  char atk1[50]; // penyerang
  char target[50]; // yg diserang // target 

  
  char desalawan[50]; // store nama desa lawan

  scanf("%s %d %d %d %s", &*konoha1.Nama, &konoha1.Health, &konoha1.Atk, &konoha1.Def, &*konoha1.Jurus);
  scanf("%s %d %d %d %s", &*konoha2.Nama, &konoha2.Health, &konoha2.Atk, &konoha2.Def, &*konoha2.Jurus);

  scanf("%s",&*desalawan);

  scanf("%s %d %d %d %s", &*lawan1.Nama, &lawan1.Health, &lawan1.Atk, &lawan1.Def, &*lawan1.Jurus);
  scanf("%s %d %d %d %s", &*lawan2.Nama, &lawan2.Health, &lawan2.Atk, &lawan2.Def, &*lawan2.Jurus);

  scanf("%d\n", &act);

  command perintah[act]; // untuk menyimpa dulu semua peritanh yg diinput karena ketika klik enter pertarungan belum dimulai, pertarungan dimulai ketika semua inputan telah diiput

  for (int i = 0; i < act; i++){
    scanf("%c %s %s",&action, &*atk1, &*target);
    perintah[i].Action = action; // simpan action ke dalam array perintah
    sprintf(perintah[i].Attacker, "%s", atk1); // ini udah diajarin ?
    sprintf(perintah[i].Target, "%s", target); // ini juga ?



    if (action == 'a') { // bug disini di laptop ane gan 
      // cari ninja dengan nama tersebut
      // ini cek satu satu kalo kkh1 ataack lawan 2 konoha 2 attack lawan dll 
      if (atk1 == konoha1.Nama && target == lawan1.Nama) {
        attack(konoha1,lawan1);
      } else if (atk1 == konoha1.Nama && target == lawan2.Nama) {
        attack(konoha1,lawan2);
      } else if (atk1 == konoha2.Nama && target == lawan1.Nama) {
        attack(konoha2,lawan1);
      } else if (atk1 == konoha2.Nama && target == lawan2.Nama) {
        attack(konoha2,lawan2);
      } else if (atk1 == lawan1.Nama && target == konoha1.Nama) {
        attack(lawan1,konoha1);
      } else if (atk1 == lawan1.Nama && target == konoha2.Nama) {
        attack(lawan1,konoha2);
      } else if (atk1 == lawan2.Nama && target == konoha1.Nama) {
        attack(lawan2,konoha1);
      } else if (atk1 == lawan2.Nama && target == konoha2.Nama) {
        attack(lawan2,konoha2);
      }
    } else if (action == 'd') { // bug disini di laptop ane gan 
        if (atk1 == konoha1.Nama) {
            defense(konoha1);
        } else if (atk1 == konoha2.Nama){
            defense(konoha2);
        } else if (atk1 == lawan1.Nama){
            defense(lawan1);
        } else if (atk1 == lawan2.Nama){
            defense(lawan2);
        }
    } else if (action == 'h') { // bug disini di laptop ane gan 
        if (atk1 == konoha1.Nama) { // cek kalo heal nya ke nama yg diinput
            heal(konoha1);
        } else if (atk1 == konoha2.Nama){
            heal(konoha2);
        } else if (atk1 == lawan1.Nama){
            heal(lawan1);
        } else if (atk1 == lawan2.Nama){
            heal(lawan2);
        }
    }
  }
  printf("Exam Begins!\n");

  winner(konoha1,konoha2, lawan1, lawan2, desalawan);
  return 0;

}




