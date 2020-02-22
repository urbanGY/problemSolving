#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a > b; }
int solution(vector<int> A, vector<int> B) {
    int answer = 0, b_index = 0;
    sort(A.begin() , A.end() , cmp);
    sort(B.begin() , B.end() , cmp);
    for(auto a : A){
        if(B[b_index] > a){
            b_index++;
            answer++;
        }
    }
    return answer;
}
큰거부터 비교해 계산하는 발상!
