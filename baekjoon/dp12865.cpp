#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int main() {
	int N, K;
	scanf("%d %d",&N,&K);
	vector<vector<int> > dp(N+1,vector<int>(K+1,0));
	vector<int> w(N,0);
	vector<int> v(N,0);
	int answer = -1;
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&w[i],&v[i]);
	}
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= K ; j++){
			if(w[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j-w[i-1]]);
			}else {
				dp[i][j] = dp[i-1][j];
			}
			answer = max(answer, dp[i][j]);
		}
	}
	printf("%d",answer);
	return 0;
}