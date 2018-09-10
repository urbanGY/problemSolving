#include <iostream>
using namespace std;

int main() {
	int E = 0, S = 0, M = 0;
	int input1, input2, input3;
	cin>>input1>>input2>>input3;
	for(int i = 1 ; i <= 7980 ; i++){
		E++;
		S++;
		M++;
		if(E == 16) E -= 15;
		if(S == 29) S -= 28;
		if(M == 20) M -= 19;
		if((E == input1)&&(S == input2)&&(M == input3)){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
