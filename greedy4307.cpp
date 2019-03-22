#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  for(int x = 0 ; x < n ; x++){
    int length , num, fast, late;
    scanf("%d %d",&length, &num);
    int array[num];
    for(int i = 0 ; i < num ; i++)
      scanf("%d",&array[i]);
    sort(array,array+num);
    late = max(length - array[0],array[num-1]);
    int tmp = 987654321;
    for(int i = 0 ; i < num ; i++){
      if(tmp > abs(length/2 - array[i])){
        tmp = abs(length/2 - array[i]);
        fast = array[i];
      }
    }
    fast = min(length - fast,fast);
    printf("%d %d\n",fast,late);
  }
  return 0;
}
