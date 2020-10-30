#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int aabs(int a) {
        return a > 0 ? a : -a;
}
int getDistance(int x, int y, int x_, int y_) {
        return aabs(x-x_) + aabs(y-y_);
}
int main(int argc, char** argv)
{
        int test_case;
        int T;
        cin>>T;
        for(test_case = 1; test_case <= T; ++test_case)
        {
                scanf(" %d %d",&n,&m);
                vector<pair<int,int> > house;
                vector<vector<int> > board(n,vector<int>(n,0));

                for(int i = 0; i < n; i++) {
                        for(int j = 0; j < n; j++) {
                                int input;
                                scanf(" %d",&input);
                                if(input == 1) {
                                        board[i][j] = 1;
                                        house.push_back({i,j});
                                }
                        }
                }
                int answer = -1;
                for(int k = 1; k <= n+1; k++) {
                        int cost = (k*k) + (k-1)*(k-1);
                        for(int x = 0; x < n; x++) {
                                for(int y = 0; y < n; y++) {
                                        int cnt = 0;
                                        for(auto& pr: house) {
                                                if(getDistance(x,y,pr.first,pr.second) < k) {
                                                        cnt++;
                                                }
                                        }
                                        if(cnt*m >= cost && cnt > answer) {
                                                answer = cnt;
                                        }
                                }
                        }
                }
                printf("#%d %d\n",test_case,answer);
        }
        return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
