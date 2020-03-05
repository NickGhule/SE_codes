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
        void player1_move(int x, int y)
        {
            board[x][y] = 1;
            showboard();
            if(check_win(x,y))
            {
                cout<<"Player 1 won";
            }
        }
        void player2_move(int x, int y)
        {
            board[x][y] = 2;
            showboard();
            if(check_win(x,y))
            {
                cout<<"Player 2 won";
            }

        }
        bool check_win(int x, int y)
        {
            if (((board[x][0] == board[x][1]) && (board[x][1] == board[x][2])) || ((board[0][y] == board[1][y]) && (board[1][y] == board[2][y])) || 
                ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) || ((board[2][0] == board[2][2]) &&( board[2][2] == board[0][2])))
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
        cin>>x>>y;
        game.player1_move(x,y);
        cin>>x>>y;
        game.player2_move(x,y);
    }

}