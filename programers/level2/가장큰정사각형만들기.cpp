#include <iostream>
#include<vector>
using namespace std;

int least(int a, int b, int c){
    int tmp = b < c ? b : c;
    return a < tmp ? a : tmp;
}
int solution(vector<vector<int>> board)
{
    int cnt = 0;
    if(board.size() < 2 || board[0].size() < 2){
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == 1) return 1;
            }
        }
    }
    for(int i = 1 ; i < board.size() ; i++){
        for(int j = 1 ; j < board[0].size() ; j++){
            if(board[i][j]){
                board[i][j] = least(board[i-1][j], board[i][j-1], board[i-1][j-1]) + 1;
                if(cnt < board[i][j]) cnt = board[i][j];
            }
        }
    }
    return cnt*cnt;
}
