#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

vector<int> children[105];
int gen_cnt[105];
struct Node{
    int id;
    int deep;  
};
queue<Node> qu;
void bfs()
{
    Node tmp_node, cur_node;
    int i;
    
    tmp_node.id = 1;
    tmp_node.deep = 1;
    qu.push(tmp_node);
    while(!qu.empty()){
        cur_node = qu.front();
        gen_cnt[cur_node.deep]++;
        qu.pop();
        for(i = 0; i < children[cur_node.id].size(); ++i){
            tmp_node.id = children[cur_node.id][i];
            tmp_node.deep = cur_node.deep + 1;
            qu.push(tmp_node);
        }
    }
}
int main()
{
    int nmem, nhave_child;
    int nchild;
    int mem_id;
    int child_id;
    int i, j, k;
    int maxx = -1;
    
    //freopen("1094.txt", "r", stdin);
    //freopen("1094.out.txt", "w", stdout);
    
    memset(gen_cnt, 0, sizeof(gen_cnt));
    scanf("%d%d", &nmem, &nhave_child);
    for(i = 0; i < nhave_child; ++i){
        scanf("%d%d", &mem_id, &nchild);
        while(nchild--){
            scanf("%d", &child_id);
            children[mem_id].push_back(child_id);
        }
    }
    bfs();
    for(i = 1; i <= nmem; ++i)
        if(maxx < gen_cnt[i]){
            maxx = gen_cnt[i];
            k = i;
        }
    printf("%d %d\n", maxx, k);
    return 0;
}