#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, block = 0, W = 2*w+1, start = 1;
    for(const auto& station : stations){
        if(start > station-w){ // 이 부분이 중요 ㅎㅎ
            start = station+w+1;
        }else {
            block = station-w-start;
            answer += (block/W);
            if(block%W != 0) answer += 1;
            start = station+w+1;
        }
    }
    if(start <= n){
        block = n - start + 1;
        answer += (block/W);
        if(block%W != 0) answer += 1;
    }

    return answer;
}
