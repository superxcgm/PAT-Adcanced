#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
char str[100005];
const int MOD = 1000000007;
int main()
{
    int i, j, k;
    int len;
    int p, q;
    int cnt_t = 0;
    int cnt = 0;
    int at_pire = 0;
    
    //freopen("1093.txt", "r", stdin);
    //freopen("1093.out.txt", "w", stdout);
    
    scanf("%s", str);
    len = strlen(str);
    for(i = len - 1; i >= 0; --i){
        if(str[i] == 'T')
            cnt_t++;
        else if(str[i] == 'A'){
            at_pire = (at_pire + cnt_t) % MOD;
        }else{
            //p
            cnt = (cnt + at_pire) % MOD;
        }
    }
    printf("%d\n", cnt);
    return 0;
}