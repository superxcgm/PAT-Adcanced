#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
int sale[100005];
vector<int> vt[100005];
double increase_rate;
double total_sale;
void dfs(int cur, double price)
{
    int len, i;
    if(sale[cur] != 0){
        // retailer
        total_sale += sale[cur] * price;
        return;
    }
    len = vt[cur].size();
    for(i = 0; i < len; ++i)
        dfs(vt[cur][i], price * increase_rate);
}
int main()
{
    int nmem;
    double init_price;
    int i;
    int nnum;
    int cnt;
    int next;
    
    //freopen("1079.txt", "r", stdin);
    //freopen("1079.out.txt", "w", stdout);
    scanf("%d %lf %lf", &nmem, &init_price, &increase_rate);
    increase_rate = 1 + increase_rate/100;
    total_sale = 0;
    memset(sale, 0, sizeof(sale));
    for(i = 0; i < nmem; ++i){
        scanf("%d", &nnum);
        if(nnum == 0){
            // retailer
            scanf("%d", &cnt);
            sale[i] = cnt;
        }else{
            while(nnum--){
                scanf("%d", &next);
                vt[i].push_back(next);    
            }
        }
    }
    dfs(0, init_price);
    printf("%.1lf", total_sale);
    return 0;
}