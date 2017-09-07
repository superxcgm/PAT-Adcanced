#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
int hash[20000];
int hash_cnt;
int size;
bool isPrime(int x)
{
    int sqx;
    if(x <=3 ) return x >= 2;
    if(x % 2 == 0 || x % 3 == 0) return false;
    sqx = (int)sqrt(x);
    for(int i = 5; i <= sqx; i += 6)
        if(x % i == 0 || x % (i+2) == 0)
            return false;
    return true;
}
int refine(int x)
{
    while(!isPrime(x))
        x++;
    return x;
}
int hash_op(int x)
{
    // >=0 success, -1 conflict, -2 impossible   
    if(hash_cnt > size / 2) return -2;
    int idx = (x + hash_cnt * hash_cnt) % size;
    if(hash[idx] != -1){
        hash_cnt++;
        return -1;
    }
    return idx;
}
void insert(int x)
{
    int rtn;
    hash_cnt = 0;
    while(1){
        rtn = hash_op(x);
        if(rtn == -2){
            putchar('-');
            return;
        }else if(rtn >= 0){
            printf("%d", rtn);
            hash[rtn] = 1;
            return ;
        }
    }   
}
int main()
{
    int nnum;
    int i, j;
    int num;
    
    //freopen("1078.txt", "r", stdin);
    //freopen("1078.out.txt", "w", stdout);
    memset(hash, 0xff, sizeof(hash));
    scanf("%d%d", &size, &nnum);
    size = refine(size);
    for(i = 0; i < nnum; ++i){
        scanf("%d", &num);
        if(i != 0) putchar(' ');
        insert(num);
    }
    return 0;
}