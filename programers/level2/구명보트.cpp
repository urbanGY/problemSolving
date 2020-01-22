#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b){
    return a < b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    int cnt = 0;
    int start = 0 , end = people.size() -1;
    sort(people.begin(), people.end(), cmp);
    while(start < end){
        while(start < end){
            if(people[start]+people[end] <= limit){
                end--;
                cnt++;
                break;
            }
            end--;
        }
        start++;
    }
    return people.size() - cnt;
}
