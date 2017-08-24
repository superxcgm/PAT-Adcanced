#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <set>
#include <stack>

using namespace std;
const int INF = 0x3f3f3f3f;

multiset<int> minm, maxm;
stack<int> st;
int mid = INF;
void adjust()
{
    multiset<int>::iterator it;
    /* minn.size() == maxm.size() || minn.size() == maxm.size() + 1 */
    if(minm.size() < maxm.size()){
        minm.insert(*maxm.begin());
        maxm.erase(maxm.begin());
    }
    if(minm.size() > maxm.size() + 1){
        it = minm.end();
        --it;
        maxm.insert(*it);
        minm.erase(it);
    }
    if(st.empty())
        mid = INF;
    else{
        it = minm.end();
        --it;
        mid = *it;
    }
}
int main(void)
{
    int ncmd;
    char cmd[15];
    int num;

    // freopen("1057.in", "r", stdin);
    scanf("%d", &ncmd);
    while(ncmd--){
        scanf("%s", cmd);
        if(cmd[1] == 'o'){          /* pop */
            if(st.empty()){
                printf("Invalid\n");
                continue;
            }
            num = st.top();
            printf("%d\n", num);
            st.pop();
            if(num > mid){
                // printf("max before erase: %d\n", maxm.size());
                maxm.erase(maxm.find(num));
                // printf("max after erase: %d\n", maxm.size());
            }else{
                // printf("min before erase: %d\n", minm.size());
                minm.erase(minm.find(num));
                // printf("min after erase: %d\n", minm.size());
            }
            adjust();
        }else if(cmd[1] == 'u'){    /* push */
            scanf("%d", &num);
            st.push(num);
            if(num > mid)
                maxm.insert(num);
            else
                minm.insert(num);
            adjust();
        }else{                      /* PeekMedian */
            if(st.empty()){
                printf("Invalid\n");
                continue;
            }
            printf("%d\n", mid);
        }
    }

    return 0;
}