#include <stdio.h>

const int INF = 0x3f3f3f3f;
int main(void)
{
	int k;
	int i;
	int x;
	int max_sum, sum;
	int from;
	int max_from, max_to;
	int first_ele, last_ele;

	max_sum = -INF;

	scanf("%d", &k);
	sum = 0;
	for(i = 0; i < k; ++i){
		scanf("%d", &x);
		if(i == 0){
			from = x;
			first_ele = x;
		}
		if(i == k - 1)
			last_ele = x;
		if(from == -1)
			from = x;
		sum += x;
		if(sum > max_sum){
			max_from = from;
			max_sum = sum;
			max_to = x;
		}
		if(sum < 0){
			sum = 0;
			from = -1;
		}
	}
	if(max_sum < 0)
		printf("0 %d %d", first_ele, last_ele);
	else
		printf("%d %d %d", max_sum, max_from, max_to);
	
	return 0;
}