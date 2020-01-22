#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = 0 , b = 1 , tmp;
    for(int i = 1 ; i <= n ; i++){
        tmp = (a%1234567) + (b%1234567);
        a = b;
        b = (tmp%1234567);
    }
    return a;
}
