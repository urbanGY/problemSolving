#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M, minVal = 987654321;
vector<string> board;
void find(int x, int y, char entry[]){
	int ans = 0, cnt = 0;
	for(int i = x ; i < x+8 ; i++){
		for(int j = y ; j < y+8 ; j++){
			if(board[i][j] != entry[cnt%2]){
				ans++;
			}
			cnt++;
		}
		cnt++;
	}
	if(ans < minVal) minVal = ans;
}

int main() {
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i < N ; i++){
		string s;
		cin>>s;
		board.push_back(s);
	}

	char entry_1[2] = {'W','B'};
	char entry_2[2] = {'B','W'};
	for(int i = 0 ; i <= N-8 ; i++){
		for(int j = 0 ; j <= M-8 ; j++){
			find(i,j,entry_1);
			find(i,j,entry_2);
		}
	}
	printf("%d",minVal);
	return 0;
}
