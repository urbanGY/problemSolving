#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
bool cmp(int &a, int &b) { return a<b; }
long long calculate(vector<int>& budgets, int limit){
    long long sum = 0;
    for(int i = 0 ; i < budgets.size() ; i++){
        if(budgets[i] > limit){
            sum += (limit*(budgets.size()-i));
            break;
        } else sum += budgets[i];
    }
    return sum;
}
int solution(vector<int> budgets, int M) {
    int answer = 0;
    long long sum = 0;
    sort(budgets.begin(), budgets.end(), cmp);
    for(auto & budget : budgets)
        sum += budget;
    if(sum <= (long long)M) return budgets.back();
    int min = 0, max = 100000, tmp = 0; //tmp 와 mid가 같은 것을 판단해서 답을 찾자.

    while(true){
        int mid = (max+min)/2;
        long long result = calculate(budgets,mid);
        if(mid == tmp) return mid;
        if(result > (long long)M){
            max = mid;
        }else {
            min = mid;
        }
        tmp = mid;
    }
    return answer;
}
