#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int x)
{
	int sqx = (int)sqrt(x);
	int i;

	if(x <= 3) return x >= 2;
	if(x % 2 == 0 || x % 3 == 0) return 0;
	for(i = 5; i <= sqx; i+= 6)
		if(x % i == 0 || x % (i + 2) == 0)
			return 0;
	return 1;
}

int main(void)
{
	int num, i, j;
	int cnt;
	int flag = 0;

	scanf("%d", &num);
	printf("%d=", num);
	if(num == 1){
		printf("1\n");
		return 0;
	}
	for(i = 2; i <= num; i++){
		if(!is_prime(i)) continue;
		cnt = 0;
		while(num % i == 0){
			++cnt;
			num /= i;
		}
		if(cnt){
			if(flag)
				putchar('*');
			flag = 1;
			printf("%d", i);	
			if(cnt > 1)
				printf("^%d", cnt);
		}
		
	}
	return 0;
}