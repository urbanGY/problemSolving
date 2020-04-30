#include <iostream>
#include <vector>
using namespace std;
int maxVal = -987654321;
int minVal = 987654321;

int getVal(char op, int a, int b){
  int result = 0;
  switch (op) {
    case '+': result = a+b; break;
    case '-': result = a-b; break;
    case '*': result = a*b; break;
    case '/': result = a/b; break;
  }
  return result;
}

void find(vector<int>& v, vector<char>& op, vector<bool> check, int val, int cnt){
  if(cnt == check.size()){
    if(val > maxVal) maxVal = val;
    if(val < minVal) minVal = val;
    return;
  }

  for(int i = 0 ; i < check.size() ; i++){
    if(!check[i]){
      check[i] = true;
      int tmp = getVal(op[i],val,v[cnt+1]);
      find(v,op,check,tmp,cnt+1);
      check[i] = false;
    }
  }
}

int main() {
	int N;
	cin >> N;
  vector<int> oper(4,0);

	vector<int> v(N,0);
	vector<char> op;
	for(int i = 0 ; i < N ; i++)
		cin >> v[i];

	for(int i = 0 ; i < 4 ; i++)
		cin >> oper[i];
	for(int i = 0 ; i < oper[0] ; i++)
		op.push_back('+');
	for(int i = 0 ; i < oper[1] ; i++)
		op.push_back('-');
	for(int i = 0 ; i < oper[2] ; i++)
		op.push_back('*');
	for(int i = 0 ; i < oper[3] ; i++)
		op.push_back('/');

  find(v,op,vector<bool>(op.size(),false),v[0], 0);

  printf("%d\n%d\n",maxVal,minVal);
	return 0;
}
