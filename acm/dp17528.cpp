#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	int n;
	vector<pair<int,int> > v(251,make_pair(0,0));
	vector<vector<int> > dp(251,vector<int>(250*250+1,987654321));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    dp[0][v[0].first] = 0;
    dp[0][0] = v[0].second;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 250*250+1; j++){
            dp[i][j + v[i].first] = min(dp[i][j + v[i].first], dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + v[i].second);
        }
    }
    int ans = 987654321;
    for(int i = 0; i < 62501; i++)ans = min(ans, max(i, dp[n - 1][i]));
    printf("%d", ans);
}
