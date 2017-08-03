#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_to_int(char x)
{
	if(x >= '0' && x <= '9')
		return x - '0';
	return x - 'a' + 10;
}
int get_min_radix(const char *str)
{
	int ans = 0;
	int tmp;
	while(*str){
		tmp = char_to_int(*str);
		if(tmp > ans)
			ans = tmp;
		++str;
	}
	return ans + 1;
}

long long convert_to_decimal(const char *str, long long base)
{
	long long ans = 0;

	while(*str){
		ans *= base;
		ans += char_to_int(*str);
		++str;
		if(ans < 0)
			return -1;
	}
	return ans;
}

int main(void)
{
	char sn1[13];
	char sn2[13];
	char buf[13];
	long long base;
	long long n1;
	int tag;
	long long l, r, mid;
	int flag = 0;

	scanf("%s%s%d%lld", sn1, sn2, &tag, &base);

	if(tag == 2){
		strcpy(buf, sn1);
		strcpy(sn1, sn2);
		strcpy(sn2, buf);
	}
	n1 = convert_to_decimal(sn1, base);
	l = get_min_radix(sn2);
	r = n1 + 1;
	while(l <= r){
		long long tmp;
		mid = (l + r) / 2;
		tmp = convert_to_decimal(sn2, mid);
		if(tmp == -1 || tmp > n1){
			r = mid - 1;
		}else if(tmp < n1){
			l = mid + 1;
		}else{
			flag = 1;
			break;
		}
	}
	if(flag)
		printf("%lld", mid);
	else
		printf("Impossible");
	return 0;
}