#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
int num[100005];
int main()
{
    int nnum, p;
    long long M;
    int l = 0;
    int i;
    int max_ans = -1;

    //freopen("1085.txt", "r", stdin);
    //freopen("1085.out.txt", "w", stdout);
    
    scanf("%d%d", &nnum, &p);
    for(i = 0; i < nnum; ++i)
        scanf("%d", &num[i]);
    sort(num, num + nnum);
    for(i = 0; i < nnum; ++i){
        M = num[i];
        // num[l] stands for m
        while(i != l && M > 1LL * num[l] * p)
            l++;
        if(i - l + 1 > max_ans)
            max_ans = i - l + 1;
    }
    printf("%d\n", max_ans);
    return 0;
}