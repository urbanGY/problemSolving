#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N, K;
	vector<bool> check(100001,false);
	scanf("%d %d",&N,&K);
	{
		queue<pair<int,int> > q;
		q.push(make_pair(N,0));
		check[N] = true;
		while(!q.empty()){
			pair<int, int> pr = q.front();
			q.pop();
			if(pr.first == K) {
				cout<<pr.second<<endl;
				return 0;
			}
			if(pr.first-1 >= 0 && !check[pr.first-1]){
                q.push(make_pair(pr.first-1,pr.second+1));
                check[pr.first-1] = true;
            }

			if(pr.first+1 <= 100000 && !check[pr.first+1]){
                q.push(make_pair(pr.first+1,pr.second+1));
                check[pr.first+1] = true;
            }

			if(pr.first*2 <= 100000 && !check[pr.first*2]){
                q.push(make_pair(pr.first*2,pr.second+1));
                check[pr.first*2] = true;
            }

		}
	}
	return 0;
}
