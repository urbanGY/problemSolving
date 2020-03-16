#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    if(n == 2) return 1;
    vector<bool> v(1000001,false);
    for(int i = 2 ; i <= n ; i++){
        if(v[i] == false){
            answer++;
            for(int j = i+i ; j <= n ; j += i){
                v[j] = true;
            }
        }
    }
    return answer;
}
