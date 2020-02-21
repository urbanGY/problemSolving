#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void find(int num, int start, int end){
    if(num >= 1){
        find(num-1, start, 6-start-end);
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        answer.push_back(tmp);
        find(num-1, 6-start-end, end);
    }
}
vector<vector<int>> solution(int n) {
    find(n,1,3);
    return answer;
}
