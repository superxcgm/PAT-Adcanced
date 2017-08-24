#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int ga, sa, ka;
	int gb, sb, kb;

	scanf("%d.%d.%d", &ga, &sa, &ka);
	scanf("%d.%d.%d", &gb, &sb, &kb);

	ka += kb;
	sa += sb;
	ga +=gb;
	if(ka >= 29){
		sa += ka / 29;
		ka %= 29;
	}
	if(sa >= 17){
		ga += sa / 17;
		sa %= 17;
	}
	printf("%d.%d.%d\n", ga, sa, ka);
	return 0;
}