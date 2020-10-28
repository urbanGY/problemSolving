ll gcd(ll a, ll b) //최대공약수
{
        if(a % b == 0)
                return b;
        return gcd(b, a % b);
}

ll lcm(ll a, ll b) // 최소공배수
{
        return a * b / gcd(a,b);
}
