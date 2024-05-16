#include<iostream>

using namespace std;

class TicTacToe{
private:
    char m_game[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
    int m_times;

public:
    TicTacToe(){
        cout << "-- Tic Tac Toe -- CSIE@CGU" << endl;
        cout << "Player 1 (X) - Player 2 (O)" << endl;
        m_times = 0;
        status();
    }

    void run(){
        while(true){
            char number;
            if(m_times % 2){
                cout << "==> Player 2 (O), enter a number:";
            } 
            else {
                cout << "==> Player 1 (X), enter a number:";
            }
            cin >> number;
            if(put(number, m_times)){
                continue;
            }
            status();
            m_times++;
            if(m_times >= 9){
                cout << "==> Game draw" << endl;
                break;
            } else if(check()){
                cout << "==> Player " << check() << " wins!";
                break;
            }
        }
    }

    void status(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << " " << m_game[i][j] << " ";
                if(j != 2){
                    cout << "|";
                }
            }
            cout << endl;
            if(i != 2){
                cout << "---+---+---" << endl;
            }
        }
    }

    int put(char input, int times){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(m_game[i][j] == input){
                    if(times % 2){
                        m_game[i][j] = 'O';
                        return 0;
                    } else {
                        m_game[i][j] = 'X';
                        return 0;
                    }
                }
            }
        }
        cout << "==> Invalid value, please enter again" << endl;
        return 1;
    }

    int check(){
        for(int i = 0; i < 3; i++){
            if(m_game[i][0] == m_game[i][1] && m_game[i][2] == m_game[i][1] && m_game[i][0] == m_game[i][2]){
                if(m_game[i][0] == 'O'){
                    return 2;
                } else {
                    return 1;
                }
            }
            if(m_game[0][i] == m_game[1][i] && m_game[2][i] == m_game[1][i] && m_game[0][i] == m_game[2][i]){
                if(m_game[i][0] == 'O'){
                    return 2;
                } else {
                    return 1;
                }
            }
        }
        if(m_game[0][0] == m_game[1][1] && m_game[1][1] == m_game[2][2] && m_game[2][2] == m_game[0][0]){
            if(m_game[1][1] == 'O'){
                return 2;
            } else {
                return 1;
            }
        } else if(m_game[0][2] == m_game[1][1] && m_game[1][1] == m_game[2][0] && m_game[2][0] == m_game[0][2]){
            if(m_game[1][1] == 'O'){
                return 2;
            } else {
                return 1;
            }
        }
        return 0;
    }
};

int main(){
    TicTacToe game;
    game.run();
    return 0;
}