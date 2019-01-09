#include <iostream>
using namespace std;
int min(int , int);

int main(){
  int N = 0;
  scanf("%d",&N);
  int a = 0, b = 0, c = 0;
  int red = 0, green = 0, blue = 0;
  int min_red = 0, min_green = 0, min_blue = 0;
  for(int i = 0 ; i < N ; i++){
    min_red = a;
    min_green = b;
    min_blue = c;
    scanf("%d %d %d",&red,&green,&blue);
    a = red + min(min_green,min_blue);
    b = green + min(min_red,min_blue);
    c = blue + min(min_red, min_green);
    // a = min_red + min(green,blue);
    // b = min_green + min(red,blue);
    // c = min_blue + min(red,green);
    //입력값 red,green,blue를 기준으로 현재 내가 선택한 색을 구분
    printf("%d %d %d\n",a,b,c);
  }
  printf("%d",min(a,min(b,c)));
  return 0;
}

int min(int a, int b)
{
  if(a < b)
    return a;
  else
    return b;
}
