#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;
#define MAX_NODE 103
const int INF = 0x3f3f3f3f;

int nnode;
int nnone_left;

int edge[MAX_NODE][MAX_NODE];

struct node{
	int idx;
	int deep;
};

int is_leaf(int x)
{
	int i;
	for(i = 0; i < MAX_NODE; ++i)
		if(edge[x][i] == 1)
			return 0;
	return 1;
}
void bfs()
{
	int i;
	int cnt = 0;
	struct node tmp, cur;
	int deep = 0;
	queue<struct node> q;
	tmp.idx = 1;
	tmp.deep = 0;
	q.push(tmp);

	putchar('0');
	while(!q.empty()){
		cur = q.front();
		if(cur.deep != deep){
			printf(" %d", cnt);
			cnt = 0;
			deep = cur.deep;
		}
		q.pop();
		for(i = 0; i < MAX_NODE; ++i)
			if(edge[cur.idx][i] == 1){
				if(is_leaf(i))
					++cnt;
				else{
					tmp.idx = i;
					tmp.deep = cur.deep + 1;
					q.push(tmp);
				}
			}
	}
	printf(" %d", cnt);
}
int main(void)
{
	int i;

	// freopen("1004.in", "r", stdin);

	memset(edge, 0x3f, sizeof(edge));
	scanf("%d%d", &nnode, &nnone_left);

	for(i = 0; i < nnone_left; ++i){
		int node, num, child;
		scanf("%d %d", &node, &num);
		while(num--){
			scanf("%d", &child);
			edge[node][child] = 1;
		}
	}
	if(nnode == 1)
		putchar('1');
	else
		bfs();
	return 0;
}