#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
double price_raise;
double highest_price = -1;
int highest_cnt = 0;
vector<int> vt_sup[100005];
void dfs(int cur, double price)
{
    int i;
    if(vt_sup[cur].empty()){
        //retailers
        if(price > highest_price){
            highest_price = price;
            highest_cnt = 1;
        }else if(price == highest_price){
            highest_cnt++;
        }
        return ;
    }
    price *= price_raise;
    for(i = 0; i < vt_sup[cur].size(); ++i){
        dfs(vt_sup[cur][i], price);
    }
}
int main()
{
    double init_price;
    int nmem;
    int i, j;
    int supplier;
    int root_supplier;
    
    //freopen("1090.txt", "r", stdin);
    //freopen("1090.out.txt", "w", stdout);
    
    scanf("%d%lf%lf", &nmem, &init_price, &price_raise);
    price_raise /= 100;
    price_raise += 1;
    
    for(i = 0; i < nmem; ++i){
        scanf("%d", &supplier);
        if(supplier == -1)
            root_supplier = i;
        else
            vt_sup[supplier].push_back(i);
    }
    dfs(root_supplier, init_price);
    printf("%.2lf %d", highest_price, highest_cnt);
    return 0;
}