#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){ return a < b; }

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end(), cmp);
    long long max = (long long)times.back()*n;
    long long min = 1;
    long long answer = 0;
    while(min <= max){
        long long mid = (min + max)/2;
        long long sum = 0;
        for(auto & time : times)
            sum += (mid/time);
        if(sum < n){
            min = mid+1;
        }else {
            answer = mid;
            max = mid-1;
        }
    }
    return answer;
}
