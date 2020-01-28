#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<int> before;
    vector<int> after;
    bool flag = true;
    for(const auto& r : land){
        if(flag){
            for(int i = 0 ; i < 4 ; i++){
                before.push_back(r[i]);
                after.push_back(0);
            }

            flag = false;
            continue;
        }
        for(int i = 0 ; i < 4 ; i++){
            int max = 0;
            for(int j = 0 ; j < 4 ; j++){
                if(i == j) continue;
                if(before[j] > max) max = before[j];
            }
            after[i] = r[i] + max;
        }
        for(int i = 0 ; i < 4 ; i++)
            before[i] = after[i];
    }

    for(const auto& c : before){
        if(c > answer) answer = c;
    }

    return answer;
}
