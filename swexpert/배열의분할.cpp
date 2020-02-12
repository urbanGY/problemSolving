#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, i, input;
        int up = 1, down =1,answer = 1;
        cin>>n;
        vector<int> v;
        cin >> input;
        v.push_back(input);
        for(i = 1 ; i < n ; i++){
            cin >> input;
            v.push_back(input);
            if(input == v[i-1]){
                up++;
                down++;
            }else if(input < v[i-1]){
				if(up > down){
                    answer++;
                    up = 1;
                    down = 1;
                }else
                down++;

            }else {
				if(down > up) {
                    answer++;
                    down = 1;
                    up = 1;
                }else
                up++;

            }
        }
        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
