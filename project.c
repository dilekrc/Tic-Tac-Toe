/*

Name        : datenstrunkturen.c

Authoren    : Dilek Karaca, Kevin Fach

Beschreibung : Erstellung vom Spielfeld und initalisieurng von Spielern.


*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Erstellt ein zweidimensionalen Feld mit 9 Bereichen
char feld[3][3]; 
// Erstelle eine konstante Variable für den Spieler und für die KI

void feldErneuern(){
// Alle Felder werden auf ' ' gesetzt
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            feld[i][j] = ' ';
        }
    }
}

int checkeFreieFelder(){
// Checken von freien Feldern in dem man runterzählt
    int freieFelder = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] != ' '){
                freieFelder--;
            }
        }
    }
    return freieFelder;
}

char checkeGewinner(){
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


/* NAME: Spielende.c
AUTHOREN: Nathalie Kascha
BESCHREIBUNG: Es soll ermittelt werden, wer gewonnen hat oder ob das Spiel mit ein unentschieden endet.
*/


#include <stdio.h>

int main(){

    return 0;
}

/*
|  [0]  |  [1]  |  [2]  |
-------------------------
|  [3]  |  [4]  |  [5]  |         // <-- bsp FELD
-------------------------
|  [6]  |  [7]  |  [8]  |
*/

int wer_gewinnt(){

    //HORIZONTAL 

    int Feld[9];

    if(Feld[ 0 ] == 'X' && Feld[ 1 ] == 'X' && Feld[ 2 ] == 'X'){
        return 1;
    } else if(Feld[ 3 ] == 'X' && Feld[ 4 ] == 'X' && Feld[ 5 ] == 'X'){
        return 1;
    } else if(Feld[ 6 ] == 'X' && Feld[ 7 ] == 'X' && Feld[ 8 ] == 'X'){
        return 1;
    }

    if(Feld[ 0 ] == 'O' && Feld[ 1 ] == 'O' && Feld[ 2 ] == 'O'){
        return 1;
    } else if(Feld[ 3 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 5 ] == 'O'){
        return 1;
    } else if(Feld[ 6 ] == 'O' && Feld[ 7 ] == 'O' && Feld[ 8 ] == 'O'){
        return 1;
    }

    //VERTIKAL

    if(Feld[ 0 ] == 'X' && Feld[ 3 ] == 'X' && Feld[ 6 ] == 'X'){
        return 1;
    } else if(Feld[ 1 ] == 'X' && Feld[ 4 ] == 'X' && Feld[ 7 ] == 'X'){
        return 1;
    } else if(Feld[ 2 ] == 'X' && Feld[ 5 ] == 'X' && Feld[ 8 ] == 'X'){
        return 1;
    }

    if(Feld[ 0 ] == 'O' && Feld[ 3 ] == 'O' && Feld[ 6 ] == 'O'){
        return 1;
    } else if(Feld[ 1 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 7 ] == 'O'){
        return 1;
    } else if(Feld[ 2 ] == 'O' && Feld[ 5 ] == 'O' && Feld[ 8 ] == 'O'){
        return 1;
    }

    //DIAGONAL

    if(Feld[ 0 ] == "X/O" && Feld[ 4 ] == "X/O" && Feld[ 8 ] == "X/O"){
        return 1;
    } else if(Feld[ 2 ] == "X/O" && Feld[ 4 ] == "X/O" && Feld[ 6 ] == "X/O"){
        return 1;
    }

    if(Feld[ 0 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 8 ] == 'O'){
        return 1;
    } else if(Feld[ 2 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 6 ] == 'O'){
        return 1;
    } else{
        return 0;
    }


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
        feld[x][y] =' ';
       
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
