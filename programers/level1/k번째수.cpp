#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) { return a < b; }
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto & command : commands){
        int i = command[0], j = command[1], k = command[2];
        vector<int> tmp;
        for(int index = i-1 ; index < j ; index++){
            tmp.push_back(array[index]);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        answer.push_back(tmp[k-1]);
    }
    return answer;
}
