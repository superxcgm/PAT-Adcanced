#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n_base_to_decimal(const char *str, int base)
{
	char *p;
	int pow = 1;
	int ans = 0;

	p = str + strlen(str) - 1;
	while(p >= str){
		ans += pow * (*p - '0');
		pow *= base;
		p--;
	}
	return ans;
}

char *str_reverse(char *str)
{
	char *p = str, *q, tmp;

	q = str + strlen(str) - 1;
	while(p < q){
		tmp = *p;
		*p = *q;
		*q = tmp;
		p++; q--;
	}
	return str;
}

char *decimal_to_n_base(int num, int base)
{
	int stack[30];
	int sp = 0;
	char *ans;
	int i;

	while(num)
	{
		stack[sp++] = num % base;
		num /= base;
	}
	ans = (char *)malloc(BUFSIZ);
	--sp;
	i = 0;
	while(sp >= 0)
		ans[i++] = stack[sp--] + '0';
	ans[i] = '\0';
	return ans;
}

int reverse(int num, int base)
{
	char * str = decimal_to_n_base(num, base);
	int ans; 
	// printf("decimal_to_n_base: %s\n", str);
	str = str_reverse(str);
	// printf("reverse: %s\n", str);
	ans = n_base_to_decimal(str, base);
	// printf("reverse: %d\n", ans);
	return ans;
}

int isprime(int x)
{
	int sqx = (int)sqrt(x);
	int i;

	if(x < 5)
		return x == 2 || x == 3;
	if(x % 2 == 0 || x % 3 == 0)
		return 0;
	for(i = 5; i <= sqx; i += 6)
		if(x % i == 0 || x % (i + 2) == 0)
			return 0;
	return 1;
}

int main(void)
{
	int num, base;

	while(~scanf("%d", &num)){
		if(num < 0) break;
		scanf("%d", &base);
		if(isprime(num) && isprime(reverse(num,
			base)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}