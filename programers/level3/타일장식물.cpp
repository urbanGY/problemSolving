#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long a = 4, b = 6;
    if(N == 1) return a;
    if(N == 2) return b;
    for(int i = 3 ; i <= N ; i++){
        answer = a + b;
        a = b;
        b = answer;
    }
    return answer;
}
