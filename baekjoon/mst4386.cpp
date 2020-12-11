#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <math.h>
using namespace std;
float aabs(float a) {
	return a > 0.0 ? a : -a;
}

struct node {
	int num;
	float x;
	float y;
	node(int num, float x, float y)
	:num(num),x(x),y(y) {}
};

struct cmp {
	bool operator()(pair<int,float> a, pair<int,float> b) {
		return a.second > b.second;		
	}
};

vector<node> pos;
vector<bool> isConnected;

float getDist(node a, node b) {
	float w = aabs(a.x - b.x);
	float h = aabs(a.y - b.y);
	return sqrt((w*w)+(h*h));
}

int main() {
	int n;
	float answer = 0.0;
	scanf("%d",&n);
	isConnected = vector<bool>(n,false);
	priority_queue<pair<int,float>, vector<pair<int,float> >, cmp> pq;
	for(int i = 0 ; i < n ; i++) {
		float a, b;
		scanf("%f %f",&a,&b);
		pos.push_back(node(i,a,b));
	}
	pq.push({0,0.0});
	while(!pq.empty()) {
		int cur = pq.top().first;
		float cost = pq.top().second;
		pq.pop();
		if(isConnected[cur]) continue;
		isConnected[cur] = true;
		answer += cost;
		for(int i = 0 ; i < n ; i++) {
			if(!isConnected[i]) {
				pq.push({i,getDist(pos[cur],pos[i])});
			}
		}
	}
	printf("%.2f\n",answer);
	return 0;
}