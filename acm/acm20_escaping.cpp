#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int aabs(int a) { return a > 0 ? a : -a; }
int main() {
	bool answer = true;
	int N, sx,sy;
	scanf("%d",&N);
	vector<pair<int,int> > v;
	for(int i = 0 ; i < N ; i++) {
		int x, y;
		scanf("%d %d",&x,&y);
		v.push_back({x,y});
	}
	scanf("%d %d",&sx,&sy);
	vector<bool> check(4,false);
	for(int i = 0 ; i < N ; i++) {
		int x = v[i].first, y = v[i].second;
		if(y > sy && aabs(sx - x) <= aabs(sy - y)) check[0] = true;
		if(y < sy && aabs(sx - x) <= aabs(sy - y)) check[1] = true;
		if(x > sx && aabs(sx - x) >= aabs(sy - y)) check[2] = true;
		if(x < sx && aabs(sx - x) >= aabs(sy - y)) check[3] = true;
		if(check[0] && check[1] && check[2] && check[3]) {
			answer = false;
			break;
		}
	}
	printf("%s\n",answer?"YES":"NO");
	return 0;
}
