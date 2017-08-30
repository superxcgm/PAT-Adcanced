#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int coin[105];
int rec[105];
int fin(int from, int need_to_pay, int deep)
{
	int i, j;
	if(need_to_pay == 0){
		printf("%d", rec[0]);
		for(i = 1; i < deep; ++i)
			printf(" %d", rec[i]);
		printf("\n");
		return -1;
	}
	for(i = from; i <= 100; ++i){
		if(coin[i] > 0 && i <= need_to_pay){
			--coin[i];
			rec[deep] = i;
			if(fin(i, need_to_pay - i, deep + 1) == -1)
				return -1;
			++coin[i];
		}
	}
}
int main(void)
{
	int nnum, need_to_pay;
	int i, j, k;
	int face_value;

	scanf("%d%d", &nnum, &need_to_pay);
	memset(coin, 0, sizeof(coin));
	for(i = 0; i < nnum; ++i){
		scanf("%d", &face_value);
		coin[face_value]++;
	}
	if(fin(1, need_to_pay, 0) != -1)
		printf("No Solution\n");
	return 0;
}