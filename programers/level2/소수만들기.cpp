#include <vector>
#include <iostream>
using namespace std;

int cnt = 0;
int len = 0;

bool is_prime(int n){
    for(int i = 2 ; i < n ; i++){
        if(n%i == 0) return false;
    }
    return true;
}

void find(vector<int>& nums, int n, int start, int target){
    if(n == 0){
        if(is_prime(target)) cnt++;
        return;
    }

    for(int i = start ; i < len ; i++){
        find(nums, n-1, i+1, target + nums[i]);
    }
}

int solution(vector<int> nums) {
    len = nums.size();
    find(nums,3,0,0);
    return cnt;
}
