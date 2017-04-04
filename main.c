#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//#include variables.h

struct centralny_sklad {
    int jedlo;
    int pivo;
    int ruda;
    int mince;
};

struct moj_hrac {
    char meno[20];
    int zivoty;
    int hlad;
    int energia;
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

void meno_hraca(char *menomojhohraca){
    printf("Zadaj meno tvojho trpaslika\n");
    scanf("%s",&*menomojhohraca);
    return;
}

void gen_hrac_stamina(struct moj_hrac *hodnoty){
    hodnoty->energia=50;
    hodnoty->hlad=50;
    hodnoty->zivoty=100;
    return;
}

void gen_centralny_sklad(struct centralny_sklad *stav){
    stav->jedlo=100;
    stav->mince=1000;
    stav->pivo=100;
    stav->ruda=100;
}

void print_hrac(struct moj_hrac gamer){
    printf( "Meno hraca : %s\n", gamer.meno);
    printf( "Zivoty : %d\n", gamer.zivoty);
    printf( "Energia : %d\n", gamer.energia);
    printf( "Hlad : %d\n", gamer.hlad);
}

void print_centralny_sklad(struct centralny_sklad stav){
    printf("Stav centralny sklad\n");
    printf( "Jedlo : %d\n", stav.jedlo);
    printf( "Pivo : %d\n", stav.pivo);
    printf( "Ruda : %d\n", stav.ruda);
    printf( "Mince : %d\n", stav.mince);
}


int main() {
    char menohraca_p[20];

    struct moj_hrac trpaslik;
    struct centralny_sklad polozky;

    srand(time(NULL));

    credits();
    welcome();
    meno_hraca(&menohraca_p);
    strcpy( trpaslik.meno, menohraca_p);
    gen_hrac_stamina(&trpaslik);
    print_hrac(trpaslik);
    gen_centralny_sklad(&polozky);
    print_centralny_sklad(polozky);

    return 0;
}

