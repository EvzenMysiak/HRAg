#include <stdio.h>
#include <math.h>

typedef struct centralny_sklad {
    int jedlo;
    int pivo;
    int ruda;
    int mince;
};

typedef struct moj_hrac {
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
    return 0;
}