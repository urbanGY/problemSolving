#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	vector<pair<int, int> > arr;
	int n;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++){
		int a, b;
		scanf("%d %d",&a,&b);
		arr.push_back(make_pair(a,b));
	}
	sort(arr.begin(),arr.end(),cmp);
	int now = 0, ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(now <= arr[i].first){
			ans++;
			now = arr[i].second;
		}
	}
	printf("%d",ans);
	return 0;
}
