#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int> > board(m+1, vector<int>(n+1,1));
    for(const auto& puddle : puddles){
        if(!puddle.empty()){
            int tmp_m = puddle[0] , tmp_n = puddle[1];
            board[tmp_m][tmp_n] = 0;
        }
    }
    for(int i = 0 ; i <= n ; i++)
        board[0][i] = 0;
    for(int i = 0 ; i <= m ; i++)
        board[i][0] = 0;

    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= n ; j++){
            if((i == 1 && j == 1) || board[i][j] == 0) continue;
            else {
                board[i][j] = (board[i-1][j] + board[i][j-1])%1000000007;
            }
        }
    }
    answer = board[m][n];
    return answer;
}
