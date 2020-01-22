#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    bool flag = false;
    priority_queue< int, vector<int>, greater<int> > pq;
    for(const auto& elem : scoville)
        pq.push(elem);
    while(true){
        int a = pq.top();
        if(a >= K){
            flag = true;
            break;
        }
        if(pq.size() == 1) break;
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b*2);
        answer++;
    }
    return flag?answer:-1;
}
