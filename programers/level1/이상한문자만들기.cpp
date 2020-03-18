#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int i = 0;
    for(auto& c : s){
        if(c == ' '){
            i = 0;
            continue;
        }

        if(i%2 == 0){
            if(c >= 'a' && c <= 'z') c -= 32;
        }else {
            if(c >= 'A' && c <= 'Z') c += 32;
        }
        i++;
    }
    return s;
}
