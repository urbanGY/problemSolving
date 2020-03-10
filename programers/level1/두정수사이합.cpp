#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    long long answer = 0;
    for(int i = a ; i <= b ; i++)
        answer += i;
    return answer;
}
