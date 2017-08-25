#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int num[BUFSIZ];
int nnum;
int tree[BUFSIZ];
int pos;

void build(int cur)
{
    int l, r;

    if(cur > nnum) return;
    l = cur * 2;
    r = l + 1;
    build(l);
    tree[cur] = num[pos++];
    build(r);
}

int main(void)
{
    int i;

    scanf("%d", &nnum);
    for(i = 0; i < nnum; ++i)
        scanf("%d", &num[i]);
    sort(num, num + nnum);
    pos = 0;

    build(1);
    printf("%d", tree[1]);
    for(i = 2; i <= nnum; ++i)
        printf(" %d", tree[i]);

    return 0;
}