#include <iostream>
#include "definitions.h"
#include "class.h"

int main()
{
    game play;
    while(1)
    {
        play.displayBoard();
        play.displayName(); 
        play.putPiece();
        system("cls");
    }
    
   
}

