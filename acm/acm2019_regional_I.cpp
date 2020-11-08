#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

int main() {
	int n;
	ll answer = 0;
	scanf("%d",&n);
	vector<pair<int,int> > v(n,{0,0});
	for(int i = 0 ; i < n ; i++) {
		int s, l;
		scanf("%d %d",&v[i].first,&v[i].second);
	}
	sort(v.begin(), v.end(), cmp);
	ll left = 1, right = 2000000000;
	while(left <= right) {
		ll mid = (left + right) / 2;
		//cout<<left<<","<<right<<" - "<<mid<<endl;
		ll knot = v[0].first;
		int flag = 0;
		for(auto& elem : v) {
			if(knot >= elem.first && knot <= elem.first + elem.second) {
				knot += mid;
			}else if(knot < elem.first) {
				knot = elem.first + mid;
			}else {
				flag = 1;
				break;
			}
		}
		if(flag == 0) {
			if(mid > answer) answer = mid;
			left = mid+1;
		}else if(flag == 1) {
			right = mid-1;
		}
	}
	printf("%lld\n",answer);
	return 0;
}
