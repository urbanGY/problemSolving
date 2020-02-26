#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> people;
    long long fac = 1;
    long long N = n;
    for(long long i = 1 ; i <= n ; i++){
        fac *= i;
        people.push_back(i);
    }


    while(N > 0){
        fac /= N;
        N--;
        int index = (int)(k/fac);
        int remain = (int)(k%fac);
        if(remain == 0){
            index--;

            answer.push_back(people[index]);
            people.erase(people.begin()+index);
            while(!people.empty()){ //나머지가 0일 경우에는 이 뒤에 남은 경우의 수가 역수로 들어오면 되기 때문에 아래와 같이 처리하고 바로 리턴해준다
                int per = people.back(); // ex) 1,2,3 / k = 4 일때, k/fac = 2 임으로 나머지가 0이기 때문에 index를 하나 줄인 것을 택하고 남은 것은 역수로 집어넣는경우가 된다. 2,3,1
                people.pop_back();
                answer.push_back(per);
            }
            return answer;
        }
        answer.push_back(people[index]);
        people.erase(people.begin()+index);
        k %= fac;
    }
    return people;
}
