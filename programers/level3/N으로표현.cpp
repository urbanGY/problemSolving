#include <string>
#include <vector>

using namespace std;
int answer;

void find(int result, int count, int n, int number){
    if(count > 8) return;
    if(result == number) {
        if(answer < 0 || answer > count) answer = count;
        return;
    }
    int nn = 0;
    for(int i = 0 ; i < 8 ; i++){
        nn = nn*10 + n;
        find(result + nn, count + 1 + i, n, number );
        find(result - nn, count + 1 + i, n, number );
        find(result * nn, count + 1 + i, n, number );
        find(result / nn, count + 1 + i, n, number );
    }
}

int solution(int N, int number) {
    answer = -1;
    find(0, 0, N, number);
    return answer;
}
