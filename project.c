/*
Name        : datenstrunkturen.c
Authoren    : Dilek Karaca, Kevin Fach
Beschreibung : Erstellung vom Spielfeld und initalisieurng von Spielern.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

// Erstelle eine konstante Variable für den Spieler und für die KI
char feld[3][3];
const char SPIELER ='X';
const char SPIELERZWEI = 'O';
const char COMPUTER = 'O';

int minimax(int depth, bool isMaximizing);
int check_minimax_win();

void feldErneuern(){
// Alle Felder werden auf ' ' gesetzt
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
           feld[i][j] = ' ';
        }
    }
}

void feldErstellen(){
    // Hier wird das Feld erstellt
    printf(" _____________________");
    printf("\n|  _________________  |");
    printf("\n| |                 | |");
    printf("\n| |    %c | %c | %c    | |", feld[0][0], feld[0][1], feld[0][2]);
    printf("\n| |   ---|---|---   | |\n");
    printf("| |    %c | %c | %c    | |", feld[1][0], feld[1][1], feld[1][2]);
    printf("\n| |   ---|---|---   | |\n");
    printf("| |    %c | %c | %c    | |", feld[2][0], feld[2][1], feld[2][2]);
    printf("\n| |_________________| |");
    printf("\n|_____________________|\n");
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

    // Checke Spalte um den Gewinner zu ermitteln
    for(int i = 0; i < 3; i++){
        if(feld[i][0] == feld[i][1] && feld[i][0] == feld[i][2] && feld[i][0] != ' '){
            return feld [i][0];
        }
    }

    // Checke Reihe um den Gewinner zu ermitteln
     for(int i = 0; i < 3; i++){
        if(feld[0][i] == feld[1][i] && feld[0][i] == feld[2][i] && feld[0][i] != ' '){
            return feld[0][i];
        }
    }

    // Checke Diagonale um den Gewinner zu ermitteln
        if(feld[0][0] == feld[1][1] && feld[0][0] == feld[2][2] && feld[0][0] != ' '){
            return feld [0][0];
        }
         if(feld[0][2] == feld[1][1] && feld[0][2] == feld[2][0] && feld[0][2] != ' '){
            return feld[0][2];
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

void spielzug(int modus){
    
    int x; //für Zeile
    int y; //für Spalten

    // Spieler 1 gegen Computer
    if(modus == 1){
        do{
        printf("\nWaehle eine Zeile und eine Spalte aus #(1-3): ");
        if(scanf("%d %d", &x, &y)==2){
            x--;
            y--;
        }else{
            printf("Ungueltiger Spielzug!\n");
          
        }
        
        if(feld[x][y] != ' ')
        {
            printf("Ungueltiger Spielzug!\n");
        }
        else
        {
            feld[x][y] = SPIELER;
            break;
        }
    }    while (feld[x][y] != ' ');
    //Spierler 1 und 2 im Mehrspielermodus
    }else if(modus == 2){
        do{
        printf("\nWaehle eine Zeile und eine Spalte aus #(1-3): ");
        if(scanf("%d %d", &x, &y)==2){
            x--;
            y--;
        }else{
            printf("Ungueltiger Spielzug!\n");
          
        }
        
        if(feld[x][y] != ' ')
        {
            printf("Ungueltiger Spielzug!\n");
        }
        else
        {
            feld[x][y] = SPIELER;
            break;
        }
    }    while (feld[x][y] != ' ');

    feldErstellen();
        
        do{
        printf("\nWaehle eine Zeile und eine Spalte aus #(1-3): ");
        if(scanf("%d %d", &x, &y)==2){
            x--;
            y--;
        }else{
            printf("Ungueltiger Spielzug!\n");
          
        }
        
        if(feld[x][y] != ' ')
        {
            printf("Ungueltiger Spielzug!\n");
        }
        else
        {
            feld[x][y] = SPIELERZWEI;
            break;
        }
    }    while (feld[x][y] != ' ');
    }
}
    
void computerSpielzug(){
    int move_i, move_j;

    // Setze besteWert INFINITY
    float besteWert = -INFINITY;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            // checken ob Spielfeld leer ist
            if (feld[i][j] == ' '){

                // feld wird temporär geändert um minimax aufzurufen und den Schritt zu berechnen
                feld[i][j] = COMPUTER;    
                float wert = minimax(0, false);

                // feld wird zurückgesetzt
                feld[i][j] = ' ';

                // Für den maximierenden Spieler: Wenn wert grösser als besteWert ist, übernimmt besteWert den Wert
                if (wert > besteWert){
                    besteWert = wert;
                    move_i = i;
                    move_j = j;
                }
                
            }           
        }
    }
    //Computer setzt 'O' auf das beste Feld
    feld[move_i][move_j] = COMPUTER;
}

// MINIMAX FUNCTION
int minimax(int depth, bool isMaximizing){     
    //Es wird überprüft zu welchem Ergebnis der jeweilige Schritt führt
    int ergebnis = check_minimax_win();
    
    if (ergebnis != 2){
        return ergebnis;
    }

    //Wenn Computer maximierend ist
    if (isMaximizing){
          
        //Setze besteWert zu -Infinity
        float besteWert = -INFINITY;

        //Durch das feld iterieren
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                // Checken ob feld an der Position leer ist
                if (feld[i][j] == ' '){

                    //Das feld bekommt das Symbol des maximierenden Spielers(COMPUTER)
                    //minimax wird aufgerufen um danach den minimierenden Spielzug zu analysieren
                    feld[i][j] = COMPUTER;
                    float wert = minimax(depth + 1, false);

                    // feld wird an der Position zurückgesetzt
                    feld[i][j] = ' ';
                    
                    // wert wird, falls grösser, als besteWert für den maximierenden Spieler(COMPUTER) gespeichert
                    if (wert > besteWert){
                        besteWert = wert;
                    }
                }
            }
        }
        return besteWert;
    }
    //Wenn COMPUTER minimierenden ist
    else{
        //Setze besteWert zu INFINITY
        float besteWert = INFINITY;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (feld[i][j] == ' '){

                    // Das feld bekommt das Symbol des maximierenden Spielers(SPIELER)
                    //minimax wird aufgerufen um danach den maximierend Spielzug zu analysieren
                    feld[i][j] = SPIELER;
                    float wert = minimax(depth + 1, true);
                    
                    // feld wird an der Position zurückgesetzt
                    feld[i][j] = ' ';

                    // wert wird, falls kleiner, als besteWert für den minimierenden Spieler(COMPUTER) gespeichert
                    if (wert < besteWert){
                        besteWert = wert;
                    }
                }
            }
        }
        return besteWert;
    }
}

//Funktion um zu analysieren welche Schritte in minimax zu welchem ergebnis führen
//Wenn SPIELER gewinnt wird -1 zurückgegeben, wenn COMPUTER gewinnt 1, bei Unentschieden 0 und wenn das Spiel noch läuft 2
int check_minimax_win(){
    // Checke Diagonale
    if(feld[0][0] == feld[1][1] && feld[0][0] == feld[2][2] && feld[0][0] == SPIELER){
        return -1;
    }else if(feld[0][2] == feld[1][1] && feld[0][2] == feld[2][0] && feld[0][2] == SPIELER){
        return -1;
    }else if(feld[0][0] == feld[1][1] && feld[0][0] == feld[2][2] && feld[0][0] == COMPUTER){
        return 1;
    }else if(feld[0][2] == feld[1][1] && feld[0][2] == feld[2][0] && feld[0][2] == COMPUTER){
        return 1;
    }
    // Checke Spalte und Reihe
    for(int i = 0; i < 3; i++){
        if(feld[i][0] == feld[i][1] && feld[i][0] == feld[i][2] && feld[i][0] == SPIELER){
            return -1;
        }else if(feld[i][0] == feld[i][1] && feld[i][0] == feld[i][2] && feld[i][0] == COMPUTER){
            return 1;
        }else if(feld[0][i] == feld[1][i] && feld[0][i] == feld[2][i] && feld[0][i] == SPIELER){
            return -1;
        }else if(feld[0][i] == feld[1][i] && feld[0][i] == feld[2][i] && feld[0][i] == COMPUTER){
            return 1;
        }//Checke ob Feld schon voll ist und es Unentschieden ist
        else if(checkeFreieFelder() == 0){
            return 0;
        }
    }
    return 2;
}

void gewinnerAusgabe(char gewinner, int modus){
    // Hier wird der Gewinner/Verlierer im Computermodus ausgegeben
    if(gewinner == SPIELER)
    {
        printf("Spieler 1 hat gewonnen!");
    }
    else if(gewinner == COMPUTER && modus == 1)
    {
        printf("Computer hat gewonnen!");
    }
    else if(gewinner == SPIELERZWEI && modus == 2)
    {
        printf("Spieler 2 hat gewonnen!");
    }else{
        printf("Unentschieden!");
    }
}

int main(){
    
    char gewinner = ' ';    // Variable für Gewinner
    char antwort;   // Variable um zu entscheiden, ob man nochmal spielen möchte
    int modus;  // Variable um zu entscheiden welchen Modus man spielen möchte

    printf(" __________   __     _______      __________    ____        _______      __________   __________   _______  \n");
    printf("|___    ___| |  |   |   ____|    |___    ___|  / __ \\      |   ____|    |___    ___| |   ____   | |   ____|\n");
    printf("    |  |     |  |   |  |             |  |     / /  \\ \\     |  |             |  |     |  |    |  | |  |____\n");
    printf("    |  |     |  |   |  |             |  |    / /____\\ \\    |  |             |  |     |  |    |  | |   ____|\n");
    printf("    |  |     |  |   |  |____         |  |   /  ______  \\   |  |____         |  |     |  |____|  | |  |____\n");
    printf("    |__|     |__|   |_______|        |__|  /__/      \\__\\  |_______|        |__|     |__________| |_______|\n");
    printf("\n __________________________________________________________________________________________________________");
    printf("\n __________________________________________________________________________________________________________\n");
    printf("\n\nMODUS: Computer(1) oder Mehrspieler(2)?\n");
    printf("\nEingabe : ");
    scanf("%d", &modus);

    do{
        gewinner = ' ';
        antwort = ' ';
        feldErneuern();
        
        if(modus == 1){
        // Spieler wählt Computermodus
        printf("\nSPIELER(X) COMPUTER(O)\n");
        while(gewinner == ' ' && checkeFreieFelder() != 0){     // Schleife die nur abgebrochen wird, wenn es einen Gewinner gibt oder es Unentschieden ist
        feldErstellen();
        spielzug(modus);
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){    // Falls die Schleife hier abgebrochen wird, gewinnt der Spieler
                break;
            }
        
        computerSpielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){    // Falls die Schleife hier abgebrochen wird, gewinnt die KI
                break;
            }
        }

    feldErstellen();
    gewinnerAusgabe(gewinner, modus);

    printf("\nMoechtest du nochmal spielen? (J/N): ");
    getchar();
    scanf("%c", &antwort);
    antwort = toupper(antwort);

    } else if(modus == 2){
        // Spieler wählt Mehrspielermodus
        printf("SPIELER 1(X) SPIELER 2(O)\n");
        while(gewinner == ' ' && checkeFreieFelder() != 0){        // Schleife die nur abgebrochen wird, wenn es einen Gewinner gibt oder es Unentschieden ist
        feldErstellen();
        spielzug(modus);
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){        // Falls die Schleife hier abgebrochen wird, gewinnt der erste Spieler
                break;
            }
        
        feldErstellen();
        spielzug(modus);
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){        // Falls die Schleife hier abgebrochen wird, gewinnt der zweite Spieler
                break;
            }
        }

    feldErstellen();
    gewinnerAusgabe(gewinner, modus);

    printf("\nMoechtest du nochmal spielen? (J/N): ");     // Abfrage ob man nochmal spielen will         
    getchar();
    scanf("%c", &antwort);      // Hier wird die Antwort erwartet die J oder N ist 
    antwort = toupper(antwort);     // ToUpper ist dafür da, um die Zeichenkette in Großbuchstaben auszugeben
    }else{
       
        printf("Ungueltige Eingabe!\n");    // Falls man den falschen Modus wählt, kommt die Ausgabe Ungültige Eingabe und das Program wird geschloßen
        abort();
    }
    }while(antwort == 'J');     // Falls man J auswählt fängt das Spiel von neu an

    printf("Danke fuers Spielen!");     // Falls man N auswählt, kommt die Ausgabe Danke fürs spielen und das Program schließt sich
    
    return 0;

}