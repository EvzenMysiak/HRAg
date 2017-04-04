//
// Created by mysiak on 04.04.17.
//

#ifndef HRAG_VARIABLES_H
#define HRAG_VARIABLES_H

#define MIN_energy 10
//energeticke hodnoty jedla a ich cena
#define steak 20
#define steak_cena 10
#define zemiaky 10
#define zemiaky_cena 5
#define salat 5
#define salat_cena 2
#define beer_crafted 25
#define beer_crafted_cena 10
#define beer_botled 24
#define beer_botled_cena 9
#define vodka 30
#define vodka_cena 15
#define paleno 35
#define paleno_cena 18

//cena rudy
#define cena_rudy 2
//item shop
#define cena_vylepsenia_obrany 5
#define cena_vylepsenie_sily 5

#endif //HRAG_VARIABLES_H

void dokumentacia(){
    printf("Boj s vlkmi:\n");
    printf("V tejto sekcii tvoja postava bojuje s random vlkom vykenerovanym prirodou.\n"
                   "vlk sa ti podda len ak mas vacsiu silu a obranu ako on. V niektorych pripadoch\n "
                   "ked ma tvoja postava rovnaku silu ako vlk je to len na stasti kto vyhra. \n"
                   "Vyhra nad vlkom ti zabezpeci par minci a silu no odoberie energiu\n");
    printf("\nBoj s inym hracom:\n");
    printf("V tejto sekcii bojujes podobne ako s vlkmi no tvoj protivnik je pseudonahodny hrac\n"
                   "o to si treba viac davat pozor lebo nevies co mu priroda nadelila\n");
    printf("\nDolovanie rudy (praca):\n");
    printf("V tejto sekcii tazis rudu. Tento proces bezi autonomne a iba ti vypise kolko si jej vytazil.\n"
                   "mnozstvo vytazenej rudy zavisi od mnozstva energie tvojej postavy\n");
    printf("\nObchod:\n");
    printf("V tejto sekcii najdes vsetko potrebne k vyvoju hry, ci uz predaj hrudy alebo nakup jedla.\n");
    printf("\nVylepsenia:\n");
    printf("v tejto sekcii najdes tooly na vylepsenie tvojich hracov. Mozes si tu vylepsit silu a obranu. Samozrejme\n"
                   "nic nejde bez penazi\n ");
    printf("\nVyber z inych posta:\n");
    printf("V tejto sekcii si mozes zvolit niektoru z pseudonahodnych postav za ktoru mozes dalej hrat hru.\n"
                   "tuto postavu mozes kedykolvek zmenit\n");
    printf("\nDokumentacia:\n");
    printf("V tejto sekcii najdete toto...\n");
    printf("\nKoniec hry:\n");
    printf("Myslim ze toto je kazdemu jasne\n\n");
}




