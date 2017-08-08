#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> vt;				/* farest vertex */
vector<int> adj[10005];
set<int> ans;

int f[10005];
int max_deep;
int vis[10005];
int nnode;

int fin(int t)
{
	if(f[t] == -1) return t;
	return f[t] = fin(f[t]);
}
void dfs(int cur, int deep)
{

	if(deep > max_deep){
		max_deep = deep;
		vt.clear();
		vt.push_back(cur);
	}else if(deep == max_deep){
		vt.push_back(cur);
	}
	vis[cur] = 1;
	int len = adj[cur].size();
	for(int i = 1; i <= nnode; ++i){
		if(vis[i]) continue;
		int flag = 0;
		for(int j = 0; j < len; ++j){
			if(adj[cur][j] == i){
				flag = 1;
				break;
			}
		}
		if(!flag) continue;
		dfs(i, deep + 1);
	}
	// vis[cur] = 0;
}

void merge(int a, int b)
{
	int t1 = fin(a);
	int t2 = fin(b);

	if(t1 != t2)
		f[t1] = t2;
}

int main(void)
{
	// freopen("1021_1.in", "r", stdin);
	scanf("%d", &nnode);
	if(nnode == 1){
		printf("1");
		return 0;
	}
	memset(f, 0xff, sizeof(f));
	for(int i = 0; i < nnode; ++i){
		int from, to;

		scanf("%d%d", &from, &to);
		adj[from].push_back(to);
		adj[to].push_back(from);
		
		merge(from, to);
	}
	int cnt = 0;
	for(int i = 1; i <= nnode; ++i)
		if(fin(i) == i)
			++cnt;
	if(cnt > 1){
		printf("Error: %d components", cnt);
		return 0;
	}
	max_deep = -1;
	memset(vis, 0, sizeof(vis));
	dfs(1, 0);

	max_deep = -1;
	memset(vis, 0, sizeof(vis));
	int start = vt[0];
	int len = vt.size();
	for(int i = 0; i < len; ++i)
		ans.insert(vt[i]);
	vt.clear();
	dfs(start, 0);
	len = vt.size();
	for(int i = 0; i < len; ++i)
		ans.insert(vt[i]);
	for(set<int>::iterator it = ans.begin(); it != ans.end(); ++it)
		printf("%d\n", *it);

	return 0;
}