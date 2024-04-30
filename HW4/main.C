#include <iostream>
using namespace std;

class TicTacToe{
    private:
        char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
        int count;
        
    public:
        
        void run(){
            cout<<"-- Tic Tac Toe -- CSIE@CGU"<<endl;
            cout<<"Player 1 (X) - Player 2 (O)"<<endl;
        }
        
        void print_board(char Board[10]){
        
            for(int i=0;i<2;i++){
                cout<<" "<<board[3*i]<<" | "<<board[3*i+1]<<" | "<<board[3*i+2]<<" "<<endl;
                cout<<"---+---+---"<<endl;
            }
            cout<<" "<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<" "<<endl;
        }
        
        void print_hint(int Count){
            cout<<"==> Player "<<<<" ("<<X<<"), enter a number://這裡輸入"<<endl;
        }
}

int main()
{
    TicTacToe game;
    game.run();
    
    return 0;
}
