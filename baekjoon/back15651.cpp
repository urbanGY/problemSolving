#include <iostream>
#include <vector>
using namespace std;

void find(int N, int M, vector<int> check){
	if(check.size() == M){
		for(auto val : check){
			printf("%d ",val);
		}
		printf("\n");
		return;
	}

	for(int i = 1 ; i <= N ; i++){
		check.push_back(i);
		find(N,M,check);
		check.pop_back();
	}
}

int main() {
	int N, M;
	scanf("%d %d",&N, &M);
	find(N,M,vector<int>());

	return 0;
}
