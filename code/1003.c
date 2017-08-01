#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ncity;
int nroad;
// int from;
int to;
#define MAX_CITY 505
const int INF = 0x3f3f3f3f;
int res_team[MAX_CITY];
int road[MAX_CITY][MAX_CITY];
int npath;
int max_team;
int lowest_cost;
int vis[MAX_CITY];

void dfs(int cur_city, int nteam, int cost)
{
	int i;
	nteam += res_team[cur_city];
	if(cur_city == to){
		if(cost < lowest_cost){
			npath = 1;
			max_team = nteam;
			lowest_cost = cost;
		}else if(cost == lowest_cost){
			npath++;
			if(max_team < nteam)
				max_team = nteam;
		}
		return;
	}
	for(i = 0; i < ncity; ++i){
		if(road[cur_city][i] != INF && !vis[i]){
			vis[i] = 1;
			dfs(i, nteam, cost + road[cur_city][i]);
			vis[i] = 0;
		}
	}
}

int main(void)
{
	int i;
	int from;

	memset(res_team, 0, sizeof(res_team));
	memset(road, 0x3f, sizeof(road));
	memset(vis, 0, sizeof(vis));
	scanf("%d%d%d%d", &ncity, &nroad, &from, &to);

	for(i = 0; i < ncity; ++i)
		scanf("%d", &res_team[i]);
	for(i = 0; i < nroad; ++i){
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		road[a][b] = road[b][a] = cost;
	}
	npath = 0;
	max_team = 0;
	vis[from] = 1;
	lowest_cost = INF;
	dfs(from, 0, 0);
	printf("%d %d", npath, max_team);

	return 0;
}