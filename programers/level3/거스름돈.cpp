#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b) { return a < b; }

int solution(int n, vector<int> money) {
    int answer = 0;
    int mod = 1000000007;
    sort(money.begin(), money.end(), cmp);
    vector<int> dp(n+1,1);
    for(int j = 1 ; j <= n ; j++){
        if(j%money[0] == 0) dp[j] = 1;
        else dp[j] = 0;
    }

    for(int i = 1 ; i < money.size() ; i++){
        for(int j = money[i] ; j <= n ; j++){
            dp[j] = (dp[j] + dp[j-money[i]])%mod;
        }
    }
    answer = dp[n];
    return answer;
}
