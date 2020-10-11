#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, K, C;
vector<pair<int,int> > snake;
vector<pair<int,int> > apple;
queue<pair<int,char> > command;
pair<int,int> head;
int t = 0, nx = 0, ny = 1;

bool isOkay() {
	int x = head.first, y = head.second;
	if(x < 0 || y < 0 || x >= N || y >= N) return false;
	for(auto& body : snake) {
		if(x == body.first && y == body.second) return false;
	}
	return true;
}

bool isApple() {
	int x = head.first, y = head.second;
	for(auto& a : apple) {
		if(x == a.first && y == a.second) {
			a.first = -999;
			a.second = -999;
			return true;
		}
	}
	return false;
}

void move() {
	int size = snake.size() - 1;
	for(int i = size ; i >= 1 ; i--) {
		snake[i].first = snake[i-1].first;
		snake[i].second = snake[i-1].second;
	}
	if(!snake.empty()) {
		snake[0].first = head.first - nx;
		snake[0].second = head.second - ny;
	}
	// cout<<t<<" : "<<head.first<<","<<head.second<<"  ";
	// for(auto s : snake) {
	// 	cout<<s.first<<","<<s.second<<"  ";
	// }
	// cout<<endl;
}

void isTime() {
	if(command.empty()) return;
	int time = command.front().first;
	char direct = command.front().second;
	char before = nx == 0 ? 'H' : 'V';
	if(time == t) {
		command.pop();
		int tmp = nx;
		nx = ny;
		ny = tmp;
		if(before == 'H') {// 가로진행방향
			if(direct == 'L') nx *= -1;
		}
		if(before == 'V') {// 세로진행방향
			if(direct == 'D') ny *= -1;
		}
	}
}

int main() {
	scanf("%d %d",&N,&K);
	for(int i = 0 ; i < K ; i++){
		int x, y;
		scanf("%d %d",&x,&y);
		apple.push_back({x-1,y-1});
	}
	scanf("%d",&C);
	for(int i = 0 ; i < C ; i++) {
		int time;
		char direct;
		scanf("%d %c",&time,&direct);
		command.push({time,direct});
	}
	head = {0,0};
	while(true) {
		isTime();
		t++;
		head.first += nx;
		head.second += ny;
		//cout<<nx<<" , "<<ny<<endl;
		// cout<<t<<" : "<<head.first<<" , "<<head.second<<endl;
		if(isOkay()) {
			if(isApple()) {
				snake.push_back({0,0});
			}
			move();
		}else break;
	}
	printf("%d\n",t);
	return 0;
}
