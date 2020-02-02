#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = 1, b = 2;
    for(int i = 3 ; i <= n ; i++){
        int tmp = (a+b)%1000000007;
        a = b;
        b = tmp;
    }
    return b;
}
