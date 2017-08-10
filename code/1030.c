#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x3f3f3f3f

int des_city, ncity;
int dis[505][505];
int cost[505][505];
int min_dis = INF;
int min_cost = INF;
int record[505];
int vis[505];
int min_path[505];
int min_deep;

void dfs(int cur, int tmp_dis, int tmp_cost, int deep)
{
	int i;
	if(tmp_dis > min_dis) return;
	record[deep] = cur;
	if(cur == des_city){
		min_dis = tmp_dis;
		if(tmp_cost < min_cost){
			min_cost = tmp_cost;
			for(i = 0; i <= deep; ++i)
				min_path[i] = record[i] ;
			min_deep = deep;
		}
		return ;
	}
	for(i = 0; i < ncity; ++i){
		if(vis[i] || (dis[cur][i] == INF) || (cost[cur][i] == INF))
			continue;
		vis[i] = 1;
		dfs(i, tmp_dis + dis[cur][i], tmp_cost + cost[cur][i],
			deep + 1);
		vis[i] = 0;
	}
}
int main(void)
{
	int nroad, start_city;
	int i;

	scanf("%d%d%d%d", &ncity, &nroad, &start_city, &des_city);
	memset(dis, 0x3f, sizeof(dis));
	memset(cost, 0x3f, sizeof(cost));
	for(i = 0; i < nroad; ++i){
		int from, to, tmp_dis, tmp_cost;
		scanf("%d%d%d%d", &from, &to, &tmp_dis, &tmp_cost);
		dis[from][to] = dis[to][from] = tmp_dis;
		cost[from][to] = cost[to][from] = tmp_cost;
	}
	memset(vis, 0, sizeof(vis));
	vis[start_city] = 1;
	dfs(start_city, 0, 0, 0);
	printf("%d", start_city);
	for(i = 1; i <= min_deep; ++i)
		printf(" %d", min_path[i]);
	printf(" %d", min_dis);
	printf(" %d", min_cost);
	return 0;
}