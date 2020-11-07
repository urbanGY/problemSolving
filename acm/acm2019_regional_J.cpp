#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> dp(1000001);
	scanf("%d",&n);
	dp[3] = 0;
	dp[4] = 1;
	dp[5] = 2;
	for(int i = 6 ; i <= n ; i++) {
		int sub = i/2;
		if(i%2 == 1) sub += 1;
		dp[i] = dp[sub] + 2;
	}
	printf("%d\n",dp[n]);
	return 0;
}

// 6각형을 나누는 방법 잘 생각하고, 각 도형마다 내부에 그려지는 작은 도형이 있음을 생각한다.
// 내부의 작은 도형들을 건너는 최장 거리는 항상 내부 거리 + 2 임으로 dp로 관리해 이전 값을 가져와 갱신해준다.
