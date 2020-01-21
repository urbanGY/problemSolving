#include <string>
#include <vector>
#include <utility>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int end = -1;
    pair<char, int> pos = make_pair('0',0);
    for(int i = k ; i < number.size() ; i++){
        pos.first = number[i];
        pos.second = i;
        for(int j = i-1 ; j > end ; j--){
            if(pos.first <= number[j]){
                pos.first = number[j];
                pos.second = j;
            }
        }
        answer += pos.first;
        end = pos.second;
    }
    return answer;
}
