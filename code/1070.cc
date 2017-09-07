#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

struct Mooncake{
       double inv;
       double price;
       double single_price;       
} mooncake[1005];
bool cmp(const Mooncake &a, const Mooncake &b)
{
     return a.single_price > b.single_price;
}
int main()
{
    int nkind;
    double total;
    int i, j;
    double sum = 0;
    
    //freopen("1070.txt", "r", stdin);
    //freopen("1070.out.txt", "w", stdout);
    scanf("%d%lfd", &nkind, &total);
    for(i = 0; i < nkind; ++i)
          scanf("%lf", &mooncake[i].inv);
    for(i = 0; i < nkind; ++i){      
          scanf("%lf", &mooncake[i].price);
          mooncake[i].single_price = mooncake[i].price / mooncake[i].inv;
    }
    sort(mooncake, mooncake + nkind, cmp);
    i = 0;
    while(total > 0 && i < nkind){
                if(total >= mooncake[i].inv){
                         sum += mooncake[i].price;
                         total -= mooncake[i].inv;
                }else{
                      sum += total * mooncake[i].single_price;
                      total = 0;
                }
                ++i;
    }
    printf("%.2lf", sum);
    return 0;
}