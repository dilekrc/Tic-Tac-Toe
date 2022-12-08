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


