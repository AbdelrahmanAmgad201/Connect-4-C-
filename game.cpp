#include <iostream>

#include "definitions.h"
#include "class.h"

int main(void)
{
    game play;
    while(play.playCount<= ROWS * COLS)
    {
        play.displayBoard();
        play.displayName(); 
        play.putPiece();
        system("cls");
    }
    return 0;
   
}

