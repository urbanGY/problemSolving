#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<int> month{31,29,31,30,31,30,31,31,30,31,30,31};
    vector<string> dayofweek{"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int day = 0;
    for(int i = 0 ; i < a-1 ; i++){
        day += month[i];
    }
    day += b;
    answer = dayofweek[day%7];
    return answer;
}
