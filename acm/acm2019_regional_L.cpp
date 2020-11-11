#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

struct Node {
	int start;
	int end;
	int val;
	Node(int start, int end, int val)
	:start(start), end(end), val(val) {}
};

bool cmp(Node a, Node b) {
	return a.start < b.start;
}

ll getMax(ll a, ll b) { return a > b ? a : b; }

int main() {
	ll answer = -1;
	int n,m;
	scanf("%d %d",&m,&n);
	vector<int> type(m+1);
	vector<Node> v;
	vector<ll> dp(15001);
	for(int i = 1 ; i <= m ; i++) {
		scanf("%d",&type[i]);
	}
	for(int i = 0 ; i < n ; i++) {
		int s, e, t;
		scanf("%d %d %d",&s,&e,&t);
		v.push_back(Node(s,e,type[t]));
	}
	sort(v.begin(), v.end(), cmp);
	int cur = 0;
	for(int i = 0 ; i < 15000 ; i++) {
		while(cur < n && i == v[cur].start) {
			int start = v[cur].start, end = v[cur].end, val = v[cur].val;
			dp[end] = getMax(dp[end],dp[start] + (val * (end - start))); // 도착지에 현재까지 계산된 dp 값 + 새롭게 추가된 값 을 갱시하는데 이때 기존 값보다 클 경우에만 갱신한다.
			if(dp[end] > answer) answer = dp[end];
			cur++;
		}
		dp[i+1] = getMax(dp[i],dp[i+1]); // 다음 값이 뭐든 현재 값 보다 작은 경우 현재 값을 취하는 것이 유리하기 대문에 갱신시켜준다. 이는 중간에 처리 값이 없는 영역도 값을 갱신시켜 정답을 누적해 나가게 된다.
		if(dp[i+1] > answer) answer = dp[i+1];
		//if(i < 12) cout<<dp[i]<<" ";
	}
	printf("%lld\n",dp[15000]);
	return 0;
}


//14501번하고 유사한 문제.
