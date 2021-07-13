#include <iostream>
#include <vector>
using namespace std;

int getPtr(vector<int>& C, int here) {
	if(here > C.back()) return C.size();
	int start = 0, end = C.size()-1, result = 0;
	while(start < end) {
		int mid = (start + end) / 2;
		//result = mid;
		if(C[mid] > here) {
			end = mid;
		}else {
			start = mid+1;
		}
	}
	return end;
}

int main() {
	int n;
	scanf("%d\n",&n);
	vector<int> input(n,0);
	vector<int> C;
	for(int i = 0 ; i < n ; i++) scanf("%d",&input[i]);
	for(auto& elem : input) {
		if(C.empty()) {
			C.push_back(elem);
		}else {
			int ptr = getPtr(C,elem);
			if(ptr == C.size()) C.push_back(elem);
			else {
				C[ptr] = elem;
			}
		}
	}
	printf("%d\n",C.size());
}