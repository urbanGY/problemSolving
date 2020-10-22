#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d, w, k;
vector<vector<int> > board;
bool flag;

bool check() {
        for(int i= 0; i < w; i++) {
                int before = board[0][i], cnt = 0, maxCnt = 0; // maxCnt로 마지막에 값을 판단하는데 이 값이 갱신되지 않을 경우도 생각해야 한다. 즉 한번도 같은 셀이 없는 경우라면 이 값을 갱신하지 않을 것이고 0을 반환하도록 초기 값을 0으로 해야 마지막 케이스가 통과된다.
                for(int j = 1; j < d; j++) {
                        if(board[j][i] == before) {
                                cnt++;
                                if(cnt > maxCnt) maxCnt = cnt;
                        }else cnt = 0;
                        before = board[j][i];
                }
                if(maxCnt+1 < k) {
                        return false;
                }
        }
        return true;
}

void find(int cur, int target, int start) {
        if(flag) return;
        if(cur == target) {
                if(check()) flag = true;
                return;
        }
        for(int i = start; i < d; i++) {
                for(int j = 0; j < w; j++) { // 경우의 수를 뽑아놓고 마지막에 순회하는 방식은 시간손해가 발생한다. 더럽더라도 순회중에 변화시킬 수 있도록 하자.
                        board[i][j+w] = board[i][j];
                        board[i][j] = 0;
                }

                find(cur+1,target,i+1);

                for(int j = 0; j < w; j++)
                        board[i][j] = 1;

                find(cur+1,target,i+1);

                for(int j = 0; j < w; j++)
                        board[i][j] = board[i][j+w];
        }
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                flag = false;
                scanf(" %d %d %d",&d,&w,&k);
                board = vector<vector<int> >(d,vector<int>(w*2));
                for(int i = 0; i < d; i++) {
                        for(int j = 0; j < w; j++) {
                                scanf(" %d",&board[i][j]);
                        }
                }
                if(check()) {
                        printf("#%d %d\n",test_case,0);
                        continue;
                }
                for(int i = 1; i  <= k; i++) {
                        find(0,i,0);
                        if(flag) {
                                printf("#%d %d\n",test_case,i);
                                break;
                        }
                }
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
