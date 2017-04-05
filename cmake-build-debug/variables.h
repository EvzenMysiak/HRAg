//
// Created by mysiak on 04.04.17.
//

#ifndef HRAG_VARIABLES_H
#define HRAG_VARIABLES_H

#define moznost_vyhry 100
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
#define cena_zivota 150
//define colours
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

#endif //HRAG_VARIABLES_H

void dokumentacia(){
    printf(RED"Boj s vlkmi:\n"RESET);
    printf(GRN"\tV tejto sekcii tvoja postava bojuje s random vlkom vykenerovanym prirodou.\n"
                   "vlk sa ti podda len ak mas vacsiu silu a obranu ako on. V niektorych pripadoch\n "
                   "ked ma tvoja postava rovnaku silu ako vlk je to len na stasti kto vyhra. \n"
                   "Vyhra nad vlkom ti zabezpeci par minci a silu no odoberie energiu\n"RESET);
    printf(RED"\nBoj s inym hracom:\n"RESET);
    printf(GRN"\tV tejto sekcii bojujes podobne ako s vlkmi no tvoj protivnik je pseudonahodny hrac\n"
                   "o to si treba viac davat pozor lebo nevies co mu priroda nadelila\n"RESET);
    printf(RED"\nDolovanie rudy (praca):\n"RESET);
    printf(GRN"\tV tejto sekcii tazis rudu. Tento proces bezi autonomne a iba ti vypise kolko si jej vytazil.\n"
                   "mnozstvo vytazenej rudy zavisi od mnozstva energie tvojej postavy\n"RESET);
    printf(RED"\nObchod:\n"RESET);
    printf(GRN"\tV tejto sekcii najdes vsetko potrebne k vyvoju hry, ci uz predaj hrudy alebo nakup jedla.\n"RESET);
    printf(RED"\nVylepsenia:\n"RESET);
    printf(GRN"\tV tejto sekcii najdes tooly na vylepsenie tvojich hracov. Mozes si tu vylepsit silu a obranu. Samozrejme\n"
                   "nic nejde bez penazi\n"RESET);
    printf(RED"\nVyber z inych posta:\n"RESET);
    printf(GRN"\tV tejto sekcii si mozes zvolit niektoru z pseudonahodnych postav za ktoru mozes dalej hrat hru.\n"
                   "tuto postavu mozes kedykolvek zmenit\n"RESET);
    printf(RED"Vypis hodnot\n"RESET);
    printf(GRN"\tV tejto sekcii sa ti vypisu hodnoty tvojho aktualneho hraca a skladu\n");
    printf(RED"\nDokumentacia:\n"RESET);
    printf(GRN"\tV tejto sekcii najdete toto...\n"RESET);
    printf(RED"\nKoniec hry:\n"RESET);
    printf(GRN"Myslim ze toto je kazdemu jasne\n\n"RESET);
}


void credits(){
    printf("Create by Michal Janosik\n");
    printf("Zadanie 1 - Hra");
}

void welcome(){
    printf("Vitajte v mojej konzolovej aplikacii HRAq\n");
    printf("Hra je odvodena od hry Dwarf Fortress\n");
    printf("Podme teda hrat\n");
}




