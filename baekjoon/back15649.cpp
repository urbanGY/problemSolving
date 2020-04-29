#include <iostream>
#include <string>
#include <vector>
using namespace std;
void find(string s, int N, int M, vector<bool>& check){
	if(s.size() == M){
		for(auto c : s) printf("%c ",c);
		printf("\n");
	}
	for(int i = 1 ; i <= N ; i++){
		if(!check[i]){
			check[i] = true;
			find(s+to_string(i), N, M, check);
			check[i] = false;
		}
	}
}

int main() {
	int N, M;
	string s = "";
	scanf("%d %d",&N,&M);
	vector<bool> check(M+1, false);
	find(s,N,M,check);
	return 0;
}
