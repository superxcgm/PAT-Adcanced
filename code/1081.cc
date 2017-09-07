#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

long long gcd(long long a, long long b)
{
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
long long numerator;
long long denominator;
void add(long long a, long long b)
{
    long long tmp_lcm;
    if(b == denominator)
        numerator += a;
    else{
        tmp_lcm = lcm(b, denominator);
        numerator *= tmp_lcm / denominator;
        a *= tmp_lcm / b;
        numerator += a;
        denominator = tmp_lcm;
    }
}
void refine()
{
    long long tmp_gcd;
    while((tmp_gcd = gcd(numerator, denominator)) != 1){
        numerator /= tmp_gcd;
        denominator /= tmp_gcd;
    }
}
int main()
{
    int nnum;
    long long a, b;
    int flag = 0;
    int i;
    
    //freopen("1081_2.txt", "r", stdin);
    //freopen("1081.out.txt", "w", stdout);
    scanf("%d", &nnum);
    scanf("%lld/%lld", &numerator, &denominator);
    refine();
    for(i = 1; i < nnum; ++i){
        scanf("%lld/%lld", &a, &b);
        add(a, b);
        refine();
    }
    if(numerator == 0){
        printf("0");
        return 0;
    }
    if(numerator > denominator){
        printf("%lld", numerator / denominator);
        numerator %= denominator;
        flag = 1;
    }
    if(numerator){
        if(flag)
            putchar(' ');
        printf("%lld/%lld", numerator, denominator);
    }
    return 0;
}