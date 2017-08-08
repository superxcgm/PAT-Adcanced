#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digits[10];

void get_digits(const char *num)
{
	while(*num){
		digits[*num - '0']++;
		num++;
	}
}
int check_digits(const char *num)
{
	int i;
	while(*num){
		digits[*num - '0']--;
		num++;
	}
	for(i = 0; i < 10; ++i)	
		if(digits[i] != 0)
			return 0;
	return 1;
}
void double_num(char *num)
{
	int len = strlen(num);
	int i;
	int tmp;
	int carry = 0;
	
	num[len + 1] = '\0';
	for(i = len - 1; i >= 0; --i){
		tmp = (num[i] - '0') * 2 + carry;
		carry = tmp / 10;
		tmp %= 10;
		num[i + 1] = tmp + '0';
	}
	num[0] = carry + '0';
}

int main(void)
{
	char num[BUFSIZ];
	char *num2;

	scanf("%s", num);
	memset(digits, 0, sizeof(digits));
	get_digits(num);
	double_num(num);
	num2 = num[0] == '0' ? num + 1: num;
	printf("%s\n", check_digits(num2) ? "Yes" : "No");
	printf("%s\n", num2);

	return 0;
}