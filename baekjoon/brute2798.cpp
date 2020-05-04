#include <iostream>
#include <vector>
using namespace std;
int answer = -1;
int N, M;
void find(vector<int>& v, int cnt, int cur, int start){
	if(cnt == 3){
		if(cur <= M && cur > answer) answer = cur;
		return;
	}
	for(int i = start ; i < N ; i++){
		find(v,cnt+1,cur+v[i],i+1);
	}
}

int main() {
	scanf("%d %d",&N,&M);
	vector<int> v(N,0);
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&v[i]);
	}
  find(v,0,0,0);
	printf("%d",answer);

	return 0;
}
