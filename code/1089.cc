#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int init_num[110];
int target_num[110];
int nnum;
int is_insert_sort = 0;
void insert_sort_detect()
{
    int tmp_num[110];
    int i, j, k;
    int key;
    int same = 0;
    
    for(i = 0; i < nnum; ++i)
        tmp_num[i] = init_num[i];
    for(i = 1; i < nnum; ++i){
        key = tmp_num[i];
        j = i - 1;
        while(j >= 0 && tmp_num[j] > key){
            tmp_num[j + 1] = tmp_num[j];
            j--;
        }
        tmp_num[j + 1] = key;
        if(same == 1){
            is_insert_sort = 1;
            printf("Insertion Sort\n");
            printf("%d", tmp_num[0]);
            for(j = 1; j < nnum; ++j)
                printf(" %d", tmp_num[j]);
            break;
        }
        same = 1;
        for(j = 0; j < nnum; ++j)
            if(tmp_num[j] != target_num[j]){
                same = 0;
                break;
            }
    }
}
void merge_sort()
{
    int size = 2;
    int end;
    int same = 0;
    int i, j;
    
    while(1){
        for(i = 0; i < nnum; i += size){
            end = i + size;
            if(end > nnum)
                end = nnum;
            sort(init_num + i, init_num + end);
        }
        if(same == 1){
            printf("Merge Sort\n");
            printf("%d", init_num[0]);
            for(j = 1; j < nnum; ++j)
                printf(" %d", init_num[j]);
            break;
        }
        same = 1;
        for(i = 0; i < nnum; ++i)
            if(init_num[i] != target_num[i]){
                same = 0;
                break;
            }
        size *= 2;
    }
}
int main()
{
    int i, j;
    
    //freopen("1089_1.txt", "r", stdin);
    //freopen("1089.out.txt", "w", stdout);
    
    scanf("%d", &nnum);
    for(i = 0; i < nnum; ++i)
        scanf("%d", &init_num[i]);
        
    for(i = 0; i < nnum; ++i)
        scanf("%d", &target_num[i]);    
    
    insert_sort_detect();
    if(is_insert_sort == 0)
        merge_sort();
    return 0;
}