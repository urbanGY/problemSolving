#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}
int solution(vector<vector<int>> routes) {
    int answer = 1, minimum;
    sort(routes.begin(), routes.end(), cmp);
    minimum = routes[0][1];
    for(int i = 1 ; i < routes.size() ; i++){
        if(routes[i][0] <= minimum){ //같은 시점에 진입, 탈출하는 경우 생각해서 <= 로 바꾸니 성공
            if(minimum > routes[i][1]) minimum = routes[i][1];
        }else {
            answer++;
            minimum = routes[i][1];
        }
    }
    return answer;
}
