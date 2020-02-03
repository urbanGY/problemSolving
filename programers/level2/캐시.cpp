#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return 5*cities.size();
    queue<string> q;
    map<string, bool> m;
    int answer = 0;
    for(int i = 0 ; i < cities.size() ; i++){
        string refine_city = cities[i];
        transform(refine_city.begin(), refine_city.end(), refine_city.begin(), (int(*)(int))tolower);
        if(q.empty()) {
            q.push(refine_city);
            m[refine_city] = true;
            answer += 5;
            continue;
        }
        if(m[refine_city]){
            answer++;
            string tmp;
            int n = 0, end = q.size();
            while(n < end){
                tmp = q.front();
                q.pop();
                if(tmp != refine_city) q.push(tmp);
                n++;
            }
            q.push(refine_city);
        }else {
            answer += 5;
            q.push(refine_city);
            m[refine_city] = true;
            if(q.size() > cacheSize){
                m[q.front()] = false;
                q.pop();
            }
        }

    }
    return answer;
}
