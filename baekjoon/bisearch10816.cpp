#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int main() {
	map<int,bool> m;
	int N,M, dummy = 10000000;
	scanf("%d",&N);
	vector<int> arr(20000020,0);
	for(int i = 0 ; i < N ; i++) {
		int input;
		scanf("%d",&input);
		arr[input+dummy]++;
		m[input+dummy] = true;
	}
	vector<pair<int, int> > v;
	for(int i = 0 ; i < 20000020 ; i++) {
		if(arr[i] > 0) {
			v.push_back(make_pair(i,arr[i]));
		}
	}
	scanf("%d",&M);
	for(int i = 0 ; i < M ; i++) {
		bool flag = true;
		int input, start = 0, end = v.size()-1;
		scanf("%d",&input);
		input += dummy;
		while(start <= end) { //여기 <로 하면 안될 때가 있음
			int mid = (start + end) / 2;
			if(v[mid].first == input) {
				flag = false;
				printf("%d ",v[mid].second);
				break;
			}else if(input < v[mid].first) {
				end = mid-1;
			}else {
				start = mid+1;
			}
		}
		if(flag) printf("0 ");
	}
	return 0;
}
