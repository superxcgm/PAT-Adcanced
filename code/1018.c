#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max_cap, nsttn, prblm_sttn;
int bike[505];
int road[505][505];
int vis[505];
int rec[505];
int min_path[505];
int min_cost;
int min_bike_sent;
int min_bike_back;

const int INF = 0x3f3f3f3f;

void record_min_path(int x)
{
	int i;

	for(i = 0; i <= x; ++i)
		min_path[i] = rec[i];
	min_path[x + 1] = -1;
}

void dfs(int cur, int cost, int deep, int bike_cur, int bike_sent)
{
	int i, j;

	rec[deep] = cur;
	if(cost > min_cost) return;
	
	if(cur == prblm_sttn){
		int update = 0;
		if(cost < min_cost){
			min_cost = cost;
			update = 1;
		}else{
			if(bike_sent < min_bike_sent || (bike_sent == min_bike_sent
				&& bike_cur < min_bike_back)){
				update = 1;
			}
		}
		
		if(update){
			min_bike_sent = bike_sent;
			min_bike_back = bike_cur;
			record_min_path(deep);
		}
		return ;
	}

	for(i = 1; i <= nsttn; ++i){
		if(!vis[i] && road[cur][i] != INF){
			int tmp_bike_cur, tmp_bike_sent;
			vis[i] = 1;
			tmp_bike_cur = bike_cur;
			tmp_bike_sent = bike_sent;
			if(bike_cur + bike[i] < max_cap / 2){
				tmp_bike_cur = 0;
				tmp_bike_sent += (max_cap / 2) - bike_cur - bike[i];
			}else{
				tmp_bike_cur = bike_cur + bike[i] - max_cap / 2;
			}
			dfs(i, cost + road[cur][i], deep + 1, tmp_bike_cur, tmp_bike_sent);
			vis[i] = 0;
		}
	}
}
int main(void)
{
	int nroad;
	int i;

	// freopen("1018.in", "r", stdin);
	memset(road, 0x3f, sizeof(road));
	memset(vis, 0, sizeof(vis));
	scanf("%d%d%d%d", &max_cap, &nsttn, &prblm_sttn, &nroad);

	for(i = 1; i <= nsttn; ++i)
		scanf("%d", &bike[i]);

	for(i = 0; i < nroad; ++i){
		int from, to, cost;

		scanf("%d%d%d", &from, &to, &cost);
		road[from][to] = road[to][from] = cost;
	}
	vis[0] = 1;
	min_cost = INF;
	min_bike_sent = INF;
	min_bike_back = INF;
	dfs(0, 0, 0, 0, 0);
	// printf("min_cost: %d\n", min_cost);
	printf("%d ", min_bike_sent);
	putchar('0');
	for(i = 1; min_path[i] != -1; ++i)
		printf("->%d", min_path[i]);
	printf(" %d", min_bike_back);
	return 0;
}