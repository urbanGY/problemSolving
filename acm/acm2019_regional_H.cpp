#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
	if(a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

ll eval(ll p1, ll p2, ll c1, ll c2) {
	return p1*c1 - p2*c2;
}

ll aabs(ll a) { return a > 0 ? a : -a; }

int main() {
	int n1,n2,c1,c2;
	scanf("%d",&n1);
	vector<pair<ll,ll> > v1(n1,{0,0});
	for(int i = 0 ; i < n1 ; i++) {
		scanf("%lld %lld",&v1[i].first,&v1[i].second);
	}
	sort(v1.begin(), v1.end(), cmp);
	scanf("%d",&n2);
	vector<pair<ll,ll> > v2(n2,{0,0});
	for(int i = 0 ; i < n2 ; i++) {
		scanf("%lld %lld",&v2[i].first,&v2[i].second);
	}
	sort(v2.begin(), v2.end(), cmp);
	scanf("%d %d",&c1,&c2);
	ll answer = c1;
	for(int i = 0 ; i < n1 ; i++) { // 시작지점
		for(int j = n1 - 1 ; j > i ; j--) {
			ll p1 = j+1-i , p2 = 0;
			ll x = v1[i].first, y = v1[i].second;
			ll w = aabs(v1[i].first - v1[j].first), h = aabs(v1[i].second - v1[j].second);
			for(int k = 0 ; k < n2 ; k++) {
				ll cx = v2[k].first, cy = v2[k].second;
				if( ( cx >= x && cx <= x + w ) && ( cy >= y && cy <= y + h)) p2++;
			}
			ll tmp = eval(p1,p2,c1,c2);
			if(tmp > answer) answer = tmp;
		}
	}
	printf("%lld\n",answer);
	return 0;
}
