#include <string>
#include <vector>
#include <iostream>
using namespace std;
int cnt;
int len;
void showall(vector<vector<int>>& board){
    for(const auto& raw : board){
        for(const auto& tup : raw){
            cout<<tup<<" ";
        }
        cout<<""<<endl;
    }
    cout<<""<<endl;
}
bool check(vector<vector<int>>& board, int x, int y){
    for(int i = 0 ; i < len ; i++)
        if(board[i][y] == 1 && i != x) return false;
    for(int i = x-1, j = y-1 ; (i >= 0 && j >= 0) ; i--, j--){
        if(board[i][j] == 1) return false;
    }
    for(int i = x-1, j = y+1 ; (i >= 0 && j < len) ; i--, j++){
        if(board[i][j] == 1) return false;
    }
    return true;
}
void find(vector<vector<int>>& board, int q, int x){
    if(q == len){
        cnt++;
        return;
    }
    
    for(int j = 0 ; j < len ; j++){
        if(check(board,x,j)){
            board[x][j] = 1;
            find(board,q+1,x+1);
            board[x][j] = 0;
        }
    }

}
int solution(int n) {
    int answer = 0;
    cnt = 0;
    len = n;
    vector<vector<int> > board(n,vector<int>(n,0));
    find(board, 0, 0);
    answer = cnt;
    return answer;
}
