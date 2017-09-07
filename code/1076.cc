#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int follow[1005][1005];
int sum;
int vis[1005];
int nuser, nlevels;
struct Node{
    int id;
    int deep;
};
queue<Node> qu;
int bfs(int cur)
{
    struct Node cur_node, tmp_node;
    int ans = 0, i, j;
    while(!qu.empty())
        qu.pop();
    tmp_node.id = cur;
    tmp_node.deep = 0;
    qu.push(tmp_node);
    memset(vis, 0, sizeof(vis));
    vis[cur] = 1;
    while(!qu.empty()){
        cur_node = qu.front();
        qu.pop();
        if(cur_node.deep == nlevels) continue;
        for(i = 1; i <= nuser; ++i){
            if(!vis[i] && follow[i][cur_node.id]){
                vis[i] = 1;
                ++ans;
                tmp_node.id = i;
                tmp_node.deep = cur_node.deep + 1;
                qu.push(tmp_node);
            }
        }
    }
    return ans;
}
int main()
{
    int i, j;
    int nfollow;
    int uid;
    int nquery;
    
    //freopen("1076.txt", "r", stdin);
    //freopen("1076.out.txt", "w", stdout);
    scanf("%d%d", &nuser, &nlevels);
    memset(follow, 0, sizeof(follow));
    for(i = 1; i <= nuser; ++i){
        scanf("%d", &nfollow);
        for(j = 0; j < nfollow; ++j){
            scanf("%d", &uid);
            follow[i][uid] = 1;
        }
    }
    scanf("%d", &nquery);
    for(i = 0; i < nquery; ++i){
        scanf("%d", &uid);
        printf("%d\n", bfs(uid));
    }
    return 0;
}