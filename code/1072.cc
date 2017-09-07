#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int road[1013][1013];
int vis[1013];
int cost[1013];
int nhouse, nstation, nroad, serv_dis;
int dest;
const int INF = 0x3f3f3f3f;
int tmp_min;
int flag;
double tmp_avg;
int getid(char *str)
{
    int ans;
    int offset = 0;
    if(*str == 'G'){
        offset = nhouse;
        ++str;
    }
    sscanf(str, "%d", &ans);
    ans += offset;
    return ans;
}
void dijsktra(int start)
{
    int i, j;
    memset(vis, 0, sizeof(vis));
    vis[start] = 1;
    for(i = 1; i <= nhouse + nstation; ++i)
        cost[i] = road[start][i];
    for(i = 1; i < nhouse + nstation; ++i){
        int min_dis = INF;
        int k;
        for(j = 1; j <= nhouse + nstation; ++j){
            if(!vis[j] && cost[j] < min_dis){
                min_dis = cost[j];
                k = j;
            }
        }
        if(min_dis == INF) break;
        vis[k] = 1;
        for(j = 1; j <= nhouse + nstation; ++j)
            if(!vis[j] && road[k][j] + cost[k] < cost[j])
                cost[j] = road[k][j] + cost[k];
    }
    tmp_min = INF;
    flag = 0;
    tmp_avg = 0;
    for(i = 1; i <= nhouse; ++i){
        if(cost[i] > serv_dis){
            flag = 1;
            return;
        }
        if(cost[i] < tmp_min)
            tmp_min = cost[i];
        tmp_avg += cost[i];
    }   
    tmp_avg /= nhouse;
}
int main()
{    
    int i, j;
    int dis;
    int pos1, pos2;
    char s1[5], s2[5];
    
    //freopen("1072.txt", "r", stdin);
    //freopen("1072.out.txt", "w", stdout);
    scanf("%d%d%d%d", &nhouse, &nstation, &nroad, &serv_dis);
    memset(road, 0x3f, sizeof(road));
    for(i = 0; i < nroad; ++i){
        scanf("%s %s %d", s1, s2, &dis);
        pos1 = getid(s1);
        pos2 = getid(s2);
        road[pos1][pos2] = road[pos2][pos1] = dis;
    }
    int max_min_dis = -INF;
    double min_avg_dis = INF;
    int best = -1;
    for(i = 1; i <= nstation; ++i)
    {
        dijsktra(i + nhouse);
        if(flag) continue;
        if(tmp_min > max_min_dis){
            max_min_dis = tmp_min;
            min_avg_dis = tmp_avg;
            best = i;
        }else if(tmp_min == max_min_dis && tmp_avg < min_avg_dis){
            best = i;
            min_avg_dis = tmp_avg;
        }
    }
    if(best == -1)
        printf("No Solution\n");
    else
        printf("G%d\n%d.0 %.1lf\n", best, max_min_dis, min_avg_dis);
    return 0;
}