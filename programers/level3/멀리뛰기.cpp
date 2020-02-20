#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long a = 1;
    long long b = 2;
    long long mod = 1234567;
    if(n == 1) return 1;
    if(n == 2) return 2;
    for(int i = 3 ; i <= n ; i++){
        long long tmp = (a+b)%mod;
        a = b;
        b = tmp;
    }
    return b%mod;
}
