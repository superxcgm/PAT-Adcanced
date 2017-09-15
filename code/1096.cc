#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    long long num;
    int sqx;
    int i, j;
    int max_len = -1;
    int start;
    
    //freopen("1096.txt", "r", stdin);
    //freopen("1096.out.txt", "w", stdout);
    
    scanf("%lld", &num);
    sqx = sqrt(num) + 1;
    for(i = 2; i <= sqx; ++i){
        long long mul = 1;
        int len = 0;
        
        for(j = i; j <= 28; ++j){
            mul *= j;
            if(mul > num || num % mul != 0) break;
            len++;
            if(len > max_len){
                max_len = len;
                start = i;
            }
        }
    }
    if(max_len == -1)
        printf("1\n%lld", num);
    else{
        printf("%d\n", max_len);
        printf("%d", start);
        for(i = start + 1; i < start + max_len; ++i)
            printf("*%d", i);
    }
    return 0;
}