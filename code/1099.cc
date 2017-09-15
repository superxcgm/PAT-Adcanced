#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>

using namespace std;
struct Node{
    int key;
    int left, right;
};
const int INF = 0x3f3f3f3f;
Node bst[110];
int num[110];
int nnum;
int use[110];
queue<int> qu;
void print_tree(int cur)
{
    qu.push(cur);
    while(!qu.empty()){
        cur = qu.front();
        if(cur != 0)
            putchar(' ');
        printf("%d", bst[cur].key);
        if(bst[cur].left != -1)
            qu.push(bst[cur].left);
        if(bst[cur].right != -1)
            qu.push(bst[cur].right);
        qu.pop();
    }
}
int count_node(int cur)
{
    int cnt;
    if(cur == -1)
        return 0;
    cnt = 1;
    cnt += count_node(bst[cur].left);
    cnt += count_node(bst[cur].right);
    return cnt;
}
void fill(int cur, int l, int r)
{
    int i;
    int n_l;
    int n_r;
    
    if(cur == -1)
        return;
    n_l = count_node(bst[cur].left);
    n_r = count_node(bst[cur].right);
    bst[cur].key = num[l + n_l];
    fill(bst[cur].left, l, l + n_l - 1);
    fill(bst[cur].right, l + n_l + 1, r);
    
}
int main()
{
    int i;
    
    //freopen("1099.txt", "r", stdin);
    //freopen("1099.out.txt", "w", stdout);
    memset(use, 0, sizeof(use));
    scanf("%d", &nnum);
    for(i = 0; i < nnum; ++i)
        scanf("%d%d", &bst[i].left, &bst[i].right);
    for(i = 0; i < nnum; ++i)
        scanf("%d", &num[i]);
    sort(num, num + nnum);
    fill(0, 0, nnum - 1);
    print_tree(0);
    return 0;
}