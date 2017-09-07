#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>

using namespace std;
struct Node{
    int key;
    int next;  
};
map<int, Node> mp;
int nnode, reverse_len;
void xc_print(int cur)
{
    vector<int> vt;
    vector<int> vt_tmp;
    int flag = 0;
    int i;
    while(cur != -1){
        vt_tmp.push_back(cur);
        cur = mp[cur].next;
        if(vt_tmp.size() == reverse_len)
            while(!vt_tmp.empty()){
                vt.push_back(vt_tmp.back());
                vt_tmp.pop_back();
            }
    }
    for(i = 0; i < vt_tmp.size(); ++i)
        vt.push_back(vt_tmp[i]);
    for(i = 0; i < vt.size() - 1; ++i)
        printf("%.5d %d %.5d\n", vt[i], mp[vt[i]].key, vt[i + 1]);
    printf("%.5d %d -1\n", vt[i], mp[vt[i]].key);
}
int main()
{
    int start;
    int i, j, addr;
    struct Node tmp;
    
    //freopen("1074.txt", "r", stdin);
    //freopen("1074.out.txt", "w", stdout);
    scanf("%d%d%d", &start, &nnode, &reverse_len);
    for(i = 0; i < nnode; ++i){
        scanf("%d%d%d", &addr, &tmp.key, &tmp.next);
        mp[addr] = tmp;
    }
    xc_print(start);
    return 0;
}