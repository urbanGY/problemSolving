#include <iostream>
#include <stack>
using namespace std;

int main(){
  stack<int> st;
  int N;
  scanf("%d",&N);
  int array[N];
  char * answer = new char[2*N+1];
  for(int i = 0 ; i < N ; i++)
    scanf("%d",&array[i]);

  int index = 0;
  int cnt = 1;
  st.push(cnt++);
  answer[index++] = '+';
  for(int i = 0 ; i < N ; i++){
    while(true){
      if(cnt > N+1){
        printf("NO");
        return 0;
      }
      if(!st.empty() && st.top() == array[i]){
        st.pop();
        answer[index++] = '-';
        break;
      }
      st.push(cnt++);
      answer[index++] = '+';
    }
  }
  for(int i = 0 ; answer[i] != '\0' ; i++)
    printf("%c\n",answer[i]);
  return 0;
}
