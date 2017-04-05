#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "cmake-build-debug/variables.h"


struct centralny_sklad {
    int jedlo;
    int pivo_fl;
    int pivo_craft;
    int ruda;
    int mince;
    int vod;
    int pal;
};

struct moj_hrac {
    int ID;
    char meno[20];
    int zivoty;
    int hlad;
    int energia;
    int money;
    int ruda;
    //schopnosti
    int sila;
    int vydrz;
    int obrana;
};

struct vlk_bojovnik{
    int sila;
    int obrana;
    int vytrvalost;
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
    hodnoty->obrana=rand()%100+1;
    hodnoty->sila=rand()%100+1;
    hodnoty->vydrz=rand()%100+1;
}

void gen_vlk_bojovnik(struct vlk_bojovnik *vlkoviny){
    vlkoviny->sila=rand()%100+1;
    vlkoviny->obrana=rand()%100+1;
    vlkoviny->vytrvalost=rand()%100+1;
}

void random_hodnoty_ostatny_hraci(struct moj_hrac *hodnoty){
    hodnoty->energia=rand()%100+1;
    hodnoty->hlad=rand()%100+1;
    hodnoty->zivoty=rand()%5+2;
    hodnoty->money=rand()%100+1;
    hodnoty->ruda=rand()%50+1;
    hodnoty->obrana=rand()%100+1;
    hodnoty->sila=rand()%100+1;
    hodnoty->vydrz=rand()%100+1;
}

void gen_centralny_sklad(struct centralny_sklad *stav){
    stav->jedlo=1000;
    stav->mince=1000;
    stav->pivo_fl=1000;
    stav->ruda=1000;
    stav->pivo_craft=1000;
    stav->pal=1000;
    stav->vod=1000;
}

void print_hrac(struct moj_hrac *gamer){
    printf( MAG"\nID hraca: %d\n",gamer->ID );
    printf( "Meno hraca : %s\n", gamer->meno);
    printf( "Zivoty : %d\n", gamer->zivoty);
    printf( "Energia : %d\n", gamer->energia);
    printf( "Hlad : %d\n", gamer->hlad);
    printf( "Peniaze %d\n",gamer->money);
    printf( "Ruda %d\n", gamer->ruda);
    printf( "Sila : %d\n", gamer->sila);
    printf( "Vydrz %d\n",gamer->vydrz);
    printf( "Obrana %d\n"RESET, gamer->obrana);
}

void print_centralny_sklad(struct centralny_sklad stav){
    printf(CYN"\n\nStav centralny sklad\n");
    printf( "Jedlo : %d\n", stav.jedlo);
    printf( "Pivo capovane : %d\n", stav.pivo_craft);
    printf( "Pivo flaskove : %d\n", stav.pivo_fl);
    printf( "Vodka : %d\n", stav.vod);
    printf( "Paleno : %d\n", stav.pal);
    printf( "Ruda : %d\n", stav.ruda);
    printf( "Mince : %d\n"RESET, stav.mince);
}

int menu(int *volba){
    printf("\n\nMENU\n");
    printf(YEL"Vyber si operaciu:\n"RESET);
    printf(BLU"\t1. Boj s vlkmi\n\t2. Boj s inym hracom\n\t3. Dolovanie rudy(praca)\n\t4. Karcma\n\t5. Obchod\n\t"
                   "6. Vylepsenia\n\t7. Vyber z inych postav\n\t8. Vypis hodnot\n\t9. Dokumentacia\n\t10. Koniec hry\n"RESET);
    scanf("%d",&*volba);
}

int vypis_hracov(struct moj_hrac hr[0],int *vyber_hraca){
    int pomocna;
    for (int i = 1; i <5 ; ++i) {
    printf("Hrac c1: %d\n",i);
    printf( "\tMeno hraca : %s\n", hr[i].meno);
    printf( "\tZivoty : %d\n", hr[i].zivoty);
    printf( "\tEnergia : %d\n", hr[i].energia);
    printf( "\tHlad : %d\n", hr[i].hlad);
    printf( "\tPeniaze %d\n",hr[i].money);
    printf( "\tRuda %d\n", hr[i].ruda);
    printf( "\tSila : %d\n", hr[i].sila);
    printf( "\tVydrz %d\n",hr[i].vydrz);
    printf( "\tObrana %d\n", hr[i].obrana);
    }

    printf("\nZadaj poradove cislo hraca:\t");
    scanf("%d",&*vyber_hraca);
}

//-------------------------------------------------
//funkcie na operacie s hracom (hra)
//-------------------------------------------------

int boj_s_vlkmi(struct moj_hrac *hodnoty){
    int random_vyhra;
    int rand_boj_rand1=rand()%20+1;
    int rand_boj_rand2=rand()%20+1;
    struct vlk_bojovnik vlk;
    gen_vlk_bojovnik(&vlk);

    if (hodnoty->zivoty<1){
        printf(RED"Nedostatok zivotov tvoja postava je pravdepodobne mrtva\n"RESET);
        return 0;
    }
    if (hodnoty->energia<MIN_energy){
        printf(RED"Nedostatok energie na boj\n"RESET);
        return 1;
    }

//------------------boj---------------------------
    if (hodnoty->energia>20&&hodnoty->hlad>20){
        if(hodnoty->sila>vlk.sila) {
            hodnoty->energia -= rand_boj_rand1;
            hodnoty->hlad -= rand_boj_rand2;
            hodnoty->money += 10;
            hodnoty->sila+=2;
            hodnoty->obrana+=1;
            hodnoty->vydrz+=2;
            printf("BOJUJEM!");
            animacia(5);
            printf(GRN"Porazil si vlka\n"RESET);
        } else if(hodnoty->sila==vlk.sila){
            random_vyhra=rand()%2;
            if(random_vyhra==0) {
                hodnoty->energia -= rand_boj_rand1 + 5;
                hodnoty->hlad -= rand_boj_rand2 + 5;
                hodnoty->money += 15;
                hodnoty->sila += 3;
                hodnoty->obrana += 2;
                hodnoty->vydrz += 3;
                printf("BOJUJEM!");
                animacia(5);
                printf(GRN"Porazil si vlka\n"RESET);
            }else{
                hodnoty->energia =50;
                hodnoty->hlad =50;
                hodnoty->money -=5;
                hodnoty->zivoty-=1;
                printf("BOJUJEM!");
                animacia(5);
                printf(RED"Vlk ta porazil\n"RESET);
            }
        } else{
            hodnoty->energia =50;
            hodnoty->hlad =50;
            hodnoty->money -=5;
            hodnoty->zivoty-=1;
            printf("BOJUJEM!");
            animacia(5);
            printf(RED"Vlk ta porazil\n"RESET);
        }
    } else{
        printf(RED"Hrac %s stratil zivot\n"RESET,hodnoty->meno);
        hodnoty->energia=50;
        hodnoty->hlad=50;
        hodnoty->zivoty--;
    }
}

void dolovanie(struct moj_hrac *hodnoty,struct centralny_sklad *sklad){

    if (hodnoty->energia<20){
        sklad->ruda-=5;
        hodnoty->energia-=5;
        hodnoty->ruda+=5;
        hodnoty->hlad-=5;
        hodnoty->sila+=1;
        hodnoty->vydrz+=1;
        printf("DOLUJEM!");
        animacia(10);
    } else{
        sklad->ruda-=10;
        hodnoty->energia-=5;
        hodnoty->ruda+=10;
        hodnoty->hlad-=5;
        hodnoty->sila+=2;
        hodnoty->vydrz+=2;
        printf("DOLUJEM!");
        animacia(7);
    }
}

void obchod(struct moj_hrac *hodnoty,struct centralny_sklad *sklad){
    int vyber;
    int obchodovanie=0;
    int velkost_rudy;
    int odpocet_jedla;
    int prisun_energie;
    int pomocna_hlad;

    while (obchodovanie<1){
        printf("\nPonuka:\n");
        printf("\t1. Predaj rudu\n\t2. Jedlo\n\t3. Spat do menu\n");
        scanf("%d",&vyber);
        switch (vyber){
            case 1:
                printf("Napis kolko rudy chces predat\n");
                scanf("%d", &velkost_rudy);

                if (hodnoty->ruda>=0) {
                    sklad->ruda += velkost_rudy;
                    hodnoty->money += (velkost_rudy * cena_rudy);
                    hodnoty->ruda -= velkost_rudy;
                    printf("OBCHODUJEM!");
                    animacia(3);
                    printf("--------------Transakcia akceptovana--------------\n");
                    print_hrac(hodnoty);
                } else{
                    printf("Nemas dostatok rudy !!!\n");
                }
                break;
            case 2:
                zvolenie_jedla(&odpocet_jedla,&prisun_energie);
                hodnoty->money-=odpocet_jedla;
                hodnoty->energia+=prisun_energie;
                sklad->jedlo-=1;
                pomocna_hlad=hodnoty->hlad;
                hodnoty->hlad-=pomocna_hlad;
                printf("OBEDUJEM!");
                animacia(3);
                print_hrac(hodnoty);
                break;
            case 3:
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

void karcma(struct moj_hrac *hodnoty, struct centralny_sklad *sklad){
    int vyber;
    int bar=0;
    printf("Vitaj v nasej krcme!\n");

    while (bar<1) {
        printf(RED"Vyber si z nasej ponuky:\n"RESET);
        printf(GRN"\t1. Capovane pivo\tCena %d\tEnergia %d\n\t2. Flaskove pivo\tCena %d\tEnergia %d"
                       "\n\t3. Vodka\t\t\tCena %d\tEnergia %d\n\t4. Paleno\t\t\tCena %d\tEnergia %d\n\t5. Odist z krcmy\n"RESET, beer_crafted_cena,
               beer_crafted, beer_botled_cena, beer_botled, vodka_cena, vodka, paleno_cena, paleno);
        printf("Zadaj cislo vyberu z ponuky:\t");
        scanf("%d",&vyber);
        switch (vyber){
            case 1:
                hodnoty->energia+=beer_crafted;
                hodnoty->hlad+=(beer_crafted/2);
                hodnoty->money-=beer_crafted_cena;
                hodnoty->sila+=1;
                hodnoty->obrana-=1;
                sklad->pivo_craft-=1;
                printf("KRCMUJEM!");
                animacia(3);
                break;
            case 2:
                hodnoty->energia+=beer_botled;
                hodnoty->hlad+=(beer_botled/2);
                hodnoty->money-=beer_botled_cena;
                hodnoty->obrana-=1;
                sklad->pivo_craft-=1;
                sklad->pivo_fl-=1;
                printf("KRCMUJEM!");
                animacia(3);
                break;
            case 3:
                hodnoty->energia+=vodka;
                hodnoty->hlad+=(vodka/2);
                hodnoty->money-=vodka_cena;
                hodnoty->obrana-=2;
                sklad->pivo_craft-=2;
                sklad->vod-=1;
                printf("KRCMUJEM!");
                animacia(3);
                break;
            case 4:
                hodnoty->energia+=paleno;
                hodnoty->hlad+=(paleno/2);
                hodnoty->money-=paleno_cena;
                hodnoty->obrana-=3;
                sklad->pivo_craft-=3;
                sklad->pal-=1;
                printf("KRCMUJEM!");
                animacia(3);
                break;
            case 5:
                bar++;
                break;
        }
        if(bar<1) {
            print_hrac(hodnoty);
        }
    }
}

void boj_s_protivnikom(struct moj_hrac *moj,struct moj_hrac *protivnik){
    print_hrac(moj);
    print_hrac(protivnik);
    if (moj->sila>protivnik->sila){
        if(moj->obrana>protivnik->obrana){
            printf("1");
            printf("BOJUJEM!");
            animacia(5);
            printf(GRN"Vyhral si nad bojovnikom %s\n"RESET,protivnik->meno);
            moj->sila+=10;
            moj->obrana+=5;
            moj->vydrz+=5;
            moj->energia-=10;
            protivnik->sila-=10;
            protivnik->obrana-=5;
            protivnik->vydrz+=1;
            protivnik->energia-=10;
            protivnik->zivoty-=1;
        }else if(moj->obrana<=protivnik->obrana) {
            int a = rand() % 2;
            if (a == 1) {
                printf("2");
                printf("BOJUJEM!");
                animacia(5);
                printf(GRN"Vyhral si nad bojovnikom %s\n"RESET, protivnik->meno);
                moj->sila += 8;
                moj->obrana += 4;
                moj->vydrz += 4;
                moj->energia -= 11;
                protivnik->sila -= 8;
                protivnik->obrana -= 4;
                protivnik->vydrz += 2;
                protivnik->energia -= 11;
                protivnik->zivoty -= 1;
            } else {
                printf("3");
                printf("BOJUJEM!");
                animacia(5);
                printf(RED"Prehral si!!! Premohol ta bojovnik %s\n"RESET, protivnik->meno);
                moj->sila -= 10;
                moj->obrana -= 5;
                moj->vydrz += 1;
                moj->energia -= 10;
                moj->zivoty -= 1;
                protivnik->sila += 10;
                protivnik->obrana += 5;
                protivnik->vydrz += 5;
                protivnik->energia -= 10;
            }
        }
    }else if (moj->sila==protivnik->sila){
        if(moj->obrana>protivnik->obrana){
            printf("5");
            printf("BOJUJEM!");
            animacia(5);
            printf(GRN"Vyhral si nad bojovnikom %s\n"RESET,protivnik->meno);
            moj->sila+=10;
            moj->obrana+=5;
            moj->vydrz+=5;
            moj->energia-=10;
            protivnik->sila-=10;
            protivnik->obrana-=5;
            protivnik->vydrz+=1;
            protivnik->energia-=10;
            protivnik->zivoty-=1;
        }else if (moj->obrana<=protivnik->obrana){
            int a=rand()%2;
            if (a==1) {
                printf("6");
                printf("BOJUJEM!");
                animacia(5);
                printf(GRN"Vyhral si nad bojovnikom %s\n"RESET,protivnik->meno);
                moj->sila-=8;
                moj->obrana-=4;
                moj->vydrz+=2;
                moj->energia-=11;
                moj->zivoty-=1;
                protivnik->sila+=15;
                protivnik->obrana+=5;
                protivnik->vydrz+=5;
                protivnik->energia-=15;
            }
        }else{
            printf("7");
            printf("BOJUJEM!");
            animacia(5);
            printf(RED"Prehral si!!! Premohol ta bojovnik %s\n"RESET,protivnik->meno);
            moj->sila-=8;
            moj->obrana-=4;
            moj->vydrz+=2;
            moj->energia-=11;
            moj->zivoty-=1;
            protivnik->sila+=15;
            protivnik->obrana+=5;
            protivnik->vydrz+=5;
            protivnik->energia-=15;
        }
    } else{
        printf("8");
        printf("BOJUJEM!");
        animacia(5);
        printf(RED"Prehral si!!! Premohol ta bojovnik %s\n"RESET,protivnik->meno);
        moj->sila-=8;
        moj->obrana-=4;
        moj->vydrz+=2;
        moj->energia-=11;
        moj->zivoty-=1;
        protivnik->sila+=15;
        protivnik->obrana+=5;
        protivnik->vydrz+=5;
        protivnik->energia-=15;
    }

}

void item_shop(struct moj_hrac *vybava){
    int moznost;
    int itemshop=0;

    while(itemshop<1) {
        printf("Ponuka:\n");
        printf("\t1. Vylepsenie obrany +2 cena %d\n\t2. Vylepsenie sily +2 cena %d\n\t3. Spat do menu\n",
               cena_vylepsenia_obrany, cena_vylepsenie_sily);
        printf("Zadajte jednu z moznosti:\t");
        scanf("%d", &moznost);
        switch (moznost) {
            case 1:
                vybava->obrana += 2;
                printf("VYLEPSUJEM!");
                animacia(3);
                printf("Obrana bola vylepsena\n\n");
                print_hrac(vybava);
                break;
            case 2:
                vybava->sila+=2;
                printf("VYLEPSUJEM!");
                animacia(3);
                printf("Sila bola vylepsena\n\n");
                print_hrac(vybava);
                break;
            case 3:
                itemshop++;
                break;
        }
    }
}

void animacia(int a){
    for (int i = 0; i <=a; ++i) {
        printf("-->");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}

void kontrola_vyhry(struct moj_hrac *vyherca, int *koniec){
    if(vyherca->sila==moznost_vyhry&&vyherca->obrana==moznost_vyhry){
        printf("Gratulujem VYHRAL si hru HRAg!!!");
        sleep(5);
        printf("Hra sa automaticky ukonci");
        animacia(3);
        koniec++;
    }
}

//-------------------------------------------------
//main
//-------------------------------------------------

int main() {
    char menohraca_p[20];
    int volba;
    int koniec=0;
    int vyber_hraca;
    int vyber_gen_negen;
    int vyber_gen_hraca;

    struct moj_hrac trpaslik;
    struct centralny_sklad polozky;
    struct moj_hrac hrac[8];

    strcpy( hrac[1].meno, "Izip");
    strcpy( hrac[2].meno, "Dezider");
    strcpy( hrac[3].meno, "Hegrid");
    strcpy( hrac[4].meno, "Pejo");
    strcpy( hrac[5].meno, "Kainsmetke");

    for (int i = 1; i < 5; ++i) {
        random_hodnoty_ostatny_hraci(&hrac[i]);
        hrac[i].ID=i;
    }

    credits();
    welcome();
    printf("Chces vytvorit noveho hraca alebo pouzit jedneho z vygenerovanych?\n");
    printf("\t1. Chcem noveho hraca\n");
    printf("\t2. Chcem generovaneho hraca\n");
    scanf("%d",&vyber_gen_negen);
    if (vyber_gen_negen==1) {
        meno_hraca(&menohraca_p);
        strcpy(hrac[0].meno, menohraca_p);
        gen_hrac_stamina(&hrac[0]);
        vyber_gen_hraca=0;
        hrac[vyber_gen_hraca].ID=0;
        print_hrac(&hrac[0]);
    } else {
        for (int i = 1; i <5; ++i) {
            print_hrac(&hrac[i]);
        }
        printf("Vyber si poradove cislo hraca\n");
        scanf("%d",&vyber_gen_hraca);
        print_hrac(&hrac[vyber_gen_hraca]);
    }

    gen_centralny_sklad(&polozky);
    print_centralny_sklad(polozky);

    while (koniec<1) {

        menu(&volba);
        kontrola_vyhry(&hrac[vyber_gen_hraca],&koniec);
        switch (volba) {
            case 1:
                boj_s_vlkmi(&hrac[vyber_gen_hraca]);
                print_hrac(&hrac[vyber_gen_hraca]);
                break;
            case 2:
                vypis_hracov(&hrac[0], &vyber_hraca);
                if (vyber_gen_hraca == vyber_hraca) {
                    while (vyber_gen_hraca == vyber_hraca) {
                        printf(RED"S tymto hracom nemozes bojovat!!!\n"RESET);
                        printf("Vyber si este raz.\n");
                        vypis_hracov(&hrac[0], &vyber_hraca);
                    }
                }
                if (vyber_hraca == 1) {
                    boj_s_protivnikom(&hrac[vyber_gen_hraca], &hrac[1]);
                } else if (vyber_hraca == 2) {
                    boj_s_protivnikom(&hrac[vyber_gen_hraca], &hrac[2]);
                } else if (vyber_hraca == 3) {
                    boj_s_protivnikom(&hrac[vyber_gen_hraca], &hrac[3]);
                } else if (vyber_hraca == 4) {
                    boj_s_protivnikom(&hrac[vyber_gen_hraca], &hrac[4]);
                } else {
                    boj_s_protivnikom(&vyber_gen_hraca, &hrac[5]);
                }

                break;
            case 3:
                dolovanie(&hrac[vyber_gen_hraca],&polozky);
                print_hrac(&hrac[vyber_gen_hraca]);

                break;
            case 4:
                karcma(&hrac[vyber_gen_hraca],&polozky);
                print_hrac(&hrac[vyber_gen_hraca]);
                break;
            case 5:
                obchod(&hrac[vyber_gen_hraca],&polozky);
                print_hrac(&hrac[vyber_gen_hraca]);
                break;
            case 6:
                item_shop(&hrac[vyber_gen_hraca]);
                break;
            case 7:
                printf("Vyberte si jednu z nasledovnych postav:\n");
                vypis_hracov(&hrac[vyber_gen_hraca],&vyber_gen_hraca);
                break;
            case 8:
                print_centralny_sklad(polozky);
                print_hrac(&hrac[vyber_gen_hraca]);
                break;
            case 9:
                dokumentacia();
                break;
            case 10:
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


