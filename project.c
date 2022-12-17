/*

Name        : datenstrunkturen.c

Authoren    : Dilek Karaca, Kevin Fach

Beschreibung : Erstellung vom Spielfeld und initalisieurng von Spielern.


*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Erstelle eine konstante Variable für den Spieler und für die KI
int spielfeld[3][3];

void feldErneuern(){
// Alle Felder werden auf ' ' gesetzt
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
           spielfeld[i][j] = ' ';
        }
    }
}

int checkeFreieFelder(){
// Checken von freien Feldern in dem man runterzählt
    int freieFelder = 9;
    int i;
    int j;
    int feld[i][j];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] != ' '){
                freieFelder--;
            }
        }
    }
    return freieFelder;
}
/*
|  [0]  |  [1]  |  [2]  |
-------------------------
|  [3]  |  [4]  |  [5]  |         // <-- bsp FELD
-------------------------
|  [6]  |  [7]  |  [8]  |
*/
char checkeGewinner(){
    int i;
    int j;
    int feld[i][j];
    // Checke Spalte
    for(int i = 0; i < 3; i++){
        if(feld[i][0] == feld[i][1] && feld[i][0] == feld[i][2]){
            return feld [i][0];
        }
    }

    // Checke Reihe
     for(int i = 0; i < 3; i++){
     if(feld[0][i] == feld[1][i] && feld[0][i] == feld[2][i]){
        return feld[0][i];
        }
    }

    // Checke Diagonale
        if(feld[0][0] == feld[1][1] && feld[0][0] == feld[2][2]){
            return feld [0][0];
        }
         if(feld[0][2] == feld[1][1] && feld[0][2] == feld[2][0]){
            return feld[0][0];
        }
    return ' ';
}

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


void spielzug(){
    int x; //für Zeile
    int y; //für Spalten
    int i;
    int j;
    int feld[i][j];

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
        feld[x][y] =' ';
       
    }
    if(x < 1 || x > 3 || y < 1 || y > 3){

        printf("Ungueltige Eingabe! Bitte geben Sie nur 1, 2 oder 3 ein!\n");
    }
    while(x >= 1 || x <= 3 || y >= 1 || y <= 3){

        getchar();
    }
    
}
 char wechsel;
void spielerwechsel(){
    if(wechsel == 'X'){
        wechsel = 'O';
    } else{
        wechsel = 'X';
    }

}


int main(){
    int spielfeld[3][3];
   feldErneuern();
   checkeFreieFelder();
   spielzug();
   checkeGewinner();
    
    
}
