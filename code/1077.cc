#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char str[103][260];
int p[103];
int n;
int main()
{
    int i;
    int common_len = 0;
    
    //freopen("1077_1.txt", "r", stdin);
    //freopen("1077.out.txt", "w", stdout);
    scanf("%d\n", &n);
    for(i = 0; i < n; ++i){
        gets(str[i]);
        p[i] = strlen(str[i]) - 1;
    }
    
    while(1){
        for(i = 0; i < n; ++i)
            if(p[i] < 0)
                goto there;
        for(i = 1; i < n; ++i){
            if(str[i][p[i]] != str[0][p[0]])
                goto there;
            p[i]--;
        }
        p[0]--;
        common_len++;
    }
    there:if(common_len){
        printf("%s", str[0] + (strlen(str[0]) - common_len));
    }else{
        printf("nai\n");
    }
    return 0;
}