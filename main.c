#include <stdio.h>
#include <math.h>
#include <string.h>

struct centralny_sklad {
    int jedlo;
    int pivo;
    int ruda;
    int mince;
};

struct moj_hrac {
    char meno[20];
    char nik[20];
};

void credits(){
    printf("Create by Michal Janosik\n");
    printf("Zadanie 1 - Hra");
}

void welcome(){
    printf("Vitajte v mojej konzolovej aplikacii HRAq\n");
    printf("Hra je odvodena od hry Dwarf Fortress\n");
    printf("Podme teda hrat\n");
}

int main() {
    credits();
    welcome();

    struct moj_hrac trpaslik1;
    struct centralny_sklad polozky;

    strcpy( trpaslik1.meno, "Michal Janosik");
    strcpy( trpaslik1.nik, "Mysiak");

    printf( "Meno hraca %s\n", trpaslik1.meno);
    printf( "nik %s\n", trpaslik1.nik);

    return 0;
}