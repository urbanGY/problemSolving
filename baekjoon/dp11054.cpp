#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return a < b ? b : a; }

int main() {
	int n;
	cin >> n;
	vector<int> v(n,0);
	vector<int> dp_l(n,1);
	vector<int> dp_r(n,1);
	for(int i = 0 ; i < n ; i++) scanf("%d",&v[i]);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < i ; j++){
			if(v[j] < v[i]){
				dp_l[i] = max(dp_l[i],dp_l[j] + 1);
			}
		}
	}
	for(int i = n-1 ; i >= 0 ; i--){
		for(int j = n-1 ; j > i ; j--){
			if(v[j] < v[i]){
				dp_r[i] = max(dp_r[i],dp_r[j] + 1);
			}
		}
	}
	int maxVal = -1;
	for(int i = 0 ; i < n ; i++) {
		if(maxVal < dp_l[i] + dp_r[i]) maxVal = dp_l[i] + dp_r[i];
	}
	cout<<maxVal-1<<endl;
	return 0;
}
