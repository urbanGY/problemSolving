#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b){ return a < b ? b : a ; }

int main() {
	vector<int> dp(100001, 0);
	int N, M, tmp, a, b;
	scanf("%d %d",&N,&M);
	for(int i = 1 ; i <= N ; i++){
		scanf("%d",&tmp);
		dp[i] = dp[i-1] + tmp;
	}
	for(int i = 0 ; i < M ; i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[b]-dp[a-1]);
	}
	return 0;
}

