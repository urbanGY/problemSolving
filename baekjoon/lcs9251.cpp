#include <iostream>
#include <string>
#include <vector>
using namespace std;

int max(int a, int b){ return a < b ? b : a ; }

int main() {
	string a, b;
    cin>> a >>b;
    int a_l = a.size(), b_l = b.size();
    vector<vector<int> > v(a.size()+1,vector<int> (b.size()+1, 0));
    for(int i = 1 ; i <= a_l ; i++){
    	for(int j = 1 ; j <= b_l ; j++){
    		if(a.at(i-1) == b.at(j-1)){
    			v[i][j] = v[i-1][j-1] + 1;
    		}else {
    			v[i][j] = max(v[i-1][j],v[i][j-1]);
    		}
    	}
    }
    cout<<v[a_l][b_l]<<endl;
	return 0;
}