#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;
struct Ration{
    long long num; //numerators 
    long long den; //denominators 
};
long long gcd(long long a, long long b)
{
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
void output(Ration x)
{
    int neg = 0;
    if(x.num == 0){
        putchar('0');
        return;
    }
    if(x.num < 0){
        neg = 1;
        printf("(-");
        x.num = - x.num;
    }
    if(x.num >= x.den){
        printf("%lld", x.num / x.den);
        x.num %= x.den;
        if(x.num)
            putchar(' ');
    }
    if(x.num)
        printf("%lld/%lld", x.num, x.den);
    if(neg)
        putchar(')');
}
void refine(Ration &x)
{
    int tmp;
    if(x.num == 0){
        x.den = 0;
        return ;
    }
    while((tmp = gcd(x.num, x.den)) != 1){
        x.num /= tmp;
        x.den /= tmp;
    }
    if(x.den < 0){
        x.num = -x.num;
        x.den = -x.den;
    }
}
void add(Ration a, Ration b)
{
    Ration c;
    if(a.num == b.num && a.num == 0){
        c.num = 0;
        c.den = 0;
    }else if(b.num == 0){
        c = a;
    }else if(a.num == 0){
        c = b;
    }else if(a.den == b.den){
        c.num = a.num + b.num;
        c.den = a.den;
    }else{
        c.den = lcm(a.den, b.den);
        c.num = c.den / a.den * a.num;
        c.num += c.den / b.den * b.num;
    }
    refine(c);
    output(c);
    putchar('\n');
}
void mul(Ration a, Ration b)
{
    Ration c;
    
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    refine(c);
    output(c);
    putchar('\n');
}
void calc(Ration a, Ration b, char op)
{
    switch(op){
        case '+':
            add(a, b);
            break;
        case '-':
            b.num = -b.num;
            add(a, b);
            break;
        case '*':
            mul(a, b);
            break;
        case '/':
            if(b.num == 0)
                printf("Inf\n");
            else{
                swap(b.num, b.den);
                mul(a, b);
            }
            break;
    }
}
int main()
{
    Ration a, b, c;
    char op[] = "+-*/";
    int i;
    
    //freopen("1088_1.txt", "r", stdin);
    //freopen("1088.out.txt", "w", stdout);
    
    scanf("%lld/%lld", &a.num, &a.den);
    scanf("%lld/%lld", &b.num, &b.den);
    
    refine(a);
    refine(b);
    for(i = 0; i < 4; ++i){
        output(a);
        printf(" %c ", op[i]);
        output(b);
        printf(" = ");
        calc(a, b, op[i]);
    }
    
    return 0;
}