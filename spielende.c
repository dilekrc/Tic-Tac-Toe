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

void wer_gewinnt(){

    //HORIZONTAL 

    if(Feld[ 0 ] == 'X' && Feld[ 1 ] == 'X' && Feld[ 2 ] == 'X'){
        //return 1;
    } else if(Feld[ 3 ] == 'X' && Feld[ 4 ] == 'X' && Feld[ 5 ] == 'X'){
        //return 1;
    } else if(Feld[ 6 ] == 'X' && Feld[ 7 ] == 'X' && Feld[ 8 ] == 'X'){
        //return 1;
    }

    if(Feld[ 0 ] == 'O' && Feld[ 1 ] == 'O' && Feld[ 2 ] == 'O'){
        //return 1;
    } else if(Feld[ 3 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 5 ] == 'O'){
        //return 1;
    } else if(Feld[ 6 ] == 'O' && Feld[ 7 ] == 'O' && Feld[ 8 ] == 'O'){
        //return 1;
    }

    //VERTIKAL

    if(Feld[ 0 ] == 'X' && Feld[ 3 ] == 'X' && Feld[ 6 ] == 'X'){
        //return 1;
    } else if(Feld[ 1 ] == 'X' && Feld[ 4 ] == 'X' && Feld[ 7 ] == 'X'){
        //return 1;
    } else if(Feld[ 2 ] == 'X' && Feld[ 5 ] == 'X' && Feld[ 8 ] == 'X'){
        //return 1;
    }

    if(Feld[ 0 ] == 'O' && Feld[ 3 ] == 'O' && Feld[ 6 ] == 'O'){
        //return 1;
    } else if(Feld[ 1 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 7 ] == 'O'){
        //return 1;
    } else if(Feld[ 2 ] == 'O' && Feld[ 5 ] == 'O' && Feld[ 8 ] == 'O'){
        //return 1;
    }

    //DIAGONAL

    if(Feld[ 0 ] == 'X' && Feld[ 4 ] == 'X' && Feld[ 8 ] == 'X'){
        //return 1;
    } else if(Feld[ 2 ] == 'X' && Feld[ 4 ] == 'X' && Feld[ 6 ] == 'X'){
        //return 1;
    }

    if(Feld[ 0 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 8 ] == 'O'){
        //return 1;
    } else if(Feld[ 2 ] == 'O' && Feld[ 4 ] == 'O' && Feld[ 6 ] == 'O'){
        //return 1;
    } else{
        //return 0;
    }


}