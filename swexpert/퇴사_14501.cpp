#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main() {
	int n;
	scanf("%d",&n);
	vector<int> t(n+1);
	vector<int> p(n+1);
	vector<int> dp(n+1,0);
	for(int i = 1 ; i <= n ; i++) scanf("%d %d",&t[i],&p[i]);
	for(int i = 1 ; i <= n ; i++) {
		int time = t[i]-1, pay = p[i];
		if(i+time <= n) {
			dp[i+time] = max(dp[i+time],dp[i-1] + pay); // t일 후에 받기로 미리 계산된 값과, 현재 상담을 할 경우 받을 값( dp[i-1] 이전에 받은 상담 + 현재 상담의 보상) 을 비교해 큰 것으로 갱신
		}
		if(dp[i] < dp[i-1]) dp[i] = dp[i-1]; // t가 0 즉, 하루짜리 강의가 아니라면 현재의 dp에 아무 값도 갱신 못할 수 있는데 아무 일도 하지 않아도 이전 dp 값만큼의 보상은 받을 수 있기 때문에 이전 값 중 큰 값을 택한다.
	}
	printf("%d\n",dp[n]);
	return 0;
}
