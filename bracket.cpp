#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	bool flag = false;
	stack<char> st;
	stack<int> op;
	string input;
	cin>>input;
	st.push(input[0]);
	//-3 * -2 +

	for(int i = 1 ; i < input.length() ; i++){

		if(input[i] == '(' || input[i] == '['){
			if(flag){//덧셈
				op.push(-2);
				flag = false;

			}else {
				op.push(-3);
			}
			st.push(input[i]);

		}else if(!st.empty() && (st.top() == '(' && input[i] == ')')){
			st.pop();
			op.push(2);
			flag = true;

		}else if(!st.empty() && (st.top() == '[' && input[i] == ']')){
			st.pop();
			op.push(3);
			flag = true;

		}else {
			cout<<0<<endl;
			return 0;
		}
	}
	if(!st.empty()){
		cout<<0<<endl;
		return 0;
	}
	stack<int> cal;
	while(!op.empty()){
		if(op.top() == -3){
			op.pop();
			int a = cal.top();
			cal.pop();
			while(cal.top() == -2){
				cal.pop();
				a += cal.top();
				cal.pop();
			}
			int result = a*cal.top();
			cal.pop();
			cal.push(result);
		}else {
			cal.push(op.top());
			op.pop();
		}
	}

	int sum = cal.top();
	cal.pop();
	while(!cal.empty()){
		cal.pop();
		sum += cal.top();
		cal.pop();
	}
	cout<<sum<<endl;

	return 0;
}
