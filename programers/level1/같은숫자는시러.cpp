#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int cur = -1;
    for(auto& ar : arr){
        if(cur != ar){
            cur = ar;
            answer.push_back(ar);
        }
    }

    return answer;
}
