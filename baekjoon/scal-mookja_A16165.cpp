#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <queue>
using namespace std;
struct cmp {//여기서 사용자가 min, max등 heap의 우선순위를 정해줄 수 있다.
  bool operator()(char * a, char * b){//이건 ascii상으로 오름차정렬에 해당
    if(strcmp(a, b) > 0){ //a가 더 크면 == 아스키코드상 뒤 == 사전 정렬상 뒤로 가는게 참 ex) apple,mango는 apple이 작음으로 음수 반환 즉, 이 조건문에선 거짓이 된다
      return true;//트리에서 부모 노드가 a로 자식 노드가 b로 간다. 참이면 swap!
    }else {
      return false;
    }
  }
};
//내림차 큰것부터 작은것으로
//오름차 작은것 부터 큰 것으로
int main(){
  priority_queue<char *,vector<char *>,cmp> heap;//input, output의 형을 <>으로 정할 수 있고 힙의 성질을 세번째 매개변수에 넣는데 위와 같이 사용자 정의 할 수 있다.
  int N = 0, question = 0;                      //  뒤에 cmp >부분에서 less <T>>의 꼴 등으로 쓰이게 될 경우 less <T> >로 반드시 >와 >사이에 공백이 한칸 있어야 한다.
  scanf("%d %d",&N, &question);
  char *** input;
  input = new char ** [N+1];//고차원 동적할당 방법 숙지
  int * groupLength = new int [N+1];
  char * group = new char [100];
  int memberNum = 0;
  for(int i = 0 ; i < N ; i++){
    scanf("%s",group);
    scanf("%d",&memberNum);
    groupLength[i] = memberNum;
    input[i] = new char * [memberNum+1];
    input[i][0] = new char [100];
    strcpy(input[i][0],group);//이 부분은 group의 메모리를 포인트 하는게 목적이 아니라 group에 씌워진 문자열을 복사하는 것이기 때문에 strcpy를 쓰는게 적절하다.
    for(int j = 1 ; j <= memberNum ; j++){
        input[i][j] = new char [100];
        scanf("%s",input[i][j]);
        heap.push(input[i][j]);
    }
    for(int j = 1 ; j <= memberNum ; j++){
      input[i][j] = heap.top();//strcpy(input[i][j], heap.top())으로 하면 안됨
      //위 priority_queue 에서 매개변수와 반환 형이 char * 로 선언 했다. 즉, 문자열 포인터를 반환하는 것으로
      // input[i][j] = heap.top()은 기존 input[i][j]가 가리키는 메모리의 위치를 heap으로 sorting 된 순서대로 다시 가리키게 되는 것이다.
      //여기서 strcpy를 쓰면 값이 덧씌워 지는듯한 결과가 나오는데 이는 input 과 heap 모두 같은 메모리 공간을 가리키기 때문에 나타나는 현상이다.
      heap.pop();
    }
  }

  char * q = new char [100];
  int type = -1;
  for(int i = 0 ; i < question ; i++){
    scanf("%s",q);
    scanf("%d",&type);
    if(type == 1){//1 return group name
      for(int n = 0 ; n < N ; n++){
        for(int g = 1 ; g <= groupLength[n] ; g++){
          if(strcmp(q,input[n][g]) == 0){
            printf("%s\n",input[n][0]);
            break;
          }
        }
      }
    }else {//0 return member
      for(int n = 0 ; n < N ; n++){
        if(strcmp(q,input[n][0]) == 0){
          for(int g = 1 ; g <= groupLength[n] ; g++){
            printf("%s\n",input[n][g]);
          }
          break;
        }
      }
    }
  }

  delete[] q;
  delete[] group;
  delete[] groupLength;
  delete[] input;//***이어도 delete 한번만 하면 되는듯?
  //if(음수가 들어가도 참으로 반환, 오직 0만 거짓)
  return 0;
}
