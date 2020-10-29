#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k,cnt;
int aabs(int a) {
        return a > 0 ? a : -a;
}
bool isPossible(vector<int>& v) {
        vector<int> dp_r(n), dp_l(n);
        vector<int> dp(n);
        for(int i = 0; i <n; i++) {
                if(i == 0) dp_l[i] = 1;
                else if(v[i] == v[i-1]) dp_l[i] = 1 + dp_l[i-1];
                else dp_l[i] = 1;
        }
        for(int i = n-1; i >= 0; i--) {
                if(i == n-1) dp_r[i] = 1;
                else if(v[i] == v[i+1]) dp_r[i] = 1 + dp_r[i+1];
                else dp_r[i] = 1;
        }
        for(int i = 0; i < n; i++) dp[i] = dp_l[i] + dp_r[i] -1;
        for(int i = 1; i < n; i++) {

                int cur = v[i], before = v[i-1];

                if(before == cur) continue;
                else if(aabs(before - cur) > 1) return false;
                else if(before < cur) {
                        if(dp[i-1] < k) return false;
                }else if(before > cur) {
                        if(dp[i] < k) return false;
                        //cout<<"?"<<endl;
                        for(int q = i; q < n; q++) {
                                if(v[q] == cur) {
                                        //cout<<v[q]<<" -> "<<v[q]-1<<endl;
                                        //v[q] -= 1;
                                        dp[q] -= k;
                                }else {
                                        break;
                                }
                        }

                }
        }
        return true;
}

int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                cnt = 0;
                scanf(" %d %d",&n,&k);
                vector<vector<int> > board(n,vector<int>(n,0));
                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                scanf(" %d",&board[i][j]);
                        }
                }
                for(int i = 0; i < n; i++) {
                        vector<int> tmp;
                        for(int j = 0; j < n; j++) tmp.push_back(board[i][j]);
                        if(isPossible(tmp)) {
                                cnt++;
                                //cout<<"h : "<<i<<endl;
                        }
                }
                for(int i = 0; i < n; i++) {
                        vector<int> tmp;
                        for(int j = 0; j < n; j++) tmp.push_back(board[j][i]);
                        if(isPossible(tmp)) {
                                cnt++;
                                //cout<<"v : "<<i<<endl;
                        }
                }
                printf("#%d %d\n",test_case, cnt);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
