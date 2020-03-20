#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long num = n;
    int answer = 0;
    while(num != 1){
        if(num%2 == 0) num /= 2;
        else {
            num *= 3;
            num += 1;
        }
        answer++;
        if(answer > 500) return -1;
    }
    return answer;
}
