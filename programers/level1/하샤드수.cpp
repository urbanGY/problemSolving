#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int tmp = x, sum = 0;
    vector<int> v;
    while(tmp > 0){
        int mod = tmp%10;
        v.push_back(mod);
        tmp /= 10;
    }
    for(auto& i : v) sum += i;
    if(x%sum == 0) return true;
    else return false;
}
