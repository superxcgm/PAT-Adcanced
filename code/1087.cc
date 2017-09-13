#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>

using namespace std;

const int INF = 0x3f3f3f3f;
map<string, int> mp_name2ID;
map<int, string> mp_ID2name;
int id_cnt = 0;
int ncity;
int happiness[205];
int road_cost[205][205];
int min_cost;
int nmin_cost;
int max_happiness;
int max_avg_happiness;
int path[205];
int rec[205];
int vis[205];
int des_city;
int name2ID(char *str)
{    
    if(mp_name2ID.find(str) == mp_name2ID.end()){
        mp_name2ID[str] = id_cnt;
        mp_ID2name[id_cnt++] = str;
        //printf("map %s to %d\n", str, id_cnt - 1);
        return id_cnt - 1;
    }
    return mp_name2ID[str];
}
const char *ID2name(int id)
{
    return mp_ID2name[id].c_str();
}
void dfs(int cur_city, int cost, int deep, int cur_happiness)
{
    int i;
    cur_happiness += happiness[cur_city];
    rec[deep] = cur_city;
    if(cost > min_cost)
        return;
    if(cur_city == des_city){
        int update_path = 0;
        if(cost == min_cost){
            nmin_cost++;
            if(cur_happiness > max_happiness){
                max_happiness = cur_happiness;
                max_avg_happiness = cur_happiness / deep;
                update_path = 1;
            }else if(cur_happiness == max_happiness && 
                     max_avg_happiness < cur_happiness / deep){
                max_avg_happiness = cur_happiness / deep;
                update_path = 1;
            }
        }else{
            min_cost = cost;
            nmin_cost = 1;
            max_happiness = cur_happiness;
            max_avg_happiness = cur_happiness / deep;
            update_path = 1;
        }
        if(update_path){
            //printf("update path:\n");
            for(i = 0; i <= deep; ++i){
                path[i] = rec[i];
                //printf("%s -> ", ID2name(path[i]));
            }
            //printf("\n");
        }
        path[deep + 1] = -1;
    }
    for(i = 0; i < ncity; ++i){
        if(!vis[i] && road_cost[cur_city][i] != INF){
            vis[i] = 1;
            dfs(i, cost + road_cost[cur_city][i], deep + 1, cur_happiness);
            vis[i] = 0;
        }
    }
}
int main()
{
    int nroad, city_start;
    char city_name[5];
    int city_a, city_b;
    int i, j;
    int tmp_happiness;
    int tmp_cost;
    
    //freopen("1087.txt", "r", stdin);
    //freopen("1087.out.txt", "w", stdout);
    
    memset(happiness, 0, sizeof(happiness));
    memset(road_cost, 0x3f, sizeof(road_cost));
    scanf("%d %d %s", &ncity, &nroad, city_name);
    city_start = name2ID(city_name);
    for(i = 1; i < ncity; ++i){
        scanf("%s %d", city_name, &tmp_happiness);
        happiness[name2ID(city_name)] = tmp_happiness;
    }
    for(i = 0; i < nroad; ++i){
        scanf("%s", city_name);
        city_a = name2ID(city_name);
        scanf("%s %d", city_name, &tmp_cost);
        city_b = name2ID(city_name);
        road_cost[city_a][city_b] = road_cost[city_b][city_a] = tmp_cost;
    }
    min_cost = INF;
    nmin_cost = 0;
    max_happiness = -INF;
    max_avg_happiness = -INF;
    memset(vis, 0, sizeof(vis));
    vis[city_start] = 1;
    des_city = name2ID("ROM");
    dfs(city_start, 0, 0, 0);
    printf("%d %d %d %d\n", nmin_cost, min_cost, max_happiness, max_avg_happiness);
    printf("%s", ID2name(city_start));
    for(i = 1; path[i] != -1; ++i)
        printf("->%s", ID2name(path[i]));
    return 0;
}