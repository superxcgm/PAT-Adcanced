#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
int checked[256];
int main()
{
    char str1[100];
    char str2[100];
    char *p, *q;
    
    //freopen("1084.txt", "r", stdin);
    //freopen("1084.out.txt", "w", stdout);
    
    scanf("%s%s", str1, str2);
    memset(checked, 0, sizeof(checked));
    p = str1;
    while(*p != '\0'){
        if(*p >= 'a' && *p <= 'z')
                *p = *p - ('a' - 'A');
        if(checked[*p]){
            p++;
            continue;
        }
        checked[*p] = 1;
        q = str2;
        int flag = 0;
        while(*q != '\0'){
            if(*q >= 'a' && *q <= 'z')
                *q = *q - ('a' - 'A');
            if(*p == *q){
                flag = 1;
                break;
            }
            q++;
        }
        if(flag == 0)
            putchar(*p);
        p++;
    }
    return 0;
}