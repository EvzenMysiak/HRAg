#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/param.h>
#include "cmake-build-debug/variables.h"


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
    int money;
    int ruda;
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
//-------------------------------------------------
//funkcie na inicializaciu hraca a vypis jeho skladu a staminy
//-------------------------------------------------
void meno_hraca(char *menomojhohraca){
    printf("Zadaj meno tvojho trpaslika\n");
    scanf("%s",&*menomojhohraca);
    return;
}

void gen_hrac_stamina(struct moj_hrac *hodnoty){
    hodnoty->energia=50;
    hodnoty->hlad=50;
    hodnoty->zivoty=5;
    hodnoty->money=100;
    hodnoty->ruda=0;
    return;
}

void gen_centralny_sklad(struct centralny_sklad *stav){
    stav->jedlo=1000;
    stav->mince=1000;
    stav->pivo=1000;
    stav->ruda=1000;
}

void print_hrac(struct moj_hrac gamer){
    printf( "Meno hraca : %s\n", gamer.meno);
    printf( "Zivoty : %d\n", gamer.zivoty);
    printf( "Energia : %d\n", gamer.energia);
    printf( "Hlad : %d\n", gamer.hlad);
    printf( "Peniaze %d\n",gamer.money);
    printf( "Ruda %d\n", gamer.ruda);
}

void print_centralny_sklad(struct centralny_sklad stav){
    printf("Stav centralny sklad\n");
    printf( "Jedlo : %d\n", stav.jedlo);
    printf( "Pivo : %d\n", stav.pivo);
    printf( "Ruda : %d\n", stav.ruda);
    printf( "Mince : %d\n", stav.mince);
}

int menu(int *volba){
    printf("Vyber si operaciu:\n");
    printf("\t1. Boj s vlkmi\n\t2. Boj s inym hracom\n\t3. Dolovanie rudy(praca)\n\t4. Obed\n\t5. Krcma\n\t6. Obchod\n\t7. Dokumentacia\n\t8. Koniec hry\n");
    scanf("%d",&*volba);
}

//-------------------------------------------------
//funkcie na operacie s hracom (hra)
//-------------------------------------------------

int boj_s_vlkmi(struct moj_hrac *hodnoty){
    int rand_boj_rand1=rand()%20+1;
    int rand_boj_rand2=rand()%20+1;

    if (hodnoty->zivoty<1){
        printf("Nedostatok zivotov tvoja postava je pravdepodobne mrtva\n");
        return 0;
    }
    if (hodnoty->energia<MIN_energy){
        printf("Nedostatok energie na boj\n");
        return 1;
    }

//------------------boj---------------------------
    if (hodnoty->energia>20&&hodnoty->hlad>20){
        hodnoty->energia-=rand_boj_rand1;
        hodnoty->hlad-=rand_boj_rand2;
        hodnoty->money+=10;
    } else{
        printf("Hrac %s stratil zivot\n",hodnoty->meno);
        hodnoty->energia=0;
        hodnoty->hlad=0;
        hodnoty->zivoty--;
    }
}

int dolovanie(struct moj_hrac *hodnoty,struct centralny_sklad *sklad){
    int choose;

    if (hodnoty->energia<20){
        sklad->ruda-=5;
        hodnoty->energia-=5;
        hodnoty->ruda+=5;
        hodnoty->hlad-=5;
    } else{
        sklad->ruda-=10;
        hodnoty->energia-=5;
        hodnoty->ruda+=10;
        hodnoty->hlad-=5;
    }

    printf("Chcete ist vymenit rudu do obchodu za peniaze?\n");
    printf("Napiste:\n 1 pre Ano\n 0 pre Nie\n");
    scanf("%d",&choose);
    if (choose==1){
        printf("vybral si obchod\n");
       // obchod(&hodnoty,&sklad);
        return 1;
    }else return 0;

}

int obchod(struct moj_hrac *hodnoty,struct centralny_sklad *sklad){
    int vyber;
    int obchodovanie=0;
    int velkost_rudy;
    int vyber_jedla;
    int odpocet_jedla;
    int prisun_energie;


    while (obchodovanie<1){
        printf("\nPonuka:\n");
        printf("\t1. Predaj rudu\n\t2. Jedlo\n\t3. Pivo\n\t4. Spat do menu\n");
        scanf("%d",&vyber);
        switch (vyber){
            case 1:
                printf("Napis kolko rudy chces predat\n");
                scanf("%d",&velkost_rudy);
                sklad->ruda+=velkost_rudy;
                hodnoty->money+=(velkost_rudy*cena_rudy);
                hodnoty->ruda-=velkost_rudy;
                printf("--------------Transakcia akceptovana--------------\n");
                print_hrac(*hodnoty);
                break;
            case 2:
                zvolenie_jedla(&odpocet_jedla,&prisun_energie);
                hodnoty->money-=odpocet_jedla;
                hodnoty->energia+=prisun_energie;
                sklad->jedlo-=1;
                print_hrac(*hodnoty);
                break;
            case 3:
                break;
            case 4:
                obchodovanie++;
                break;
        }
    }

}

void zvolenie_jedla(int *odpocet_jedla, int *prisun_energie){
    int vyber_jedla;
    printf("Jedalny listok:\n");
    printf("\t1. Steak %d minci\n", steak_cena);
    printf("\t2. Zemiaky %d minci\n",zemiaky_cena);
    printf("\t3. Salat %d minci\n\n", salat_cena);
    printf("\tEnergeticke hodnoty:\n");
    printf("\tEnergeticka hodnota STEAK %d\n",steak);
    printf("\tEnergeticka hodnota ZEMIAKY %d\n",zemiaky);
    printf("\tEnergeticka hodnota SALAT %d\n\n",salat);
    printf("Pre vyber jedla zadajte jeho ID");
    printf("Pre zrusenie stalc 4\n");
    scanf("%d",&vyber_jedla);
    if (vyber_jedla==1){
        *odpocet_jedla=steak_cena;
        *prisun_energie=steak;
    }
    else if(vyber_jedla==2){
        *odpocet_jedla=zemiaky_cena;
        *prisun_energie=zemiaky;
    } else{
        *odpocet_jedla=salat_cena;
        *prisun_energie=salat;
    }

}



int main() {
    char menohraca_p[20];
    int volba;
    int koniec;
    koniec=0;

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

    while (koniec<1) {

        menu(&volba);
        switch (volba) {
            case 1:
                boj_s_vlkmi(&trpaslik);
                print_hrac(trpaslik);
                break;
            case 2:
                printf("2");
                break;
            case 3:
                dolovanie(&trpaslik,&polozky);
                print_hrac(trpaslik);

                break;
            case 4:
                printf("4");
                break;
            case 5:
                printf("5");
                break;
            case 6:
                obchod(&trpaslik,&polozky);
                print_hrac(trpaslik);
                break;
            case 7:
                //TODO funkcia na dokumentaciu
                break;
            case 8:
                koniec++;
                break;
        }
        if (trpaslik.zivoty==0){
            printf("Tvoj hrac zomrel\nKONIEC HRY");
            koniec++;
        }
    }



    return 0;
}

