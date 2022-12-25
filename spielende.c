/* NAME: Spielende.c
AUTHOREN: Nathalie Kascha
BESCHREIBUNG: Es soll ermittelt werden, wer gewonnen hat oder ob das Spiel mit ein unentschieden endet.
*/


#include <stdio.h>

int main(){

    return 0;
}

/*
|  [0.0]  |  [0.1]  |  [0.2]  |
-------------------------------
|  [1.0]  |  [1.1]  |  [1.2]  |         // <-- bsp. FELD
-------------------------------
|  [2.0]  |  [2.1]  |  [2.2]  |

UNTERSUCHUNG
'X' hat den Wert "+1", wenn er gewinnt.
'O' hat den Wert "-1", wenn er gewinnt.
unentschieden hat den Wert "0", wenn es unentschieden ausging.
Wenn es unklar ist, dann "2".

COMPUTER = 'O'
HUMAN = 'X'

*/

void untersuchung(){

    /*Hier wird jedes Feld nach 'X' ueberprueft*/

    //Horizontal geprueft, wer gewinnt.
    for(int i = 0; i < 3; i++){
        if(feld[i][0] == 1 && feld[i][1] == 1 &&feld[i][2] == 1) 
        return 1;
    }
    //Vertikal
    for(int i = 0; i < 3; i++){
         if(feld[0][i] == 1 && feld[1][i] == 1 &&feld[2][i] == 1)
        return 1;
    }
    //Diagonal
    if(feld[0][0] == 1 && feld[1][1]==1 && feld[2][2]==1)
    return 1;

    if(feld[0][2] == 1 && feld[1][1]==1 && feld[2][0]==1)
    return 1;

    /*Hier wird jedes Feld nach 'X' ueberprueft*/

    //Horizontal geprueft, wer gewinnt.
    for(int i = 0; i < 3; i++){
        if(feld[i][0] == -1 && feld[i][1] == -1 &&feld[i][2] == -1) //Hier wird jedes Feld nach 'O' ueberprueft
        return -1;
    }
    //Vertikal
    for(int i = 0; i < 3; i++){
         if(feld[0][i] == -1 && feld[1][i] == -1 &&feld[2][i] == -1)
        return -1;
    }
    //Diagonal
    if(feld[0][0] == -1 && feld[1][1]== -1 && feld[2][2]== -1)
    return -1;

    if(feld[0][2] == 1 && feld[1][1]==1 && feld[2][0]==1)
    return -1;

    /*Hier werden alle Positionen durchgegangen. Und es wird ueberprueft, ob ein Feld offen ist = "Unklar"*/
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2)
            return 2;
        }
    /*Wenn ich keine Position gefunden habe die unbelegt ist, dann ist es ein unentschieden*/
    return 0;
    }
}

/*Hier wird das MinMax-Algorithmus implementiert*/

void max(){
    if untersuchung() != 2; //Wenn alle Felder belegt sind, wird sie zurueck zur Untersuchung
    return untersuchung();

    /*Wir setzten an jeder Position die noch moeglich ist unseren spielstand, bei MAX wird es ein 'X' danach wird das ganze untersucht und es wird
    MIN aufgerufen*/

    int maximal_wert = -999; //unendlich
    int wert;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2) //leeres Feld?
            feld[i][j] = 1; //setzen auf MIN auf
            wert = min()
            if(wert > maximal_wert){
                maximal_wert = wert;
            }
            feld[i][j] = 2; //setzen zurueck

            return maximal_wert;
        }
    }
}

void min(){

    int minimal_wert = 999; //unendlich
    int wert;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2) //leeres Feld?
            feld[i][j] = -1; //setzen auf MIN auf
            wert = max();
            if(wert < minimal_wert){
                minimal_wert = wert;
            }
            feld[i][j] = 2; //setzen zurueck

            return minimal_wert;
        }
    }
}

/*Der Computer muss automatisch die MINIMUM Werte generieren und speichern.
 Wo setzte ich mein optimalen Zug?*/

 int minimum_I = 0;
 int minimum_J = 0;

void min_location(){

    int minimal_wert = 999; //unendlich
    int wert;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2) //leeres Feld?
            feld[i][j] = -1; //setzen auf MIN auf
            wert = max();
            if(wert < minimal_wert){
                minimal_wert = wert;
                minimum_I = i;  /* Hier werden die Positionen gespeichert*/
                minimum_J = j;
            }
            feld[i][j] = 2; //setzen zurueck

            return minimal_wert;
        }
    }
}

