/*
Name        : datenstrunkturen.c

Authoren    : Dilek Karaca, Kevin Fach

Beschreibung : Erstellung vom Spielfeld und initalisieurng von Spielern.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Erstelle eine konstante Variable für den Spieler und für die KI
char feld[3][3];
const char SPIELER ='X';
const char SPIELERZWEI = 'O';
const char COMPUTER = 'O';

void feldErneuern();
void feldErstellen();
int checkeFreieFelder();
void spielzug();
void computerSpielzug();
void spielerZweiSpielzug();
char checkeGewinner();
void gewinnerAusgabe(char);
void gewinnerAusgabeMehrspieler(char);

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

void spielzug(){
    
    int x; //für Zeile
    int y; //für Spalten

    // Zeile und Spalte auswählen
    do{
        printf("\nWaehle eine Zeile und eine Spalte aus #(1-3): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        

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
}
    
void computerSpielzug(){
    
    srand(time(0));
    int x;
    int y;

    do{
        x = rand() % 3;
        y = rand() % 3;
    }while (feld[x][y] != ' ');
      
    feld[x][y] = COMPUTER;
}

void spielerZweiSpielzug(){
    
    int x; //für Zeile
    int y; //für Spalten

    // Zeile auswaehlen
    do{
        printf("\nWaehle eine Zeile und eine Spalte aus #(1-3): ");
        scanf("%d %d", &x, &y);
        x--;
        y--;

        if(feld[x][y] != ' ')
        {
            printf("Ungueltiger Spielzug!\n");
        }
        else
        {
            feld[x][y] = SPIELERZWEI;
            break;
        }
    }       while (feld[x][y] != ' ');
}

void gewinnerAusgabe(char gewinner){
    // Hier wird der Gewinner/Verlierer im Computermodus ausgegeben
    if(gewinner == SPIELER)
    {
        printf("Du hast gewonnen!");
    }
    else if(gewinner == COMPUTER)
    {
        printf("Du hast verloren!");
    }
    else{
        printf("Unentschieden!");
    }
}

void gewinnerAusgabeMehrspieler(char gewinner){
    // Hier wird der Gewinner/Verlierer im Mehrspielermodus ausgegeben
    if(gewinner == SPIELER)
    {
        printf("Spieler 1 gewinnt!");
    }
    else if(gewinner == SPIELERZWEI)
    {
        printf("Spieler 2 gewinnt!");
    }
    else{
        printf("Unentschieden!");
    }
}

int main(){
    
    char gewinner = ' ';    // Variable für Gewinner
    char antwort;   // Variable um zu entscheiden, ob man nochmal spielen möchte
    int a;  // Variable um zu entscheiden welchen Modus man spielen möchte

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
    scanf("%d", &a);

    do{
        gewinner = ' ';
        antwort = ' ';
        feldErneuern();
        
        if(a == 1){
        // Spieler wählt Computermodus
        printf("\nSPIELER(X) COMPUTER(O)\n");
        while(gewinner == ' ' && checkeFreieFelder() != 0){     // Schleife die nur abgebrochen wird, wenn es einen Gewinner gibt oder es Unentschieden ist
        feldErstellen();
        spielzug();
        
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
    gewinnerAusgabe(gewinner);

    printf("\nMoechtest du nochmal spielen? (J/N): ");
    getchar();
    scanf("%c", &antwort);
    antwort = toupper(antwort);

    } else if(a == 2){
        // Spieler wählt Mehrspielermodus
        printf("SPIELER 1(X) SPIELER 2(O)\n");
        while(gewinner == ' ' && checkeFreieFelder() != 0){        // Schleife die nur abgebrochen wird, wenn es einen Gewinner gibt oder es Unentschieden ist
        feldErstellen();
        spielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){        // Falls die Schleife hier abgebrochen wird, gewinnt der erste Spieler
                break;
            }
        
        feldErstellen();
        spielerZweiSpielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){        // Falls die Schleife hier abgebrochen wird, gewinnt der zweite Spieler
                break;
            }
        }

    feldErstellen();
    gewinnerAusgabeMehrspieler(gewinner);

    printf("\nMoechtest du nochmal spielen? (J/N): ");     // Abfrage ob man nochmal spielen will         
    getchar();
    scanf("%c", &antwort);      // Hier wird die Antwort erwartet die J oder N ist 
    antwort = toupper(antwort);     // ToUpper ist dafür da, um die Zeichenkette in Großbuchstaben auszugeben
    }else{
       
        printf("Ungueltige Eingabe!\n");    // Falls man den falschen Modus wählt, kommt die Ausgabe Ungültige Eingabe
        abort();
    }
    }while(antwort == 'J');

    printf("Danke fuers Spielen!");
    
    return 0;

}