#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len;

int *decimal_to_base(int num, int base)
{
	int stack[BUFSIZ];
	int sp = 0, i;
	int *ans;

	while(num){
		stack[sp++] = num % base;
		num /= base;
	}
	ans = (int *)malloc((sp + 2) * sizeof(int));
	for(i = 0; i < sp; ++i)
		ans[i] = stack[sp - i - 1];
	len = sp;
	return ans;
}

int ispali(const int *str)
{
	const int *q = str + len - 1;
	const int *p = str;
	while(p < q){
		if(*p != *q) return 0;
		p++; q--;
	}
	return 1;
}

int main(void)
{
	int num, base;
	int *str, i;

	scanf("%d%d", &num, &base);

	str = decimal_to_base(num, base);
	printf("%s\n", ispali(str) ? "Yes" : "No");
	printf("%d", *str);

	for(i = 1; i < len; ++i)
		printf(" %d", str[i]);	
	

	return 0;
}