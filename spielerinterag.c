/*
======================================================================================================
NAME: tictactoe.interagieren.spieler.c
AUTOR: Mila Le
VERSION: v0.1
COPYRIGHT: 2022, Fachhochschule Suedwestfalen
BESCHREIBUNG: Interagieren mit Spieler in Tic Tac Toe in C
=====================================================================================================
VERSION GESCHICHTE:
- v0.1:


=====================================================================================================
*/
#include <stdio.h>

void spielzug(){
    int x; //für Zeile
    int y; //für Spalten


    // Zeile auswaehlen
    printf("Waehle eine Zeile (1-3): \n");
    scanf("%d", &x);

    // Spalte auswaehlen
    printf("Waehle eine Spalte (1-3): \n");
    scanf("%d", &y);

    // Eingabe muss leerem Feld entsprechen
    if(feld[x][y] =! ' '){
        printf("Ungueltiger Spielzug");
    } else{
        feld[x][y] =        ;
        break;
    }
    if(x < 1 || x > 3 || y < 1 || y > 3){

        printf("Ungueltige Eingabe! Bitte geben Sie nur 1, 2 oder 3 ein!\n");
    }
    while(x >= 1 || x <= 3 || y >= 1 || y <= 3){

        getchar();
    }
    
}

void spielerwechsel(char wechsel){
    if(wechsel == 'X'){
        wechsel = 'O';
    } else{
        wechsel = 'X';
    }

}