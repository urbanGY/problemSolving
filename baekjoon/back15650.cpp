#include <iostream>
#include <vector>
using namespace std;

void find(int N, int M, int start, vector<int> check){
	if(check.size() == M){
		for(auto val : check){
			printf("%d ",val);
		}
		printf("\n");
	}

	for(int i = start ; i <= N ; i++){
		if(check.empty()){
			check.push_back(i);
			find(N,M,i+1,check);
			check.pop_back();
		}else {
			if(check.back() < i){
				check.push_back(i);
				find(N,M,i+1,check);
				check.pop_back();
			}
		}
	}

}

int main() {
	int N, M;
	scanf("%d %d",&N, &M);
	find(N,M,1,vector<int>());

	return 0;
}
