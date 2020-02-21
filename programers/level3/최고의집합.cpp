#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a < b; }
vector<int> solution(int n, int s) {
    vector<int> answer(n,0);
    int tmp;
    int i = 0;
    if(n > s) {
        vector<int> wrong(1,-1);
        return wrong;
    }
    while(n > 0){
        tmp = s/n;
        answer[i] = tmp;
        n -=1;
        s -= tmp;
        i++;
    }
    return answer;
}
