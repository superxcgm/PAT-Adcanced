#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ele{
	int exp;
	double coe;
} pol_a[12];
#define MAX 1004
double ans[3*MAX];

int main(void)
{
	int k1, k2;
	int i, j;
	int cnt = 0;

	memset(ans, 0, sizeof(ans));

	scanf("%d", &k1);
	for(i = 0; i < k1; ++i)
		scanf("%d %lf", &pol_a[i].exp, &pol_a[i].coe);
	
	scanf("%d", &k2);
	for(i = 0; i < k2; ++i){
		int exp;
		double coe;
		scanf("%d %lf", &exp, &coe);

		for(j = 0; j < k1; ++j)
			ans[exp + pol_a[j].exp] += coe * pol_a[j].coe;
	}
	for(i = 3 * MAX; i >= 0; --i)
		if(ans[i] != 0.0)
			cnt++;
	printf("%d", cnt);
	for(i = 3 * MAX; i >= 0; --i)
		if(ans[i] != 0.0)
			printf(" %d %.1lf", i, ans[i]);

	return 0;
}