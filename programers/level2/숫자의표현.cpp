#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    for(int i = 1 ; i <= n ; i++){
        v.push_back(i);
    }
    for(int i = 0 ; i < n ; i++){
        int tmp = 0;
        for(int j = i ; j < n ; j++){
            tmp += v.at(j);
            if(tmp > n) break;
            else if(tmp == n) {
                answer++;
                break;
            }
        }
    }

    return answer;
}
