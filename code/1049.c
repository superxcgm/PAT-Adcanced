#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int x;
	int cur;
	int high;
	int pow = 1;
	int low = 0;
	int cnt = 0;
	
	scanf("%d", &x);

	while(x){
		cur = x % 10;
		high = x / 10;
		if(cur == 0)
			cnt += high * pow;
		else if(cur == 1)
			cnt += high * pow + (low + 1);
		else
			cnt += (high + 1) * pow;

		low += cur * pow;
		pow *= 10;
		x /= 10;
	}
	printf("%d\n", cnt);

	return 0;
}
/*
1.当某位为0时，该位出现1的次数仅由高位决定，等于高位乘以当前位的权
2.当某位为1时，该位出现1的次数不光由高位决定，还由低位决定，等于高位乘以当前位的权，
加上，低位数字，再加1
3.当某位大于1时，该位出现1的次数仅由高位决定，等于高位加一，然后乘以当前位的权
 */