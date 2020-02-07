#include <string>
#include <vector>
#include <iostream>
using namespace std;
void remove_block(int m, int n, vector<string>& board, vector<vector<bool>>& check){
    bool flag = false;
    for(int i = 0 ; i < m-1 ; i++){
        for(int j = 0 ; j < n-1 ; j++){
            if(board[i][j] != 'x' && board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j+1]){
                check[i][j] = true;
                check[i+1][j] = true;
                check[i][j+1] = true;
                check[i+1][j+1] = true;
                flag = true;
            }
        }
    }
    for(int j = 0 ; j < n ; j++){
        for(int i = m-1 ; i >= 0 ; i--){
            if(check[i][j]){
                int tmp_i = i;
                while(check[tmp_i][j]){
                    board[tmp_i][j] = 'x';
                    tmp_i--;
                    if(tmp_i < 0) break;
                }
                if(tmp_i < 0) break;
                else {
                    board[i][j] = board[tmp_i][j];
                    board[tmp_i][j] = 'x';
                    check[i][j] = false;
                    check[tmp_i][j] = true;
                }
            }
        }
    }
    if(flag) remove_block(m,n,board,check);
    else return;
}

int show(vector<string> board){
    int cnt = 0;
    for(const auto& s : board){
        for(const auto& c : s)
            if(c == 'x') cnt++;
    }
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> check;
    for(int i = 0 ; i < m ; i++){
        vector<bool> tmp(n);
        check.push_back(tmp);
    }
    remove_block(m,n,board,check);
    answer = show(board);
    return answer;
}
