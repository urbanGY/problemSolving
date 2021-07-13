#include <iostream>
#include <vector>
using namespace std;

int least(int a, int b, int c){
        int tmp = b < c ? b : c;
        return a < tmp ? a : tmp;
}
int solution(vector<vector<int> > board)
{
        int cnt = 0;
        if(board.size() < 2 || board[0].size() < 2) {
                for(int i = 0; i < board.size(); i++) {
                        for(int j = 0; j < board[0].size(); j++) {
                                if(board[i][j] == 1) return 1;
                        }
                }
        }
        for(int i = 1; i < board.size(); i++) {
                for(int j = 1; j < board[0].size(); j++) {
                        if(board[i][j]) {
                                board[i][j] = least(board[i-1][j], board[i][j-1], board[i-1][j-1]) + 1;
                                if(cnt < board[i][j]) cnt = board[i][j];
                        }
                }
        }
        return cnt*cnt;
}
// 대각선 좌측 위, 위, 왼쪽, 나 모두가 1보다 클 경우 나를 제외한 세개의 수 중 가장 작은 수 +1 이 내 수가 된다. 이 수 를 누적시켜 가장 큰 수를 관리해 이를 제곱한게 가장 큰 네모를 찾는 방법이 된다.
