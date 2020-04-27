#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
private :
  int num;
  Node * next;
  Node * pref;
public:
  Node(int num)
  :num(num), next(NULL), pref(NULL)
  {

  }
  ~Node()
  {

  }
  void setNext(Node * node)
  {
    this->next = node;
  }
  Node * getNext()
  {
    return this->next;
  }
  void setPref(Node * node)
  {
    this->pref = node;
  }
  Node * getPref()
  {
    return this->pref;
  }
  int getInfo()
  {
    return num;
  }
};

class RoundQueue
{
private:
  Node * head;
  Node * tail;
  Node * cur;
  int shiftCount;
public:
  RoundQueue()
  :head(NULL), tail(NULL), cur(NULL), shiftCount(0)
  {

  }
  ~RoundQueue()
  {
    if(head != NULL){//애초에 남은 queue가 없다면 아래의 delete head가 런타임 에러 야기함으로 애초에 if로 분기해준다.
      Node * temp;
      while(head != tail){//순환 큐로 이전의 while 조건문인 head != NULL로 하면
        temp = head;      //최종적으로 head가 delete된 자기자신이 있던 쓰레기값을 포인트 하고 그걸 delete하면서 런타임 에러 발생
        head = head->getNext();
        delete temp;
      }
      delete head;
    }
  }
  void enqueue(int num){
    cur = new Node(num);
    if(head == NULL){
      head = cur;
      tail = cur;
    }else {
      tail->setNext(cur);
      cur->setPref(tail);
      head->setPref(cur);
      cur->setNext(head);
      tail = tail->getNext();
    }
    cur  = NULL;
  }
  int front()
  {
    return head->getInfo();
  }
  void dequeue()
  {
    if(head != NULL){
      if(tail == head){//큐에 하나만 남아있을 때도 따로 고려해 줘야함. head->getNext() == head하면 백준에서는 런타임뜨네?
        delete head;
        head = NULL;
        tail = NULL;//메모리 헤제 조건문이 head,tail의 NULL임으로 확실히 NULL로 초기화 해줘야 한다.
      }else {
        cur = head;
        head = head->getNext();
        delete cur;
        cur = NULL;
        tail->setNext(head);
        head->setPref(tail);
      }
    }
  }
  void shiftLeft()
  {
    shiftCount++;
    head = head->getNext();
    tail = tail->getNext();
  }
  void shiftRight()
  {
    shiftCount++;
    tail = tail->getPref();
    head = head->getPref();
  }
  void shift(int input)
  {
    int left = 0, right = 0;
    cur = head;
    while(cur->getInfo() != input){
      left++;
      cur = cur->getNext();
    }
    cur = tail;
    while(cur->getInfo() != input){
      right++;
      cur = cur->getPref();
    }
    if(right < left){//left 와 right가 동점일 땐 leftshitf가 더 적은 연산비용
      for(int i = 0 ; i <= right ; i++){
        shiftRight();
      }
      dequeue();
    }else {
      for(int i = 0 ; i < left ; i++){
        shiftLeft();
      }
      dequeue();
    }
    cur = NULL;
  }
  void showAll()
  {
    cur = head;
    printf("%d, ",cur->getInfo());
    while(cur != tail){
      cur = cur->getNext();
      printf("%d, ",cur->getInfo());
    }
    printf("\n");
  }
  int getCount()
  {
    return shiftCount;
  }
};

int main(){
  RoundQueue rq;
  int N = 0, M = 0;
  scanf("%d %d",&N,&M);
  for(int i = 1 ; i <= N ; i++){
    rq.enqueue(i);
  }
  for(int i = 0 ; i < M ; i++){
    int input = 0;
    scanf("%d",&input);
    rq.shift(input);
  }
  printf("%d\n",rq.getCount());
  return 0;
}
