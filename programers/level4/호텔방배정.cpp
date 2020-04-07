#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> m;

long long find(long long n) {
    if(!m[n]) return n;
    return m[n] = find(m[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for(auto val : room_number){
        if(!m[val]){
            answer.push_back(val);
            m[val] = find(val+1);
        }else {
            long long tmp = find(val);
            answer.push_back(tmp);
            m[tmp] = find(tmp+1);
        }
    }
    return answer;
}
