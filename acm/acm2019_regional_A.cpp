#include <iostream>
#include <vector>
using namespace std;
int aabs(int a) { return a > 0 ? a : -a; }
int main() {
	int input;
	vector<int> A(1001,0);
	A[0] = 1;
	A[1] = 1;
	for(int i = 2 ; i <= 1000 ; i++) {
		vector<bool> check(1001,true);
		int target = i/2;
		for(int k = 1 ; k <= target ; k++) {
			int index = 2*(A[i-k]) - A[i-(2*k)];
			if(index <= 0) { // 음수가 되는 경우 고려해서
				//cout<<2*(A[i-k])<<" , "<<A[i-(2*k)]<<endl;
				continue;
			}
			check[index] = false;
		}
		for(int j = 1 ; j < 1001 ; j++) {
			if(check[j]) {
				A[i] = j;
				break;
			}
		}
		//cout<<"A["<<i<<"] : "<<A[i]<<endl;
	}
	scanf("%d",&input);
	printf("%d\n",A[input]);
	return 0;
}
