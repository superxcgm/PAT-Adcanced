#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

struct Node{
    int addr;
    int key;
    int next;
};
map<int, Node> mp;
vector<Node> vt_keep;
vector<Node> vt_rm;
int vis[100005];
void f(int start)
{
    Node tmp_node;
    int addr = start;
    int abs_key;
    
    while(addr != -1){
        tmp_node = mp[addr];
        abs_key = abs(tmp_node.key);
        if(vis[abs_key]){
            vt_rm.push_back(tmp_node);
        }else{
            vis[abs_key] = 1;
            vt_keep.push_back(tmp_node);
        }
        addr = tmp_node.next;
    }
}
int main()
{
    int start, nnode;
    int addr, key, next;
    int i, j;
    Node tmp_node;
    
    //freopen("1097.txt", "r", stdin);
    //freopen("1097.out.txt", "w", stdout);
    
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &start, &nnode);
    for(i = 0; i < nnode; ++i){
        scanf("%d%d%d", &addr, &key, &next);
        tmp_node.addr = addr;
        tmp_node.key = key;
        tmp_node.next = next;
        mp[addr] = tmp_node;
    }
    f(start);
    for(i = 0; i < vt_keep.size() - 1; ++i){
        printf("%.5d %d %.5d\n", vt_keep[i].addr, vt_keep[i].key, vt_keep[i + 1].addr);
    }
    if(vt_keep.size() > 0)
        printf("%.5d %d -1\n", vt_keep[vt_keep.size() - 1].addr,
            vt_keep[vt_keep.size() - 1].key);
    //remove list
    for(i = 0; i < vt_rm.size() - 1; ++i){
        printf("%.5d %d %.5d\n", vt_rm[i].addr, vt_rm[i].key, vt_rm[i + 1].addr);
    }
    if(vt_rm.size() > 0)
        printf("%.5d %d -1\n", vt_rm[vt_rm.size() - 1].addr,
            vt_rm[vt_rm.size() - 1].key);
    return 0;
}