#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int have[256];

int main()
{
    int i, j;
    int len1, len2;
    int mis = 0;
    char strings[1024];
    char desire[1024];
    
    //freopen("1092_1.txt", "r", stdin);
    //freopen("1092.out.txt", "w", stdout);
    
    memset(have, 0, sizeof(have));
    
    scanf("%s %s", strings, desire);
    len1 = strlen(strings);
    len2 = strlen(desire);
    for(i = 0; i < len1; ++i)
        have[strings[i]]++;
    for(i = 0; i < len2; ++i){
        if(have[desire[i]] > 0){
            have[desire[i]]--;
        }else
            mis++;
    }
    if(mis)
        printf("No %d\n", mis);
    else
        printf("Yes %d\n", len1 - len2);
    return 0;
}