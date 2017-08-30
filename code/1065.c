#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int ncase;
	int k;
	long long a, b, c;
	int flag;

	scanf("%d", &ncase);
	for(k = 1; k <= ncase; ++k){
		scanf("%lld%lld%lld", &a, &b, &c);
		flag = a + b > c;
		if(a > 0 && b > 0 && a + b <= 0)
			flag = 1;
		if(a < 0 && b < 0 && a + b >= 0)
			flag = 0;
		printf("Case #%d: %s\n", k, flag ? "true" : "false");
	}


	return 0;
}