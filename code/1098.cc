#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int heap;
int init_num[110];
int des_num[110];
int tmp_num[110];
int nnum;
int is_insert_sort = 0;
void insert_sort_check()
{
    int i, j;
    int key;
    
    for(i = 1; i <= nnum; ++i)
        tmp_num[i] = init_num[i];
    for(i = 2; i <= nnum; ++i){
        key = tmp_num[i];
        j = i - 1;
        while(j > 0 && tmp_num[j] > key){
            tmp_num[j + 1] = tmp_num[j];
            j--;
        }
        tmp_num[j + 1] = key;
        if(is_insert_sort){
            printf("Insertion Sort\n");
            printf("%d", tmp_num[1]);
            for(j = 2; j <= nnum; ++j)
                printf(" %d", tmp_num[j]);
            return;
        }
        is_insert_sort = 1;
        for(j = 1; j <= nnum; ++j)
            if(tmp_num[j] != des_num[j])
                is_insert_sort = 0;
    }
}
void heap_sort()
{
    int hp = 0;
    int i, j;
    int l, r;
    int cur, pos;
    
    printf("Heap Sort\n");
    for(i = nnum; i > 0; --i)
        if(des_num[1] > des_num[i]){
            swap(des_num[1], des_num[i]);
            pos = i;
            break;
        }
    //adjust
    cur = 1;
    l = cur *2;
    r = l + 1;
    while(l < pos){
        if(r < pos){
            if(des_num[l] >= des_num[r] && des_num[l] >= des_num[cur]){
                swap(des_num[cur], des_num[l]);
                cur = l;
            }else if(des_num[r] >= des_num[l] && des_num[r] >= des_num[cur]){
                swap(des_num[cur], des_num[r]);
                cur = r;
            }else
                break;
        }else{
            if(des_num[cur] >= des_num[l])
                break;
            else{
                swap(des_num[cur], des_num[l]);
                cur = l;
            }
        }
        l = cur *2;
        r = l + 1;        
    }
    printf("%d", des_num[1]);
    for(i = 2; i <= nnum; ++i)
        printf(" %d", des_num[i]);
}
int main()
{
    int i, j, k;
    
    //freopen("1098_1.txt", "r", stdin);
    //freopen("1098.out.txt", "w", stdout);
    
    scanf("%d", &nnum);
    for(i = 1; i <= nnum; ++i)
        scanf("%d", &init_num[i]);
    for(i = 1; i <= nnum; ++i)
        scanf("%d", &des_num[i]);
    insert_sort_check();
    if(!is_insert_sort)
        heap_sort();
    return 0;
}