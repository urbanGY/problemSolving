#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	scanf("%d",&N);
	vector<int> w;
	vector<int> h;
	vector<int> answer(N,0);
	for(int i = 0 ; i < N ; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		w.push_back(x);
		h.push_back(y);
	}
	for(int i = 0 ; i < N ; i++){
		int rank = 1;
		for(int j = 0 ; j < N ; j++){
			if(w[i] < w[j] && h[i] < h[j]){
				rank++;
			}
		}
		printf("%d ",rank);
	}
	return 0;
}
