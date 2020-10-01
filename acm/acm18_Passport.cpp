#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> c;
int main() {
	scanf("%d %d",&n,&k);
	c = vector<int>(k,0);
	for(int i = 0 ; i < n ; i++) {
		bool flag = true;
		int input;
		scanf("%d",&input);
		for(int j = 0 ; j < k ; j++) {
			if(c[j] < input) {
				c[j] = input;
				flag = false;
				break;
			}
		}
		if(flag) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}
