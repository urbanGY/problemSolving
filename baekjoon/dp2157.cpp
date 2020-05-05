#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int max(int a, int b) { return a < b ? b : a; }
int main() {
	map<int, int>::iterator itr;
	map<int, int> ans;
	int N, M, K;
	scanf("%d %d %d",&N,&M,&K);
	vector<vector<int> > maps(N+1,vector<int>(N+1,0));
	vector<map<int, int> > dp(N+1,map<int, int>());
	dp[1][1] = 0;

	for(int i = 0 ; i < K ; i++){
		int from, to, val;
		scanf("%d %d %d",&from, &to, &val);
		if(maps[from][to] < val){
			maps[from][to] = val;
		}
	}
	for(int i = 1 ; i <= N ; i++){
		for(int j = i+1 ; j <= N ; j++){
			if(maps[i][j] != 0 ){
				for(itr = dp[i].begin() ; itr != dp[i].end() ; itr++){
					dp[j][itr->first+1] = max(dp[j][itr->first+1], dp[i][itr->first] + maps[i][j]);
				}
			}
		}
	}

	map<int, int> tmp = dp[N];
	int answer = 0;
	for(itr = tmp.begin() ; itr != tmp.end() ; itr++){
		if(itr->second > answer && itr->first <= M) answer = itr->second;
	}
	printf("%d",answer);
	return 0;
}
