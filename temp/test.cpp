#include <iostream>
using namespace std;

long long m = 1099511627776;
long long s0 = 1611516670;

long long even = 0, odd = 0;

int isEven(long long n) {
        if(n%2 == 0) return 0;
        else return 1;
}

void func(long long n) {
        long long tmp = s0;
        long long next;
        for(int i = 0; i < n; i++) {
                if(tmp%2 == 0) even++;
                else odd++;
                //cout<<i<<" - even : "<<even<<" , odd : "<<odd<<endl;
                cout<<" i : "<<i<<" - "<<isEven(tmp)<<" , "<<isEven((tmp>>20))<<endl;
                //cout<<"i : "<<i<<"  -  tmp>>20 : "<<(tmp>>20)<<" , "<<"12345 : "<<(12345*i)<<endl;
                next = ((tmp) + (tmp >> 20) + 12345) % m;
                tmp = next;
        }
        cout<<even<<endl;
}
int main() {
        long long input;
        scanf("%lld",&input);
        func(input);
        return 0;
}
