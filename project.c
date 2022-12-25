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
   printf(" %c | %c | %c ", feld[0][0], feld[0][1], feld[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", feld[1][0], feld[1][1], feld[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", feld[2][0], feld[2][1], feld[2][2]);
   printf("\n");
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
/*
|  [0]  |  [1]  |  [2]  |
-------------------------
|  [3]  |  [4]  |  [5]  |         // <-- bsp FELD
-------------------------
|  [6]  |  [7]  |  [8]  |
*/
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

    // Zeile auswaehlen
    do{
      printf("Waehle eine Zeile #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Waehle eine Spalte #(1-3): ");
      scanf("%d", &y);
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
   } while (feld[x][y] != ' ');
}
    
void computerSpielzug(){
    
    srand(time(0));
    int x;
    int y;

    if(checkeFreieFelder() > 0){
      
      do{
         x = rand() % 3;
         y = rand() % 3;
      } while (feld[x][y] != ' ');
      
      feld[x][y] = COMPUTER;
   }
   else{
      gewinnerAusgabe(' ');
   }
}

void spielerZweiSpielzug(){
    
    int x; //für Zeile
    int y; //für Spalten

    // Zeile auswaehlen
    do{
      printf("Waehle eine Zeile #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Waehle eine Spalte #(1-3): ");
      scanf("%d", &y);
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
   } while (feld[x][y] != ' ');
}

void gewinnerAusgabe(char gewinner){
   
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
    
    char gewinner = ' ';
    char antwort;
    int a;

    printf("TIC TAC TOE SPIEL\n");
    printf("MODUS: Computer(1) oder Mehrspieler(2)?\n");
    printf("Eingabe : ");
    scanf("%d", &a);
    
    feldErneuern();

    do{
        gewinner = ' ';
        antwort = ' ';
        feldErneuern();
        
        if(a == 1){
        
        printf("SPIELER(X) COMPUTER(O)\n");
        while(gewinner == ' ' && checkeFreieFelder() != 0){
        feldErstellen();
        spielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){
                break;
            }
        
        computerSpielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){
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
        
        printf("SPIELER 1(X) SPIELER 2(O)\n");
        while(gewinner == ' ' && checkeFreieFelder() != 0){
        feldErstellen();
        spielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){
                break;
            }
        
        feldErstellen();
        spielerZweiSpielzug();
        
        gewinner = checkeGewinner();
            if(gewinner != ' ' || checkeFreieFelder() == 0){
                break;
            }
        }

    feldErstellen();
    gewinnerAusgabeMehrspieler(gewinner);

    printf("\nMoechtest du nochmal spielen? (J/N): ");
    getchar();
    scanf("%c", &antwort);
    antwort = toupper(antwort);
    }else{
       
        printf("Ungueltige Eingabe!\n");
        printf("\nMoechtest du nochmal spielen? (J/N): ");
        getchar();
        scanf("%c", &antwort);
        antwort = toupper(antwort);
    }
    }while(antwort == 'J');

    printf("Danke fuers Spielen!");
    
    return 0;

}
