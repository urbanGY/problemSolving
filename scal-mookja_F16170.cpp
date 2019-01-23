#include <iostream>
#include <ctime>
using namespace std;

int main(){
  time_t curr_time;
  struct tm * curr_tm;
  curr_time = time(NULL);
  curr_tm = localtime(&curr_time);
  cout<<curr_tm->tm_year+1900<<endl;
  cout<<curr_tm->tm_mon+1<<endl;
  cout<<curr_tm->tm_mday<<endl;
  //현재 KST 년 월 일 반환
  return 0;
}
