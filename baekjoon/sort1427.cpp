#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(char a, char b){
	return a > b;
}
int main(){
    int N;
    scanf("%d",& N);
    string s = to_string(N);
    sort(s.begin(), s.end(), cmp);
    cout<<s<<endl;
    return 0;
}
