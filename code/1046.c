#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (((a) > (b)) ? (b) : (a))
int diss[100003];

int main(void)
{
	int ndis;
	int i, j, nquery;
	int tmp_dis;
	int from, to;
	int ans;

	// freopen("1046.in", "r", stdin);
	memset(diss, 0, sizeof(diss));
	scanf("%d", &ndis);
	for(i = 1; i <= ndis; ++i){
		scanf("%d", &tmp_dis);
		diss[i + 1] = diss[i] + tmp_dis;
	}
	scanf("%d", &nquery);
	for(i = 0; i < nquery; ++i){
		scanf("%d%d", &from, &to);
		if(from > to){
			int t = from;
			from = to;
			to = t;
		}
		ans = diss[to] - diss[from];
		ans = min(ans, diss[ndis + 1] - ans);
		printf("%d\n", ans);
	}
	return 0;
}