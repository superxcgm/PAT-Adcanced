#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Road
{
	int from;
	int to;
} roads[1000003];

int f[1003];

int fin(int t)
{
	if(f[t] == -1) return t;
	return f[t] = fin(f[t]);
}

void bing(int a, int b)
{
	int t1 = fin(a);
	int t2 = fin(b);
	if(t1 != t2)
		f[t1] = t2;
}
int main(void)
{
	int ncity, nroad, ncity_cncrn;
	int i, city_cncrn, cnt;

	scanf("%d%d%d", &ncity, &nroad, &ncity_cncrn);

	for(i = 0; i < nroad; ++i)
		scanf("%d%d", &roads[i].from, &roads[i].to);

	while(ncity_cncrn--){
		scanf("%d", &city_cncrn);

		memset(f, 0xff, sizeof(f));
		cnt = 0;
		for(i = 0; i < nroad; ++i)
			if(roads[i].from != city_cncrn &&
				roads[i].to != city_cncrn)
				bing(roads[i].from, roads[i].to);
		for(i = 1; i <= ncity; ++i)
			if(i != city_cncrn && f[i] == -1)
				cnt++;
		printf("%d\n", cnt - 1);
	}


	return 0;
}