#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int,int> >, cmp> pq;
//first 돌 값, second 인덱스

int getDp(vector<int>& dp, int index, int k){
    int start = index-k, result;
    while(true){
        pair<int, int> pa = pq.top();
        if(pa.second+k < index) pq.pop();
        else {
            result = pa.first;
            break;
        }
    }
    return result;
}

int solution(vector<int> stones, int k) {
    int answer = 0, stone_size = stones.size();
    vector<int> dp(stone_size,0);
    for(int i = 0 ; i < k ; i++){
        dp[i] = stones[i];
        pq.push(make_pair(dp[i],i));
    }
    for(int i = k ; i < stone_size ; i++){
        dp[i] = getDp(dp,i,k);
        if(dp[i] > stones[i]) dp[i] = stones[i];
        pq.push(make_pair(dp[i],i));
    }
    for(int i = stone_size - k ; i < stone_size ; i++){
        if(dp[i] > answer) answer = dp[i];
    }
    return answer;
}
