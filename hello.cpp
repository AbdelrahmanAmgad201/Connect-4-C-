#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define ROWS 6
#define COLS 7

// check diagonal
// improve Display & add names
// input validation


using namespace std;

class game{
    public:
        int plays[ROWS][COLS] = {0};
        int turn = 1 ;
        int playCount = 0;
        string player1Name;
        string player2Name;
        game()
        {
            cout << "Player 1 name: ";
            getline(cin , player1Name);
            cout <<endl<< "Player 2 name: "<<endl;
            getline(cin , player2Name);
        }
        void displayBoard()
        {
            cout << MAGENTA << " 1 2 3 4 5 6 7"<< RESET <<endl;
            for(int i = 0 ; i<ROWS ; i++)
            {
                for(int j = 0 ; j<COLS; j++)
                {
                    cout << "|";
                    if(plays[i][j] == 1)
                    {
                        cout<< BLUE << "X" << RESET;
                    }
                    else if(plays[i][j] == 2)
                    {
                        cout<< RED << "X" << RESET ;
                    }
                    else
                        cout << " ";
                }
                cout<< "|" << endl;
            }
        }
        void checkHorizontal(int playrow)
        {
            for (int i = 0; i <= 3; i++)
            {
                if (plays[playrow][i] == plays[playrow][i + 1] && plays[playrow][i + 1] == plays[playrow][i + 2] && plays[playrow][i + 2] == plays[playrow][i + 3])
                {
                    system("cls");
                    displayBoard();
                    switch (plays[playrow][i])
                    {
                    case 1:
                        cout << BLUE << player1Name << RESET << " Wins";
                        exit(0);

                    case 2:
                        cout << RED << player2Name << RESET << " Wins";
                        exit(0);
                    }
                }
            }
        }
        void checkVertical(int playcol)
        {
            for (int i = 0; i < 3; i++)
            {
                if (plays[playcol][i] == plays[playcol][i + 1] && plays[playcol][i + 1] == plays[playcol][i + 2] && plays[playcol][i + 2] == plays[playcol][i + 3])
                {
                    system("cls");
                    displayBoard();
                    switch (plays[i][playcol])
                    {
                    case 1:
                        cout << BLUE << player1Name << RESET << " Wins";
                        exit(0);

                    case 2:
                        cout << RED << player2Name << RESET << " Wins";
                        exit(0);
                    }
                }
            }
        }

        void putPiece()
        {
            cout << endl << "Enter your move: ";
            int move;
            cin >> move;
            --move;

            for(int i = ROWS - 1; i >= 0; --i)
            {
                if(plays[i][move] == 0)
                {
                    plays[i][move] = turn;
                    turn = (turn == 1) ? 2 : 1;
                    playCount++;
                    checkHorizontal(i);
                    checkVertical(move);
                    break;  

                }
            }
        }


};
int main()
{
    game play;
    while(1)
    {
        play.displayBoard();
        play.putPiece();
        system("cls");
    }
    
   
}


