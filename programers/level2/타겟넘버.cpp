#include <string>
#include <vector>

using namespace std;
int cnt = 0;
int length = 0;
void find(vector<int> & numbers, int cur, int target, int i){
    if(length == i){
        if(cur == target) cnt++;
        return;
    }
    find(numbers, cur+numbers[i], target, i+1);
    find(numbers, cur-numbers[i], target, i+1);
}

int solution(vector<int> numbers, int target) {
    length = numbers.size();
    find(numbers, 0, target, 0);
    return cnt;
}
