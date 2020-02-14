#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a < b;}
int solution(vector<int> weight) {
    int answer = 0;
    sort(weight.begin(), weight.end(), cmp);
    answer += weight[0];
    for(int i = 1 ; i < weight.size() ; i++){
        if(weight[i] > answer+1){
            //여기서 뭔가 answer+1을 옮기는 코드를 쓰면 이 for문이 돌지 않는 경우를 고려할 수 없기 때문에 틀리게 된다.
            break;
        }else {
            answer += weight[i];
        }
    }
    return answer+1;
}
