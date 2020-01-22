#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a < b;
}
int solution(vector<int> citations) {
    int answer = 0;
    int length = citations.size();
    sort(citations.begin(), citations.end(), cmp);
    for(int i = 1 ; i <= length ; i++){
        int j;
        for(j = 0 ; j < length ; j++)
            if(i <= citations[j]) break;
        int over = length-j;
        int under = j;
        if(i <= over && i >= under) answer = i;
    }
    // 0 1 3 5 6
    return answer;
}
