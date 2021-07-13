#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<bool> result;

void find(int pick, int start, vector<int>& numbers, int cnt) {
    if(cnt == 2) {
        result[pick] = true;
        return;
    }

    for(int i = start ; i < numbers.size() ; i++) {
        find(pick+numbers[i],i+1,numbers,cnt+1);
    }
}

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    result = vector<bool>(210,false);
    find(0,0,numbers,0);
    for(int i = 0 ; i < 210 ; i++) {
        if(result[i]) {
            answer.push_back(i);
        }
    }
    return answer;
}
