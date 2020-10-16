#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, answer = -1;
vector<vector<int> > board;
bool check(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= n) return false;
        return true;
}
void find(int w, int h, int x, int y) {
        set<int> type;
        type.insert(board[x][y]);
        for(int i = 0; i < w; i++) {
                x += 1;
                y += 1;
                if(check(x,y)) {
                        type.insert(board[x][y]);
                }else return;
        }
        for(int i = 0; i < h; i++) {
                x += 1;
                y -= 1;
                if(check(x,y)) type.insert(board[x][y]);
                else return;
        }
        for(int i = 0; i < w; i++) {
                x -= 1;
                y -= 1;
                if(check(x,y)) type.insert(board[x][y]);
                else return;
        }
        for(int i = 0; i < h; i++) {
                x -= 1;
                y += 1;
                if(check(x,y)) type.insert(board[x][y]);
                else return;
        }
        int total = (w+h)*2; // w*h*2 가 아니라 w+h 가 맞다 ㅡㅡ
        if(type.size() == total && total > answer) {
                answer = total;
        }
}
int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                answer = -1;
                scanf(" %d",&n);
                board = vector<vector<int> >(n,vector<int>(n));
                for(int i = 0; i < n; i++)
                        for(int j = 0; j < n; j++)
                                scanf(" %d", &board[i][j]);

                for(int i = 1; i <= n-2; i++) {
                        for(int j = 1; j <= n-2 - i+1; j++) {
                                for(int x = 0; x < n; x++) {
                                        for(int y = 0; y < n; y++) {
                                                find(i,j,x,y);
                                        }
                                }
                        }
                }
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
