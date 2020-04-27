#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d",& N);
    vector<int> v(10001,0);
    for(int i = 0 ; i < N ; i++){
        int input;
        scanf("%d",&input);
        v[input] += 1;
    }
    for(int i = 1 ; i <= 10000 ; i++){
    	while(v[i] > 0){
    		printf("%d\n",i);
    		v[i]--;
    	}
    }
    return 0;
}
