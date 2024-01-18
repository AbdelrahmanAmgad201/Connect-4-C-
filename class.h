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
        void displayName()
        {
            if(turn == 1)
            {
                cout << BLUE << player1Name << " Turn: " RESET;
            }
            else
                cout << RED << player2Name << " Turn: " RESET ;
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
                    if (plays[playrow][i] != 0 )
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
        }
        void checkVertical(int playcol)
        {
            for (int i = 0; i < 3; i++)
            {
                if (plays[i][playcol] == plays[i + 1][playcol] && plays[i + 1][playcol] == plays[i + 2][playcol] && plays[i + 2][playcol] == plays[i + 3][playcol])
                {
                    if(plays[i][playcol] != 0)
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
        }
        void checkDiagonals()
        {
            for(int i = 0 ; i<ROWS - 3 ; i++)
            {
                for(int j = 0 ;j<COLS - 3 ;j++) 
                {
                    if(plays[i][j] != 0)
                    {
                        if(plays[i][j] == plays[i+1][j+1] && plays[i+1][j+1] == plays[i+2][j+2] && plays[i+2][j+2] == plays[i+3][j+3] )
                        {
                            system("cls");
                            displayBoard();
                            switch (plays[i][j])
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
            }

            for(int i = ROWS - 3 ; i >= 0; i--)
            {
                for(int j = 0 ;j<COLS - 3 ;j++)  // Corrected condition
                {
                    if(plays[i][j] != 0)
                    {
                        if(plays[i][j] == plays[i+1][j-1] && plays[i+1][j-1] == plays[i+2][j-2] && plays[i+2][j-2] == plays[i+3][j-3] )
                        {
                            system("cls");
                            displayBoard();
                            switch (plays[i][j])
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
            }

        }
        void putPiece()
        {
            char moveC;
            cin >> moveC;
            int move = moveC - '1';
            if (move > 6 || move < 0)
            {
                do {
                    cout << "enter no between 1-7: ";
                    cin >> moveC;
                    move = moveC - '1'; 
                } while (move > 6 || move < 0);

            }

            for(int i = ROWS - 1; i >= 0; --i)
            {
                if(plays[i][move] == 0)
                {
                    plays[i][move] = turn;
                    turn = (turn == 1) ? 2 : 1;
                    playCount++;
                    checkHorizontal(i);
                    checkVertical(move);
                    checkDiagonals();
                    break;  

                }
            }
        }


};