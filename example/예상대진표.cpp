#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isIn(int start, int end, int num) {
        if(num >= start && num <= end) return true;
        else return false;
}
int solution(int n, int a, int b)
{
        int answer = log2(n);
        long long left = 1, right = n;
        int cnt = 0;
        while(true) {
                long long mid = (left + right) / 2;
                if(isIn(left,mid,a) && isIn(left,mid,b)) {
                        right = mid;
                        cnt++;
                }else if(isIn(mid+1,right,a) && isIn(mid+1,right,b)) {
                        left = mid+1;
                        cnt++;
                }else {
                        break;
                }
        }
        return answer - cnt;
}
