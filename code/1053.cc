#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > vt;

int weight[105];
vector<int> vt_adj[105];
int rec[105];
int target_weight;
bool cmp(const vector<int> &a, const vector<int> &b)
{
	int len = 0;
	int i;

	len = a.size();
	if(b.size() < len) len = b.size();

	for(i = 0; i < len; ++i){
		if(a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	/* 如果去掉这个return，会出现段错误 */
	return false;
}

void dfs(int cur, int deep, int cur_weight)
{
	int len;
	int i;
	vector<int> tmp_vt;

	cur_weight += weight[cur];
	if(cur_weight > target_weight) return;
	rec[deep] = weight[cur];
	len = vt_adj[cur].size();
	if(len == 0){
		if(cur_weight == target_weight){
			for(i = 0; i <= deep; ++i)
				tmp_vt.push_back(rec[i]);
			vt.push_back(tmp_vt);
		}
		return ;
	}
	for(i = 0; i < len; ++i)
		dfs(vt_adj[cur][i], deep + 1, cur_weight);
}
int main(void)
{
	int nnode, nnon_leaf;
	int i, j, k;
	int child;
	int tmp_node;
	int len;

	scanf("%d%d%d", &nnode, &nnon_leaf, &target_weight);
	memset(weight, 0, sizeof(weight));

	for(i = 0; i < nnode; ++i)
		scanf("%d", &weight[i]);
	for(i = 0; i < nnon_leaf; ++i){
		scanf("%d%d", &tmp_node, &k);
		for(j = 0; j < k; ++j){
			scanf("%d", &child);
			vt_adj[tmp_node].push_back(child);
		}
	}
	dfs(0, 0, 0);
	sort(vt.begin(), vt.end(), cmp);
	len = vt.size();
	for(i = 0; i < len; ++i){
		int tmp_len = vt[i].size();
		printf("%d", vt[i][0]);
		for(j = 1; j < tmp_len; ++j)
			printf(" %d", vt[i][j]);
		printf("\n");
	}
	return 0;
}