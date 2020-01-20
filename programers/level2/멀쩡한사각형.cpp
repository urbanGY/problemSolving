// 직사각형에 대각선을 그었을 때 대각선에 걸린 1*1 사각형의 수가 hole
// 개수의 규칙은 w, h의 gcd를 구한 후
// long long hole = gcd * (w/gcd) * (h/gcd)
// !! 이때 제일 주의해야할 것은 w * h를 할 때 long long 케스팅을 하고 계산을 해야한다는 것이다
// long long ans = (w*h) - hole -> 이러면 오버플로우 된 값 짤린 채로 나머지값만 ans로 쑥
// long long ans = (long long)w * (long long)h - hole -> 이렇게 개별적으로 캐스팅을 진행한 후 계산을 한다


using namespace std;

long long solution(int w,int h)
{
    int gcd = 1;
    for(int i = 2 ; i <= (w < h ? w : h) ; i++){
        if(w%i == 0 && h%i == 0)
            gcd = i;
    }
    int blockW = w/gcd;
    int blockH = h/gcd;
    int cnt = blockW + blockH - 1;
    long long hole = cnt*gcd;
    long long answer = ((long long)w*(long long)h) - hole;
	return answer;
}
