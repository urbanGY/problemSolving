#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) { return a > b ? a : b ; } 
int main() {
	int N, answer = -1;
	scanf("%d",&N);
	vector<int> dp(N+1,0);
	vector<int> t(N,0);
	vector<int> p(N,0);
	
	for(int i = 0 ; i < N ; i++){
		scanf("%d %d",&t[i],&p[i]);
	}
	
	for(int i = 0 ; i < N ; i++){
		if(i+t[i] < N+1){
			dp[i + t[i]] = max(dp[i]+p[i], dp[i + t[i]]);
			answer = max(answer, dp[i+t[i]]);
		}
		dp[i+1] = max(dp[i],dp[i+1]);
		answer = max(answer, dp[i+1]);
	}
	// for(int i = 0 ; i <= N ; i++) printf("%d ",dp[i]);
	printf("%d",answer);
	return 0;
}

