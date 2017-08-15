#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nums[100003];
int cnt[10000];

int main(void)
{
	int nnum;
	int i, tmp;

	scanf("%d", &nnum);
	memset(cnt, 0, sizeof(cnt));
	for(i = 0; i < nnum; ++i){
		scanf("%d", &tmp);
		nums[i] = tmp;
		cnt[tmp]++;
	}
	for(i = 0; i < nnum; ++i){
		if(cnt[nums[i]] == 1){
			break;
		}
	}
	if(i == nnum)
		printf("None\n");
	else
		printf("%d\n", nums[i]);

	return 0;
}