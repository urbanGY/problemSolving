#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0, min;
    vector<int> dp_l(a.size());
    vector<int> dp_r(a.size());
    min = 1000000001;
    for(int i = 0 ; i < a.size() ; i++) {
        if(a[i] < min) min = a[i];
        dp_l[i] = min;
    }
    min = 1000000001;
    for(int i = a.size()-1 ; i >= 0 ; i--) {
        if(a[i] < min) min = a[i];
        dp_r[i] = min;
    }
    for(int i = 1 ; i < a.size()-1 ; i++) {
        if(dp_l[i-1] < a[i] && dp_r[i+1] < a[i]) answer++;
    }
    return a.size() - answer;
}

// 양 끝 쪽은 반드시 살릴 수 있음. 왜냐하면 자기 외의 모든 풍선을 큰거만 남기고 제거하고 마지막에 비교할 때 작든 크든 터트리면 되기 때문이다.
// 중간에 있는 풍선의 경우 자기 좌우 양쪽 모두 작은 풍선이 있다면 살아남을 수 없다. 작은 풍선을 터트릴 기회는 한번뿐임으로.
// 즉 가운데 풍선 기준으로 좌우 모두 나보다 작은 풍선이 있는 경우 반드시 터지는 풍선이기에 미리 좌우 작은 풍선값들을 구하고 카운트 하는 방식으로 구현.
