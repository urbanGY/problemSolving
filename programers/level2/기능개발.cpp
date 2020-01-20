#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int length = progresses.size();
    vector<int> tmp;
    vector<int> answer;
    int cur, cnt;
    for(int i = 0 ; i < length ; i++){
        int n = 100 - progresses[i];
        int val = (int)(ceil((float)n/speeds[i]));
        tmp.push_back(val);
    }
    cur = tmp[0];
    cnt = 0;
    for(const auto& elem : tmp){
        if(cur < elem){
            answer.push_back(cnt);
            cnt = 0;
            cur = elem;
        }
        cnt++;
    }
    answer.push_back(cnt);
    return answer;
}
