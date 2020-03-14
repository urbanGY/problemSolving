#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int index = 0;
    for(auto s : seoul){
        if(s == "Kim") break;
        index++;
    }
    string answer = "김서방은 "+to_string(index)+"에 있다";
    return answer;
}
