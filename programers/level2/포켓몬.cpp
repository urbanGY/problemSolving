#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
    int len = nums.size();
    int cnt = 0;
    vector<bool> type(200002);
    for(const auto& n : nums){
        type[n] = true;
    }
    for(const auto& c : type){
        if(c) cnt++;
    }
    len /= 2;
	return len < cnt ? len : cnt;
}
