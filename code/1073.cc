#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
char buf[20005];
int main()
{
    int ch;
    int after_point = 0;
    int i, k = 0;
    int exp;
    
    //freopen("1073_1.txt", "r", stdin);
    //freopen("1073.out.txt", "w", stdout);
    /* sign */
    ch = getchar();
    if(ch == '-')
        putchar(ch);
    ch = getchar();
    buf[k++] = ch;
    ch = getchar();/* point */
    while((ch = getchar()) != 'E')
        buf[k++] = ch;
    buf[k] = 0;
    scanf("%d", &exp);
    if(exp < 0){
        printf("0.");
        exp = -exp;
        exp--;
        while(exp--)
            putchar('0');
        printf("%s", buf);
    }else if(exp == 0)
        printf("%c.%s", buf[0], buf + 1);
    else{
        int cnt = exp - (k - 1);
        int flag = 1;
        if(cnt < 0){
            for(i = 0; i < k; ++i){
                putchar(buf[i]);
                if(i != k && flag && i == exp){
                    putchar('.');
                    flag = 0;
                }
            }
        }else{
            printf("%s", buf);
            while(cnt--)
                putchar('0');
        }
    }
    //while(1);
    return 0;
}