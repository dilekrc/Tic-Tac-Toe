/*
=============================================================================================================
=============================================================================================================
 NAME: Spielende.c
AUTHOREN: Nathalie Kascha
BESCHREIBUNG: Es soll ermittelt werden, wer gewonnen hat oder ob das Spiel mit ein unentschieden endet.
=============================================================================================================
=============================================================================================================
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

COMPUTER = 'X'
SPIELER = 'O'

*/



/*Hier wird das MinMax-Algorithmus implementiertmmmm*/

    /*Den besten Zug für den computer finiden*/

    /*Der Computer ist dran*/


    void besten_zug(){
    int beste_wert = -999; //unendlich
    int wert;
    int best_zug;
    int max_spieler;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2) //Es wird jedes leere Feld durchgegangen
            feld[i][j] = 1; //setze O hin

            //Den wert des nächsten zugs berechnen
            int wert = minimax(feld, 0, -max_spieler);
            if(wert > beste_wert){
                beste_wert = wert;
            }
            feld[i][j] = 2; //setzen zurueck

            best_zug = i,j;

            return beste_wert;
            }
        }
        feld[best_zug][best_zug] = 1;
        int currrentplayer = -1;
    }




    int minimax(int Feld[3][3], int depth, int max_spieler){
    //Prüfen, ob jemand gewonnen hat
    int ergebnis = untersuchung();
    if(ergebnis != 0){
    //Score zurueckgegeben
    return ergebnis;
    }

    if(max_spieler){  //Der Computer ist dran

    int beste_wert = -999; //unendlich
    int wert;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2) //leeres Feld?

            feld[i][j] = 1; //setze O hin

            //Der wert des nächsten zugs berechnen
            wert = minimax(Feld, depth+1, -max_spieler);
            if(wert > beste_wert){
                beste_wert = wert;
            }
            feld[i][j] = 2; //setzen zurueck

            }
            
            return beste_wert;  //Alle moeglichen zuege für den Spieler
        }
    }else{

        int beste_wert = 999; //unendlich
        int wert;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(feld[i][j] == 2) //leeres Feld?

            feld[i][j] = -1; //setze O hin

            //Der wert des nächsten zugs berechnen
            wert = minimax(Feld, depth+1, max_spieler);
            if(wert < beste_wert){
                beste_wert = wert;
            }
            feld[i][j] = 2; //setzen zurueck

            }
        }
    
    return beste_wert;  //Alle moeglichen zuege für den Spieler
    }
}


