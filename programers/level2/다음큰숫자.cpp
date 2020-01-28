#include <string>
#include <vector>

using namespace std;

int getNum(int n){
    int cnt = 0;
    while(n){
        int tmp = n%2;
        if(tmp) cnt++;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cnt = getNum(n);
    n++;
    while(true){
        if(cnt == getNum(n)) return n;
        n++;
    }
    return answer;
}
