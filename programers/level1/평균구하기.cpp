#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto& a : arr){
        answer += (double)a;
    }
    return answer/arr.size();
}
