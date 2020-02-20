#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b) { return a > b; }
long long solution(int n, vector<int> works) {
    long long N = n;
    long long answer = 0;
    long long tmp = 0;
    sort(works.begin(), works.end() , cmp);

    for(int i = 0 ; i < works.size() ; i++){
        tmp += (long long)works[i];
    }
    if(tmp  <  N) return 0;

    tmp = works[0];
    int i = 0;
    while(true){
        if(N == 0) break;
        if(works[i] < tmp){
            tmp = works[0];
            i = 0;
        }else {
            works[i] -= 1;
            N--;
            i++;
        }
    }
    for(const auto& c : works)
        answer += (long long)c*(long long)c;
    return answer;
}
