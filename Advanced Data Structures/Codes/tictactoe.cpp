#include <iostream>
using namespace std;

class Tictactoe
{
    int board[3][3];
    public:
        Tictactoe()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    board[i][j] = 0;
                }
                
            }
            
        }
        bool player1_move(int x, int y)
        {
            if(board[x][y] != 0)
                return 1;
            board[x][y] = 1;
            showboard();
            if(check_win(x,y))
            {
                cout<<"Player 1 won";
            }
            return 0;
        }
        bool player2_move(int x, int y)
        {
            if(board[x][y] != 0)
                return 1;
            board[x][y] = 2;
            showboard();
            if(check_win(x,y))
            {
                cout<<"Player 2 won";
            }
            return 0;

        }
        bool check_win(int x, int y)
        {
            if (((board[x][0] == board[x][1]) && (board[x][1] == board[x][2]) && board[x][0] != 0 ) || ((board[0][y] == board[1][y]) && (board[1][y] == board[2][y]) && board[0][y] != 0) || 
                ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != 0) || ((board[2][0] == board[2][2]) &&( board[2][2] == board[0][2]) && board[2][0] != 0))
            {
                return 1;
            }
            return 0;
        }
        void showboard()
        {
            for (int i = 0; i < 3; i++)
            {
                cout<<"|------|------|------|\n";
                cout<<"|   "<<board[i][0]<<"  |  "<<board[i][1]<<"   |  "<<board[i][2]<<"   |\n";
                cout<<"|------|------|------|\n";
            }
            
        }
};
int main()
{
    Tictactoe game;
    int x,y;
    game.showboard();
    while (1)
    {
        cout<<"\nPlayer 1 :: ";
        cin>>x>>y;
        while(game.player1_move(x,y))
        {
            cout<<"Space already occupied.... try again!";
            cout<<"\nPlayer 1 :: ";
            cin>>x>>y;
        }
        cout<<"\nPlayer 2 :: ";
        cin>>x>>y;
        while(game.player2_move(x,y))
        {
            cout<<"Space already occupied.... try again!";
            cout<<"\nPlayer 2 :: ";
            cin>>x>>y;
        }
    }

}